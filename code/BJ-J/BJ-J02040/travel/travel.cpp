

#include <bits/stdc++.h>

using namespace std;

#define int long long

int _carNumA;
string _seatA;
int _carNumB;
string _seatB;
int _resA = 0;
int _resB = 0;
int _resC = 0;
int _resD = 0;

void ParseIn () {

    ifstream inFile("travel.in");

    inFile >> _carNumA >> _seatA >> _carNumB >> _seatB;

    inFile.close();
}

void CParseIn () {
    cin >> _carNumA >> _seatA >> _carNumB >> _seatB;
}

void Core () {
    if (_carNumA != _carNumB) {
        return;
    }
    _resA = 1;
    int lineA = (_seatA[0] - '0') * 10;
    lineA = _seatA[1] - '0';
    int lineB = (_seatB[0] - '0') * 10;
    lineB = _seatB[1] - '0';
    if (lineA != lineB) {
        return;
    }
    _resB = 1;
    if (_seatA[2] < 'D' && _seatB[2] > 'C' || _seatB[2] < 'D' && _seatA[2] > 'C' || _seatA[2] == 'D' && _seatB[2] == 'C' || _seatB[2] == 'D' && _seatA[2] == 'C') {
        return;
    }
    _resC = 1;
    if (abs((int)(_seatA[2] - _seatB[2])) != 1) {
        return;
    }
    _resD = 1;
}

void WriteOut () {

    ofstream outFile("travel.out");

    outFile << _resA << _resB << _resC << _resD << endl;

    outFile.close();
}

void CWriteOut () {

    cout << _resA << _resB << _resC << _resD << endl;

}

signed main () {

    ParseIn();
//  CParseIn();
    Core();
    WriteOut();
//  CWriteOut();

    return 0;
}
