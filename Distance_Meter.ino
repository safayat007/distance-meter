#define ECHOPIN 10 
#define TRIGPIN 11

#include <LiquidCrystal.h>

LiquidCrystal lcd(2,3,4,5,6,7);

 

void setup() {

lcd.begin(16,2);

lcd.print("Distance Meter");

lcd.setCursor(0,1);

lcd.print("Distance = ");

pinMode(ECHOPIN, INPUT);

pinMode(TRIGPIN, OUTPUT);

delay(100);

}

void loop() {

digitalWrite(TRIGPIN,LOW);

delayMicroseconds(2);

digitalWrite(TRIGPIN,HIGH);

delayMicroseconds(10);

digitalWrite(TRIGPIN,LOW);

int duration = pulseIn(ECHOPIN,HIGH);

int r = 3.4*duration/2;

int distance = r/100.00;

lcd.setCursor(11,1);

lcd.print(distance);

lcd.print(" cm ");

delay(100);

}
