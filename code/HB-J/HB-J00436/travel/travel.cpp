#include<bits/stdc++.h>
#define ll long long
using namespace std;
string c1, c2, s1, s2;
void solve() {
    string s = "";
    string t1 = "";
    string t2 = "";
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) s = s + '1';
    else {
        s = s + '0';
    }
    t1 = t1 + s1[0] + s1[1];
    t2 = t2 + s2[0] + s2[1];
    if (c1 == c2 && t1 == t2) s = s + '1';
    else {
        s = s + '0';
    }
    if (c1 == c2 &&
        t1 == t2 &&
        ((s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C') || (s1[2] >= 'D' && s1[2] <= 'F' && s2[2] >= 'D' && s2[2] <= 'F'))) s = s + '1';
    else {
        s = s + '0';
    }
    int a = s1[2];
    int b = s2[2];
    if (c1 == c2 &&
        t1 == t2 &&
        ((s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C') || (s1[2] >= 'D' && s1[2] <= 'F' && s2[2] >= 'D' && s2[2] <= 'F')) &&
        abs(a - b) == 1) s = s + '1';
    else {
        s = s + '0';
    }
    cout << s << "\n";
}
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
