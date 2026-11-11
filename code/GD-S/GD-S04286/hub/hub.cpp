#include <bits/stdc++.h>
#define int long long
#define rep(i, s, t) for (int i = s; i <= t; i++)
#define pre(i, s, t) for (int i = s; i >= t; i--)
#define pb push_back
using namespace std;
const int N = 1e6 + 2;
int cs, n, k, col[N], dist[N], st[N], mk[N];
vector<int> g[N];
void dfs(int u) {
    st[u] = 1;
    for (int v : g[u]) if (!st[v] && col[v]) dfs(v);
}
void dfs2(int u, int d) {
    dist[u] = min(dist[u], d), mk[u] = 1;
    for (int v : g[u]) if (!mk[v]) dfs2(v, d + 1);
}
inline void sol() {
    cin >> n >> k;
    rep(i, 1, n) g[i].clear();
    rep(i, 1, n - 1) {
        int u, v; cin >> u >> v;
        g[u].pb(v), g[v].pb(u);
    } int res = 2e9;
    if (cs > 3) return cout << k << '\n', void();
    rep(s, 0, (1 << n) - 1) if (__builtin_popcount(s) == k) {
        fill(dist, dist + n + 1, 2e9);
        fill(st + 1, st + n + 1, 0);
        fill(col + 1, col + n + 1, 0);
        rep(i, 1, n) if ((s >> (i - 1)) & 1) col[i] = 1;
        int cnt = 0, fg = 0;
        rep(i, 1, n) if (col[i] && !st[i]) {
            dfs(i);
            if (++cnt > 2) { fg = 1; break; }
        }
        if (fg) continue;
        rep(i, 1, n) if (col[i]) fill(mk + 1, mk + n + 1, 0), dfs2(i, 0);
        res = min(res, *max_element(dist + 1, dist + n + 1));
    }
    cout << res << '\n';
}
signed main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T; cin >> cs >> T;
    while (T--) sol();
    return 0;
}
/*
0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/