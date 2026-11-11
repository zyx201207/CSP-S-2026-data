

#include <bits/stdc++.h>

using namespace std;

#define int long long

int _curNum;
int _type;
char _curChar;
string _myStr;
int _res;

void ParseIn () {

    ifstream inFile("string.in");

    inFile >> _type;

    for (int i = 0; i < _type; i++) {
        inFile >> _curNum >> _curChar;
        for (int m = 0; m < _curNum; m++) {
            _myStr += _curChar;
        }
    }

    inFile.close();
}

void CParseIn () {
    cin >> _type;

    for (int i = 0; i < _type; i++) {
        cin >> _curNum >> _curChar;
        for (int m = 0; m < _curNum; m++) {
            _myStr += _curChar;
        }
    }
}

void Core () {
    int fro = 0;
    int las = _myStr.length() - 1;

    for (int i = 0; i < _myStr.length() / 2; i++) {
        if (_myStr[fro] != _myStr[las]) {
            _res++;
        }
        fro++;
        las--;
    }
}

void WriteOut () {

    ofstream outFile("string.out");

    outFile << _res << endl;

    outFile.close();
}

void CWriteOut () {

    cout << _res << endl;

}

signed main () {

    ParseIn();
//  CParseIn();
    Core();
    WriteOut();
//  CWriteOut();

    return 0;
}
