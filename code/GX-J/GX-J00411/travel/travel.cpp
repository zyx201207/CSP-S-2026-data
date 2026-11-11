#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2) {
        cout << 1;
    }
    else {
        cout << "0000";
        return 0;
    }
    if(s1[0] == s2[0] && s1[1] == s2[1]) {
        cout << 1;
    }
    else {
        cout << "000";
        return 0;
    }
    char c = s1[2], d = s2[2];
    if(c == 'A' || c == 'B' || c == 'C') {
        if(d == 'A' || d == 'B' || d == 'C') {
            cout << 1;
        }
        else {
            cout << "00";
            return 0;
        }
    }
    else if(c == 'D' || c == 'F') {
        if(d == 'D' || d == 'F') {
            cout << 1;
        }
        else {
            cout << "00";
            return 0;
        }
    }
    if(c >= 'A' && c <= 'C') {
        if(abs(d - c) == 1) cout << 1;
        else cout << 0;
    }
    else {
        if(abs(d - c) == 2) cout << 1;
        else cout << 0;
    }
    return 0;
}
