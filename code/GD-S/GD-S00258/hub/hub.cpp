#include <bits/stdc++.h>

const long long IMX = 1ll << 30;
const long long LMX = 1ll << 60;

#define fst first
#define snd second

using namespace std;
using ll = long long;
using ld = long double;
const int N = 1000005;
int Testid, T, n, k, ans;
int u[N], v[N], fa[N][25], lvl[N];
bool vis[N];
vector <int> G[N];
void dfs(int cur, int p) {
    lvl[cur] = lvl[p] + 1, fa[cur][0] = p;
    for (int i = 1; i <= 20; i++) fa[cur][i] = fa[fa[cur][i - 1]][i - 1];
    for (auto v : G[cur]) { if (v == p) continue; dfs(v, cur); }
}
int LCA(int u, int v) {
    if (lvl[u] < lvl[v]) swap(u, v);
    for (int i = 20; i >= 0; i--) { if ((lvl[u] - lvl[v] >> i) & 1) u = fa[u][i]; }
    if (u == v) return u;
    for (int i = 20; i >= 0; i--) { if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i]; }
    return fa[u][0];
}
int dis(int u, int v) { return lvl[u] + lvl[v] - 2 * lvl[LCA(u, v)]; }
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> Testid >> T;
    while (T--) {
        cin >> n >> k; ans = IMX;
        for (int i = 1; i <= n; i++) G[i].clear();
        for (int i = 1; i < n; i++) cin >> u[i] >> v[i], G[u[i]].push_back(v[i]), G[v[i]].push_back(u[i]);
        if (n <= 10) {
            dfs(1, 0);
            for (int i = 0; i < (1 << n); i++) {
                int cnt = 0, maxn = 0;
                if (__builtin_popcount(i) != k) continue;
                for (int j = 1; j <= n; j++) vis[j] = (i >> j - 1) & 1;
                for (int j = 1; j < n; j++) cnt += (vis[u[j]] and vis[v[j]]);
                if (cnt < k - 2) continue;
                for (int j = 1; j <= n; j++) {
                    int d = IMX;
                    for (int k = 1; k <= n; k++) { if (vis[k]) d = min(d, dis(j ,k)); }
                    maxn = max(maxn, d);
                }
                ans = min(ans, maxn);
            } 
        }
        else ans = n;
        cout << ans << '\n';
    }
    return 0;
}