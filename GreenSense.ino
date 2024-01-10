#include "LedControl.h"

LedControl lc = LedControl(11,13,10,1); //DIN,CLK,CS,#DISP

#define demora 500
#define sensorPin A0 
int valorSensor = 0;

byte feliz[8] = {
B00000000, // filas necesarias por mostrar el digito cero			
B00100100,			
B00100100,			
B00000000,			
B01000010,			
B00100100,		
B00011000,			
B00000000		
};

byte serio[8] = {
  B00000000,				// filas necesarias por mostrar el digito uno
  B00100100,
  B00100100,
  B00000000,	
  B00000000,	
  B00111100,
  B00000000,
  B00000000
};

byte triste[8] = {
  B00000000, // filas necesarias por mostrar el digito cero			
  B00100100,			
  B00100100,			
  B00000000,			
  B00011000,			
  B00100100,			
  B00100100,			
  B00000000
};

byte morido[8] = {
  B00000000, // filas necesarias por mostrar el digito cero			
  B00100100,		
  B00100100,				
  B00000000,	
  B00000000,					
  B00101010,			
  B01010100,	
  B00000000
};

byte mudo[8] = {
  B00000000, // filas necesarias por mostrar el digito cero			
  B00100100,		
  B00100100,				
  B00000000,	
  B00000000,					
  B00000000,			
  B00000000,	
  B00000000
};

byte nada[8] = {
  B00000000,
  B01000010, // filas necesarias por mostrar el digito cero			
  B00100100,						
  B00010000,						
  B00101000,			
  B01000100,
  B00000000,	
  B00000000
};

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 4);
  lc.clearDisplay(0);
  Serial.begin(9600);
}

void loop() {

  int valorSensor = map(analogRead(sensorPin), 0, 1023, 100, 0);
  //se hace un mapeo de la lectura del sensor a porcentual
  Serial.print("Humedad de la tierra: ");
  Serial.print(valorSensor);
  Serial.println("%");
  delay(100);


  if (valorSensor >= 80 && valorSensor < 100) {
    mostrar_morido();//mareado
  } 
  else if (valorSensor >=65 && valorSensor < 80) {
    mostrar_mudo();
  }
  else if (valorSensor >= 55 && valorSensor < 65) {
    mostrar_feliz();
  }
  else if (valorSensor >= 45 && valorSensor <= 55) {
    mostrar_triste();
  }
  else if (valorSensor >= 5 && valorSensor < 45) {
    mostrar_serio();
  }
  else if (valorSensor >= 0 && valorSensor < 5) {
    mostrar_nada();
  }

  delay(demora);
}

// Funciones para mostrar los patrones en la matriz LED
void mostrar_feliz() {
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, feliz[i]);
  }
}

void mostrar_serio() {
  for (int i = 0; i < 8; i++) 		// bucle itera 8 veces por el array 
  {
    lc.setRow(0,i,serio[i]);		// establece fila con valor de array uno en misma posicion
  }
}

void mostrar_triste() {
  for (int i = 0; i < 8; i++)  		// bucle itera 8 veces por el array
  {
    lc.setRow(0,i,triste[i]);		// establece fila con valor de array dos en misma posicion
  }
}

void mostrar_morido() {
 for (int i = 0; i < 8; i++) 		// bucle itera 8 veces por el array 
  {
    lc.setRow(0,i,morido[i]);		// establece fila con valor de array tres en misma posicion
  }
}

void mostrar_mudo() {
 for (int i = 0; i < 8; i++) 		// bucle itera 8 veces por el array 
  {
    lc.setRow(0,i,mudo[i]);		// establece fila con valor de array tres en misma posicion
  }
}

void mostrar_nada() {
 for (int i = 0; i < 8; i++) 		// bucle itera 8 veces por el array 
  {
    lc.setRow(0,i,nada[i]);		// establece fila con valor de array tres en misma posicion
  }
}
