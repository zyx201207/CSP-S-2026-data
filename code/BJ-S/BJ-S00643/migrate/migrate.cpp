#include <bits/stdc++.h>
using namespace std;
namespace csps {
    typedef long long ll;
    const int MAXN = 2e6 + 5;
    int c, t, n, dp[MAXN];
    ll x[MAXN], d, dis[MAXN];
    vector<int> adj[MAXN];
    void bfs(int s) {
        memset(dis, 0x3f, sizeof(dis[0]) * (n + 5));
        memset(dp, 0, sizeof(dp[0]) * (n + 5));
        queue<int> q;
        q.push(s);
        dis[s] = 0, dp[s] = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (dis[v] == dis[0]) {
                    dis[v] = dis[u] + 1;
                    dp[v] = dp[u];
                    q.push(v);
                } else if (dis[v] == dis[u] + 1) {
                    dp[v] += dp[u];
                }
            }
        }
    }
    void solve() {
        cin >> n >> d;
        for (int i = 1; i <= n; i++) adj[i].clear();
        for (int i = 1; i <= n; i++) {
            cin >> x[i];
            for (int j = i - 1; j >= 1; j--) {
                if (x[i] - x[j] <= d) adj[j].push_back(i), adj[i].push_back(j);
                else break;
            }
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            bfs(i);
            for (int j = i + 1; j <= n; j++) {
                ans += (dp[j] == 2);
            }
        }
        cout << ans << "\n";
    }
    void main() {
        ios::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);
        cin >> c >> t;
        while (t--) {
            solve();
        }
    }
}
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    csps::main();
    return 0;
}