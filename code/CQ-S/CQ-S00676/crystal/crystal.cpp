# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int N = 5e5 + 5;
int n, Ans;
ll m, p[N], pre[N];
signed main () {
    freopen ( "crystal.in", "r", stdin); freopen ( "crystal.out", "w", stdout);
    ios :: sync_with_stdio (0); cin.tie (0); cout.tie (0);
    cin >> n >> m;
    for ( int i = 1; i <= n; i ++) {
        cin >> p[i];
    }
    sort ( p + 1, p + 1 + n);
    for ( int i = 1; i <= n; i ++) {
        pre[i] = pre[i - 1] + p[i];
    }
    int l = 1;
    for ( int i = 1; i <= n; i ++) {
        while ( l < i && ( 1ll * p[i] * ( i - l + 1)) - ( pre[i] - pre[l - 1]) > m) {
            l ++;
        }
        Ans = max ( Ans, i - l + 1);
    }
    cout << Ans;
}
