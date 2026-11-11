#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int s, ss;

bool func(char c) {
    if (c == 'A' || c == 'B' || c == 'C') return true;
    return false;
}

bool lin(char x, char y) {
    if (x + 1 == y || y + 1 == x) return true;
    return false;
}

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c1, c2;
    string s1, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) cout << 1;
    else { cout << "0000"; return 0; }

    s = (s1[0] - '0') * 10 + (s1[1] - '0');
    ss = (s2[0] - '0') * 10 + (s2[1] - '0');
    if (s == ss) cout << 1;
    else { cout << "000"; return 0; }

    if (func(s1[2]) == func(s2[2])) cout << 1;
    else { cout << "00"; return 0; }

    if (lin(s1[2], s2[2])) cout << 1;
    else cout << 0;

    return 0;
}
