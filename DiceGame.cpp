#include <iostream>
#include <random>
#include <time.h>
using namespace std;

//--デバック出力-------------------
#ifdef DEBUG
#define DEBUG_LOG(...) cout <<"["<< __FILE__ <<"]"<< __func__ <<":"<< __LINE__ <<"  "<< __VA_ARGS__ << endl
#else
#define DEBUG_LOG(...)
#endif
//---------------------------------

int diceRolling(){
  static mt19937_64 mt64(time(NULL));
  uniform_int_distribution<uint64_t> get_rand_uint_int(1, 6);
  return (int)get_rand_uint_int(mt64);
}

int main(){
  //Greeting
  string name;
  cout << "What is your name?" << endl;
  cout << ">";
  cin >> name;
  cout << "Hello, " << name << "!" << endl;

  //Rolling dice
  cout << "Rolling dice..." << endl;
  int dice1 = diceRolling();
  int dice2 = diceRolling();
  cout << "Die 1: " << dice1 << endl;
  cout << "Die 2: " << dice2 << endl;
  cout << "Total value: " << dice1 + dice2 << endl;

  //Won/lost
  int winningScore = 7;
  string text;
  if(dice1+dice2 < winningScore){
    text = "lost!";
  }
  else{
    text = "won!";
  }
  cout << name << " " << text << endl;
  return 0;
}
