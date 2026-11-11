#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll x[2000005], deg[2000005], tmp[2000005], dp[2000005], cnt[2000005];
vector<int> g[2000005];
queue<int> q;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, T;
    cin >> c >> T;
    while (T--) {
        ll n, d;
        cin >> n >> d;
        for (int i = 1; i <= n; ++i) cin >> x[i];
        ll ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) g[j].clear(), deg[j] = 0;
            for (int j = i + 1; j <= n; ++j) {
                int t = j - 1;
                while (t >= i && x[j] - x[t] <= d) 
                    g[t].push_back(j), deg[j]++, t--;
                for (int k = 1; k <= n; ++k)
                    tmp[k] = deg[k], dp[k] = 1e9, cnt[k] = 0;
                cnt[i] = dp[i] = 1;
                q.push(i);
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    for (int v : g[u]) {
                        if (dp[u] + 1 < dp[v]) cnt[v] = cnt[u];
                        if (dp[u] + 1 == dp[v]) cnt[v] += cnt[u];
                        dp[v] = min(dp[v], dp[u] + 1);
                        if (--tmp[v] == 0) q.push(v);
                    }
                }
                if (cnt[j] == 2) ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}