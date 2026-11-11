

#include <iostream>
#include <fstream>

using namespace std;

int q1 = 0;
int q2 = 0;
int q3 = 0;
int q4 = 0;

string Rc = "error";
string Xc = "ERROR";
string Rs = "e";
string Xs = "e";
string Rl = "e";
string Xl = "e";
char Rn = 'e';
char Xn = 'e';

int Abs(int solo) {
  if (solo < 0) return -1 * solo;
  return solo;
}

void ParseIn () {
  ifstream inFile("travel.in");

  inFile >> Rc >> Rs;
  inFile >> Xc >> Xs;

  Rl = Rs[0] + Rs[1];
  Xl = Xs[0] + Xs[1];

  Rn = Rs[2];
  Xn = Xs[2];
  
  inFile.close();
}

void Core () {
  if (Rc == Xc) q1 = 1;
  if (q1 == 1 && Rl == Xl) q2 = 1;
  if (q1 == 1 && q2 == 1 && (Rn >= 'A' && Rn <= 'C') && (Xn >= 'A' && Xn <= 'C')) q3 = 1;
  if (q1 == 1 && q2 == 1 && (Rn >= 'D' && Rn <= 'E') && (Xn >= 'D' && Xn <= 'E')) q3 = 1;
  if (Abs(Rn - Xn) == 1 && q1 == 1 && q2 == 1 && q3 == 1) q4 = 1;
}

void WriteOut () {
  ofstream outFile("travel.out");

  outFile << q1 << q2 << q3 << q4 << endl;
  
  outFile.close();
}

int main() {
  ParseIn();
  Core();
  WriteOut();
  return 0;
}