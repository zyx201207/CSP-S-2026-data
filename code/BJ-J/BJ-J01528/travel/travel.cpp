#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool pd(char x, char y) {
    if (x == 'A') {
        return (y == 'B') || (y == 'C');
    }
    else if (x == 'B') {
        return (y == 'A') || (y == 'C');
    }
    else if (x == 'C') {
        return (y == 'A') || (y == 'B');
    }
    else if (x == 'D') {
        return y == 'F';
    }
    else if (x == 'F') {
        return y == 'D';
    }
}
bool pd2(char x, char y) {
    if (x == 'A') {
        return (y == 'B');
    }
    else if (x == 'B') {
        return (y == 'A') || (y == 'C');
    }
    else if (x == 'C') {
        return (y == 'B');
    }
    else if (x == 'D') {
        return y == 'F';
    }
    else if (x == 'F') {
        return y == 'D';
    }
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
            if (pd(s1[2], s2[2])) {
                cout << "1";
                if (pd2(s1[2], s2[2])) {
                    cout << "1\n";
                    return 0;
                }
                else {
                    cout << "0\n";
                    return 0;
                }
            }
            else {
                cout << "00\n";
                return 0;
            }
        }
        else {
            cout << "000\n";
            return 0;
        }
    }
    else {
        cout << "0000\n";
        return 0;
    }
    return 0;
}