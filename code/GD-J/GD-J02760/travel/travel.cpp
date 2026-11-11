#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

bool next(char a, char b) {
    return a == 'A' && b == 'B' ||
    a == 'B' && b == 'C' ||
    a == 'D' && b == 'F';
}

bool beside(char a, char b) {
    return next(a, b) || a == 'A' && b == 'C';
}

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) {
        cout << "1";
        if (s1[0] == s2[0] && s1[1] == s2[1]) {
            cout << "1";
            if (beside(s1[2], s2[2]) || beside(s2[2], s1[2])) {
                cout << "1";
                if (next(s1[2], s2[2]) || next(s2[2], s1[2])) {
                    cout << "1";
                } else {
                    cout << "0";
                }
            } else {
                cout << "00";
            }
        } else {
            cout << "000";
        }
    } else {
        cout << "0000";
    }
    return 0;
}