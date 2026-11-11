#include <bits/stdc++.h>
using namespace std;
#define int long long
string sa, sb, ta, tb;
signed main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> sa >> sb >> ta >> tb;
    if (sa == ta) cout << 1;
    else cout << 0;
    if (sa == ta && sb[0] == tb[0] && sb[1] == tb[1]) cout << 1;
    else cout << 0;
    if (sa == ta && sb[0] == tb[0] && sb[1] == tb[1]) {
        if ((sb[2] <= 'C' && tb[2] <= 'C') || (sb[2] >= 'D' && tb[2] >= 'D')) cout << 1;
        else cout << 0;
    } else cout << 0;
    if (sa == ta && sb[0] == tb[0] && sb[1] == tb[1]) {
        char cs = sb[2], ct = tb[2];
        if (cs > ct) swap(cs, ct);
        if (cs == 'A' && ct == 'B') cout << 1;
        else if (cs == 'B' && ct == 'C') cout << 1;
        else if (cs == 'D' && ct == 'F') cout << 1;
        else cout << 0;
    } else cout << 0 << "\n";
    return 0;
}