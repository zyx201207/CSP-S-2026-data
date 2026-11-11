#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MAXN = 5e5 + 5;
ll n, d;
ll a[MAXN];
ll nxt[MAXN];
bool chk(ll u, ll v) {
    vector <ll> vt;
    ll x = u;
    while(x < v)
        x = nxt[x], vt.push_back(min(x, v));
    ll cnt = 0;
    // cout << u << " " << v << " : " << vt[0] << " ";
    for(int i = 1; i < vt.size(); i++) {
        // cout << vt[i] << " ";
         
        if(a[vt[i]] - a[vt[i - 1] - 1] <= d && (a[vt[i]] - a[vt[i - 1] - 2] > d || vt[i - 1] - 2 < u))
            cnt++;
        if(a[vt[i]] - a[vt[i - 1] - 2] <= d && vt[i - 1] - 2 >= u)
            return 0;
    }
    // cout << cnt << " " << vt.size() << "\n";
    return cnt == 1;
}
void work() {
    cin >> n >> d;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        nxt[i] = min((ll)(lower_bound(a + 1, a + n + 1, a[i] + d) - a), n);
        // , cout << nxt[i] << " ";
    // cout << "\n";
    ll ans = 0;
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++) {
            ans += chk(i, j);
        }
    cout << ans << "\n";
}
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);
    ll c, t;
    cin >> c >> t;
    while(t--) {
        work();
    }
    return 0;
}