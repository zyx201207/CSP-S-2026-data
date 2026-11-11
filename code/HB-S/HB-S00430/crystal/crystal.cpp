#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define el '\n'
void solve() {
    ll n, m, maxn = 0;
    cin >> n >> m;
    vector<ll> v(n + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> v[i];
    }
    sort (v.begin() + 1, v.end());
    for (ll i = n; i; i--) {
        ll idx = 0;
        ll t = m;
        while (t >= v[i] - v[i - idx] && idx <= i) {
            t -= v[i] - v[i - idx++];
        }
        cerr << i - idx << el;
        maxn = max(maxn, (ll)(idx));
    }
    cout << maxn;
}
signed main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
