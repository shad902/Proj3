#include <dht.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

dht DHT;

#define DHT11_PIN 7

void setup(){
  lcd.begin(16, 2);
}

void loop(){
  int chk = DHT.read11(DHT11_PIN);
  lcd.setCursor(0,0); //text to start at beginning 
  lcd.print("Temp: "); 
  int tempC=DHT.temperature; //call on the DHT.temperature to get temp in celcius
  int tempF=(DHT.temperature*1.8)+32; //converts celcius to faren and sets as int
  lcd.print(tempC); //print the temperature in celcius
  lcd.print((char)223); //char223 for the degrees sign
  lcd.print("C");
  lcd.print("/");
  lcd.print(tempF);
  lcd.print((char)223);
  lcd.print("F");
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);
  lcd.print("%");
  delay(1500);
}
