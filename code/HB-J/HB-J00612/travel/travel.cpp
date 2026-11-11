#include <bits/stdc++.h>
#define ll long long

using namespace std;

string c1, c2, s1, s2;

bool getGuo(string s) {
    if (s[2] == 'A' || s[2] == 'B' || s[2] == 'C') return true;
    return false;
}

ll getP(string s) {
    if (s[2] == 'A') return 1;
    if (s[2] == 'B') return 2;
    if (s[2] == 'C') return 3;
    if (s[2] == 'D') return 5;
    if (s[2] == 'F') return 6;
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    cin >> c1 >> s1 >> c2 >> s2;

    ll inc = (c1 == c2);
    ll onl = (inc && (s1.substr(0, 2) == s2.substr(0, 2)));
    ll bs = (onl && getGuo(s1) == getGuo(s2));
    ll ls = (bs && (llabs(getP(s1) - getP(s2)) == 1));

    cout << inc << onl << bs << ls;

    return 0;
}
