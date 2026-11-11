#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int rc, xc;
    string rs, xs;
    cin >> rc >> rs >> xc >> xs;
    if (rc != xc) return puts("0000"), 0;
    if (rs.substr(0, 2) != xs.substr(0, 2)) return puts("1000"), 0;
    char R = rs[2], X = xs[2];
    if (
        (R == 'A' || R == 'B' || R == 'C') && (X == 'A' || X == 'B' || X == 'C')
    ||  (R == 'D' || R == 'F') && (X == 'D' || X == 'F')
    ) 
        if (R == 'A' && X == 'C' || R == 'C' && X == 'A')
            return puts("1110"), 0;
        else return puts("1111"), 0;
    else
        return puts("1100"), 0;
    return 0;
}