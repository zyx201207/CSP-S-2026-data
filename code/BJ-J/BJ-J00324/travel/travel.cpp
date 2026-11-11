#include <bits/stdc++.h>
using namespace std;
int cx(string n, string m) {
    if (n == m) return 1;
    return 0;
}
int pai(string n, string m) {
    string s1, s2;
    s1 = n[0] + n[1];
    s2 = m[0] + m[1];
    if (s1 == s2) return 1;
    return 0;
}
int gd(string n, string m) {
    char s1 = n[2], s2 = m[2];
    if (s1 <= 'C' && s2 <= 'C') return 1;
    if (s1 > 'C' && s2 > 'C') return 1;
    return 0;
}
int wz(string n, string m) {
    char s1 = n[2], s2 = m[2];
    if (s1 > s2) swap(s1, s2);
    if (s1 == 'C') return 0;
    if (s1 == 'D' && s2 == 'F') return 1;
    if (s2 == char(s1 + 1)) return 1;
    return 0;
}
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    cout << cx(c1, c2);
    cout << (cx(c1, c2) && pai(s1, s2));
    cout << (cx(c1, c2) && pai(s1, s2) && gd(s1, s2));
    cout << (cx(c1, c2) && pai(s1, s2) && wz(s1, s2));
    return 0;
}
