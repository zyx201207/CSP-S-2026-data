#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5 + 5;
ll n, m, a[N], sum[N], sum2[N];
bool check() {
    for (ll i = 1; i <= n; i++) {
        double num = double(a[i]);
        num += 1;
        if (sqrt(num) != double((a[i] + 1) * (a[i] + 1))) return 0;
    }
    return 1;
}
ll box[N], ans = -1;
bool vis[N];
void Dfs(ll x) {
    if (x - 1 == m) {
        ll res = box[1];
        for (ll i = 2; i <= m; i++) res = res & box[i];
        ans = max(ans, res);
        return ;
    }
    for (ll i = 1; i <= n; i++) {
        if (!vis[a[i]]) {
            vis[a[i]] = 1;
            box[x] = a[i];
            Dfs(x + 1);
            vis[a[i]] = 0;
        }
    }
}
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (ll i = 1; i <= n; i++) cin >> a[i];
    if (m == 1) {
        sort (a + 1, a + n + 1);
        cout << a[1];
    } else if (m == n) {
        ll sum = a[1];
        for (ll i = 2; i <= n; i++) sum = sum & a[i];
        cout << sum;
    } else if (m == 2) {
        ll ans = -1;
        for (ll i = 1; i <= n - 1; i++) {
            for (ll j = i + 1; j <= n; j++) {
                ll num = a[i] & a[j];
                ans = max(num, ans);
            }
        }
        cout << ans;
    } else if (check()) {
        sort (a + 1, a + n + 1);
        cout << a[m];
    } else if (m == n - 1) {
        sum[1] = a[1];
        sum2[n] = a[n];
        for (ll i = 1; i <= n; i++) sum[i] = sum[i - 1] & a[i];
        for (ll i = n - 1; i >= 1; i--) sum2[i] = sum[i + 1] & a[i];
        ll ans = -1;
        for (ll i = 1; i <= n; i++) {
            ll res = -1;
            if (i == 1) res = sum2[2];
            else if (i == n) res = sum[n - 1];
            else {
                res = sum[i - 1];
                res = res & sum2[i + 1];
            }
            ans = max(ans, res);
        }
        cout << ans;
    } else {
        Dfs(1);
        cout << ans;
    }
    return 0;
}
