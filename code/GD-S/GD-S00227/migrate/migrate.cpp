#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair <int, int>

const int N = 5005, inf = 1e18;
int n, k, a[N], d[N], f[N]; bool vis[N]; vector <int> g[N];
int dijkstra(int s) {
    queue <pii> q;
    for (int i = 1; i <= n; i++) d[i] = inf, vis[i] = f[i] = 0; q.push({d[s] = 0, s}); f[s] = 1;
    while (!q.empty()) {
        auto [z, u] = q.front(); q.pop(); if (vis[u]) continue; vis[u] = 1;
        for (int v : g[u]) {
            if (d[v] > d[u] + 1) q.push({d[v] = d[u] + 1, v}), f[v] = f[u];
            else if (d[v] == d[u] + 1) f[v] += f[u];
        }
    } int res = 0;
    for (int i = 1; i <= n; i++) res += f[i] == 2;
    return res;
}

signed main() {
    freopen("migrate.in", "r", stdin); freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int _, T; for (cin >> _ >> T; T--; ) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) cin >> a[i], g[i].clear();
        for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) if (abs(a[i] - a[j]) <= k) g[i].push_back(j);
        int ans = 0; for (int i = 1; i <= n; i++) ans += dijkstra(i); cout << ans << '\n';
    }
    return 0;
}