#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 4e3 + 10;
vector<int> p[N];
int dis[N][N], bk[N], vis[N], bel[N], n, k, ans;
void dfs(int u, int f, int s) {
    dis[s][u] = dis[s][f] + 1;
    for (auto v : p[u]) if (v != f) dfs(v, u, s);
}
void d(int u, int f, int idx) {
    if (!vis[u]) return ; bel[u] = idx;
    for (auto v : p[u]) if (v != f) d(v, u, idx);
}
void df(int p) {
    if (p > k) {
        for (int i = 1; i <= n; i++) bel[i] = 0;
        int idx = 0;
        for (int i = 1; i <= k; i++) if (!bel[bk[i]]) d(bk[i], 0, ++idx);
        if (idx > 2) return ;
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int minn = 0x3f3f3f3f;
            for (int j = 1; j <= k; j++) minn = min(minn, dis[i][bk[j]]);
            res = max(res, minn);
        }
        ans = min(ans, res); return ;
    }
    for (int i = bk[p - 1] + 1; i <= n; i++) bk[p] = i, vis[i] = true, df(p + 1), vis[i] = false;
}
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while (t--) {
        cin >> n >> k; ans = 0x3f3f3f3f;
        for (int i = 1; i <= n; i++) p[i].clear();
        for (int i = 1, u, v; i < n; i++) cin >> u >> v, p[u].push_back(v), p[v].push_back(u);
        for (int i = 1; i <= n; i++) dis[i][0] = -1, dfs(i, 0, i);
        df(1); cout << ans << endl;
    }
    return 0;
}