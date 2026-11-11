#include <bits/stdc++.h>
using namespace std;
int main () {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, c2;
    string s1, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    string r1 = s1.substr(0, 2), r2 = s2.substr(0, 2);
    char h1 = s1[2], h2 = s2[2];
    bool f = 0, f1 = 0;
    if (c1 == c2) {cout << 1; f = 1;}
    else cout << 0;
    if (f && r1 == r2) {cout << 1; f1 = 1;}
    else cout << 0;
    if (h1 > h2) swap(h1, h2);
    if (h1 == 'A' && h2 == 'B' || h1 == 'A' && h2 == 'C' || h1 == 'B' && h2 == 'C' || h1 == 'E' && h2 == 'F') cout << 1;
    else cout << 0;
    int d = abs(h1 - h2);
    if (f1 && d == 1) cout << 1;
    else cout << 0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
