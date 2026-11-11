#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 1e6 + 10;
int c, t, n, k, rt, tot, f[maxn], mx[maxn], fa[maxn], dep[maxn], dfn[maxn], sz[maxn];
vector<int> id, e[maxn];
void dfsrt(int u, int pa) {
    sz[u] = 1; int msz = 0;
    for (int v : e[u]) if (v != pa) dfsrt(v, u), sz[u] += sz[v], msz = max(msz, sz[v]);
    if ((max(msz, n - sz[u]) << 1) <= n) rt = u;
}
void dfs(int u, int pa) {
    dep[u] = dep[pa] + 1; mx[u] = dep[u]; fa[u] = pa; dfn[u] = ++tot; sz[u] = 1;
    for (int v : e[u]) if (v != pa)
        dfs(v, u), sz[u] += sz[v], mx[u] = max(mx[u], mx[v]);
}
void dfs2(int u, int dis) {
    f[u] = 0;
    for (int v : e[u]) if (v != fa[u]) 
        dfs2(v, dis), f[u] += f[v];
    if (mx[u] - dep[u] >= dis) ++f[u];
}
inline bool in(int x, int y) {return dfn[x] >= dfn[y] && dfn[x] < dfn[y] + sz[y];}
bool check(int dis) {
    int u = 0, v = 0; dfs2(rt, dis);
    for (int i = 1; i <= n; i++) if (dep[i] > dep[u]) u = i;
    for (; dis - dep[u] < -1; u = fa[u]);
    if (u == rt) return f[rt] <= k;
    for (int i = 1; i <= n; i++) 
        if (!in(i, u) && dep[i] > dep[v]) v = i;
    int ans = k + 1; vector<int> cur = id, p;
    for (; u && dis - dep[u] >= -1 && !in(v, u); u = fa[u]) p.push_back(u);
    reverse(p.begin(), p.end());
    for (int u : p) {
        while (cur.size() && dep[cur.back()] > dis - dep[u] + 1) {
            while (cur.size() && (in(cur.back(), u) || in(cur.back(), v))) cur.pop_back();
            if (cur.size() && dep[cur.back()] > dis - dep[u]) v = fa[v]; 
        }
        ans = min(ans, f[u] + f[v]);
        bool F = false;
        for (int x : e[u]) if (x != fa[u] && !in(v, x) && mx[x] > dis - dep[u]) {F = true; break;}
        if (F) break;
    }
    return ans <= k;
}
int cur;
bool vis[maxn];
void dfs4(int u, int pa, int tot, int mask) {
    if (mask >> (u - 1) & 1) {cur = min(cur, tot); return;}
    for (int v : e[u]) if (v != pa) dfs4(v, u, tot + 1, mask);
}
void dfs5(int u, int mask) {
    if (!(mask >> (u - 1) & 1)) return;
    vis[u] = true;
    for (int v : e[u]) if (!vis[v]) dfs5(v, mask);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t; dep[0] = -1;
    while (t--) {
        cin >> n >> k; 
        tot = 0; id.clear();
        for (int i = 1; i <= n; i++) id.push_back(i), e[i].clear();
        for (int i = 1; i < n; i++) {
            int u, v; cin >> u >> v;
            e[u].push_back(v); e[v].push_back(u);
        } 
        if (n <= 10) {
            int ans = n + 1;
            for (int mask = 0; mask < 1 << n; mask++) {
                int sum = 0, sum2 = 0;
                for (int i = 0; i < n; i++) if (mask >> i & 1) ++sum;
                if (sum > k) continue; 
                for (int i = 1; i <= n; i++) vis[i] = false;
                for (int i = 1; i <= n; i++) if ((mask >> (i - 1) & 1) && !vis[i]) ++sum2, dfs5(i, mask);
                
                if (sum2 > 2) continue; int len = 0;
                for (int i = 1; i <= n; i++) cur = n + 1, dfs4(i, 0, 0, mask), len = max(len, cur);
                ans = min(ans, len);
            }
            cout << ans << '\n';
            continue;
        }
        dfsrt(1, 0); dfs(rt, 0);
        sort(id.begin(), id.end(), [](int x, int y){return dep[x] < dep[y];});
        int l = 0, r = mx[rt] - 1, res = mx[rt];
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(mid)) r = mid - 1, res = mid;
            else l = mid + 1;
        } cout << res << '\n';
    }
    return 0;
}