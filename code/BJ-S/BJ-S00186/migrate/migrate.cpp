#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e6 + 5;
ll c, t, n, d, dp[N], x[N], vis[N];
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t--) {
        ll ans = 0;
        cin >> n >> d;
        for (ll i = 1; i <= n; i++) cin >> x[i];
        for (ll i = 1; i <= n; i++) {
            ll s = x[i], j = i;
            memset(dp, 0, sizeof(dp));
            dp[i] = 0;
            while (j <= n) {
                if (x[++j] - s <= d) {
                    //j++;
                    dp[j] = 1;
                } else break;
            }
            while (j <= n) {
                memset(vis, 0, sizeof(vis));
                ll minN = INT_MAX;
                for (ll k = j - 1; k >= 1; k--) {
                    if (x[j] - x[k] <= d) {
                        vis[dp[k]]++;
                        minN = min(minN, dp[k]);
                    }
                    else break;
                }
                if (minN == INT_MAX) break;
                if (vis[minN] == 2) ans++;
                dp[j] = minN + 1;
                j++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
