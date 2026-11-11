

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

bool CmpIUp (int a,int b) {
  return a > b;
}

int _maxi = 0;
int _numM = 0;

vector<int> _myList;

void ParseIn () {
  ifstream inFile("and.in");

  inFile >> _maxi;
  inFile >> _numM;

  int cur = 0;
  for (int i = 0; i < _maxi; i++) {
    inFile >> cur;
    _myList.push_back(cur);
  }

  inFile.close();
}

void Core () {
  sort(_myList.begin(),_myList.end(),CmpIUp);
}

void WriteOut() {
  ofstream outFile("and.out");

  outFile << _myList[_numM - 1] << endl; 
  
  outFile.close();
}

int main() {
  ParseIn();
  Core();
  WriteOut();
  return 0;
}
