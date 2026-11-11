#include <bits/stdc++.h>
using namespace std;
const int N = 25;
vector<int> e[N]; int fa[N][20], dep[N];
void dfs(int now, int _f) {
    fa[now][0] = _f; dep[now] = dep[_f] + 1;
    for(auto u : e[now])
        if(u != _f) dfs(u, now);
} int lca(int u, int v) {
    if(dep[u] > dep[v]) swap(u, v);
    for(int i = 19;i >= 0;i--)
        if(dep[fa[v][i]] >= dep[u]) v = fa[v][i];
    if(v == u) return u;
    for(int i = 19;i >= 0;i--)
        if(fa[v][i] != fa[u][i]) v = fa[v][i], u = fa[u][i];
    return fa[u][0];
} int dis(int u, int v) { return dep[u] + dep[v] - 2 * dep[lca(u, v)];} bool fl[N];
int ff[25];
int find(int x) { return (ff[x] == x ? x : ff[x] = find(ff[x])); }
void merge(int x, int y) { ff[find(x)] = find(y); }
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, t; cin >> c >> t; while(t--) {
        int n, k; cin >> n >> k;
        for(int i = 1, u, v;i < n;i++)
            cin >> u >> v,
            e[u].push_back(v),
            e[v].push_back(u);
        dfs(1, 0); for(int i = 1;i <= 19;i++)
            for(int j = 1;j <= n;j++)
                fa[j][i] = fa[fa[j][i-1]][i-1];
        int ans = 1e9;
        for(int i = 0;i < (1 << n);i++) {
            if(__builtin_popcount(i) != k) continue;
            for(int j = 1;j <= n;j++)
                if((i >> (j-1)) & 1) fl[j] = 1; else fl[j] = 0;
            for(int j = 1;j <= n;j++) ff[j] = j;
            for(int j = 1;j <= n;j++)
                for(auto x : e[j]) {
                    if(fl[j] && fl[x]) merge(j, x);
                }
            for(int j = 1;j <= n;j++) find(j);
            vector<int> pp;
            for(int j = 1;j <= n;j++) if(fl[j]) pp.push_back(ff[j]);
            sort(pp.begin(), pp.end()); int cc = 0;
            for(int i = 1;i < pp.size();i++) cc += (pp[i] != pp[i-1]);
            if(cc > 1) continue; int mx = 0;
            for(int i = 1;i <= n;i++) { int mn = 1e9;
                for(int j = 1;j <= n;j++)
                    if(fl[j]) mn = min(mn, dis(i, j));
                mx = max(mx, mn);
            } ans = min(ans, mx);
        } cout << ans << endl;
    }
    return 0;
}