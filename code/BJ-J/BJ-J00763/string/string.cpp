

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

struct NewStr {
  int _ai;
  char _ci;
};

int _maxi = 0;
long long _res = 0;

vector<NewStr> _myList;

string _myStr = "";

int Min (int one,int two) {
  if (one > two) return two;
  return one;
}

void ParseInCoreNew () {
  ifstream inFile("string.in");

  inFile >> _maxi;
  NewStr curNS;
  for (int i = 0; i < _maxi; i++) {
    inFile >> curNS._ai >> curNS._ci;
    _myList.push_back(curNS);

    //cout << curNS._ai << curNS._ci;
  }

  inFile.close();

  int minus = 0;
  NewStr maximim1;
  int curM = _maxi;
  for (int i = 0; i <= curM; i++) {
    if (curM - i - 1 < curM / 2) break;

    maximim1 = _myList[curM - i - 1];
    
    minus = Min(_myList[i]._ai, maximim1._ai);

    //cout << endl << minus << ':' << _myList[i]._ai << ' ' << maximim1._ai;
    
    _myList[i]._ai -= minus;
    _myList[curM - i - 1]._ai -= minus;
    
    if (_myList[i]._ci != maximim1._ci) _res += minus;
    
    if (_myList[i]._ai != 0){
      i--;
      curM--;
      continue;
    }
    curM++;
  }
}

void ParseInCoreTriv () {
  ifstream inFile("string.in");

  inFile >> _maxi;
  int ai;
  char ci;
  for (int i = 0; i < _maxi; i++) {
    inFile >> ai >> ci;
    for (int m = 0; m < ai; m++) {
      _myStr += ci;
    }
  }

  inFile.close();

  for (int i = 0; i < _myStr.size() / 2; i++) {
    if (_myStr[i] != _myStr[_myStr.size() - i - 1]) {
      _res++;
    }
  }
}

void WriteOut() {
  ofstream outFile("string.out");

  outFile << _res << endl; 
  
  outFile.close();
}

int main() {
  ParseInCoreNew();
  WriteOut();
  return 0;
}