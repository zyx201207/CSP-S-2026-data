#include<bits/stdc++.h>
#define int long long
#define For(i, n)for (int i = 1; i <= (n); ++i)
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define Rep(i, n) for (int i = (n); i >= 1; --i)
#define REP(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;

signed main() {
    freopen("travel.in", "r", stdin); freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);

    string c1, s1, c2, s2; cin >> c1 >> s1 >> c2 >> s2;
    if (c1 != c2) {cout << "0000\n"; return 0;}
    else {
        string d1 = s1.substr(0, 2), d2 = s2.substr(0, 2);
        if (d1 != d2) {cout << "1000\n"; return 0;}
        char u1 = s1[2], u2 = s2[2];
        if (u1 == 'F') u1--; 
        if (u2 == 'F') u2--;
        if (u1>='A'&&u1<='C' && u2 >= 'A'&&u2<='C' || u1>='D'&&u1<='E' && u2 >= 'D'&&u2<='E') {
            if (abs(u2 - u1) == 1) cout << "1111\n";
            else cout << "1110\n";
        }
        else cout << "1100\n";
    }
    return 0;
}
//9:09