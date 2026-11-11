#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>
#define fi first
#define se second
int read() {
    int x = 0, f = 1;
    char c = getchar();
    while(!isdigit(c)) f = (c == '-' ? -1 : f), c = getchar();
    while(isdigit(c)) x = x * 10 + c - '0', c = getchar();
    return x * f;
}
const int N = 1e6 + 5;
int n, k, ans, dep[N], sz[N], mx[N], rt, vs[N], dp[105][105][2], g[105][2];
vector<int> G[N];
void dfs(int u, int fa) {
    dep[u] = dep[fa] + 1, sz[u] = 1;
    for(int v : G[u]) if(v != fa) dfs(v, u), sz[u] += sz[v];
}
void gtrt(int u, int fa, int al) {
    mx[u] = al - sz[u];
    for(int v : G[u]) if(v != fa) gtrt(v, u, al), mx[u] = max(mx[u], sz[v]);
    if(mx[u] < mx[rt]) rt = u;
}
int dfs2(int u, int fa) {
    dep[u] = dep[fa] + 1;
    int mx = dep[u];
    for(int v : G[u]) if(!vs[v] && v != fa) mx = max(mx, dfs2(v, u));
    return mx;
}
int gt1(int u, int fa) {
    vs[fa] = 1;
    dep[fa] = 0, dfs(u, fa);
    rt = 0, mx[0] = 1e18;
    gtrt(u, fa, sz[u]);
    int as = dfs2(rt, 0);
    vs[fa] = 0;
    return as;
}
void solve() {
    n = read(), k = read(), ans = 1e18;
    for(int i = 1; i <= n; i++) G[i].clear();
    for(int i = 1, u, v; i < n; i++) {
        u = read(), v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    if(k == 1) {
        ans = gt1(1, 0);
    } else if(k == 2) {
        for(int i = 1; i <= n; i++) {
            for(int j : G[i]) {
                int mx = max(gt1(i, j), gt1(j, i));
                ans = min(ans, mx);
            }
        }
    }
    cout << ans << "\n";
}
signed main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int ttt = read(), T = read();
    while(T--) solve();
    return 0;
}
