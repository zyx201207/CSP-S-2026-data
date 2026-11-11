#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) cout << 1;
    else {
        cout << "0000";
        return 0;
    }
    if (s1.substr(0, 2) == s2.substr(0, 2)) cout << 1;
    else {
        cout << "000";
        return 0;
    }
    int b1 = (int)s1[2], b2 = (int)s2[2];
    if (((b1 <=67 && b2 <= 67) || (b1 > 67 && b2 > 67)) && (s1.substr(0, 2) == s2.substr(0, 2))) cout << 1;
    else {
        cout << "00";
        return 0;
    }
    if ((s1[2] == 'C' && s2[2] == 'D') || (s2[2] == 'C' && s1[2] == 'D')) cout <<0;
    else if ((abs(b1-b2) == 1) && s1.substr(0, 2) == s2.substr(0, 2)) cout << 1;
    else cout << 0;
    // cout
    // s.substr(1, 2);
    return 0;
}