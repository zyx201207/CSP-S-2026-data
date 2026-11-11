#include <bits/stdc++.h>
#define int long long
using namespace std;
#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin)), *p1++)
#define deb puts("ok");
char buf[1 << 20], *p1, *p2;
inline int rd() {
    int x = 0, f = 1;
    char c = getchar();
    for (; !isdigit(c); c = gc()) if (c == '-') f = -1;
    for (; isdigit(c); c = gc()) x = x * 10 + c - '0';
    return x * f;
}
inline void wt(int x) {
    if (x < 0) putchar('-'), x = -x;
    if (x >= 10) wt(x / 10);
    putchar(x % 10 + '0');
}
const int MAXN = 1e6 + 5;
struct Edge {
    int to, nxt;
} e[MAXN << 1];
int c, t, n, k, tot, h[MAXN], fa[MAXN][20], lg, dep[MAXN], tt, s[MAXN];
bool vis[MAXN];
bool in[MAXN];
void add(int u, int v) {
    e[++tot].to = v, e[tot].nxt = h[u], h[u] = tot;
}
void dfs(int u, int f) {
    dep[u] = dep[f] + 1;
    fa[u][0] = f;
    for (int i = 1; i <= lg; i++) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for (int i = h[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (v != f) dfs(v, u);
    }
}
int lca(int u, int v) {
    if (u == v) return u;
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = lg; i >= 0; i--) {
        if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
    }
    if (u == v) return u;
    for (int i = lg; i >= 0; i--) {
        if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
    }
    return fa[u][0];
}
int dis(int u, int v) {
    return dep[u] + dep[v] - 2 * dep[lca(u ,v)];
}
void dfs2(int u, int f) {
    for (int i = h[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (v != f && !vis[v] && in[v]) vis[v] = 1, dfs(v, u);
    }
}
void solve() {
    memset(e, 0, sizeof e);
    memset(fa, 0, sizeof fa);
    tot = 0;
    n = rd(), k = rd();
    for (int i = 1; i < n; i++) {
        int u = rd(), v = rd();
        add(u, v), add(v, u);
    }
    lg = log(n) / log(2) + 1;
    dep[1] = 0;
    dfs(1, 1);
    int ans = 1e18;
    for (int msk = 0; msk < (1 << n); msk++) {
        tt = 0;
        fill(in + 1, in + 1 + n, 0);
        for (int i = 1; i <= n; i++) {
            if (msk >> (i - 1) & 1) s[++tt] = i, in[i] = 1;
        }
        if (tt != k) continue;
        for (int i = 1; i <= tt; i++) {
            vis[s[i]] = 0;
        }
        int cnt = 0;
        for (int i = 1; i <= tt; i++) {
            if (!vis[s[i]]) vis[s[i]] = 1, cnt++, dfs2(s[i], s[i]);
        }
        if (cnt > 2) continue;
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int d = 1e18;
            for (int j = 1; j <= tt; j++) {
                d = min(d, dis(i, s[j]));
            }
            res = max(res, d);
        }
        ans = min(ans, res);
    }
    wt(ans), putchar('\n');
}
signed main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
//    freopen("1.in", "r", stdin);
 //   freopen("1.out", "w", stdout);
    c = rd(), t = rd();
    while (t--) solve();
    return 0;
}

