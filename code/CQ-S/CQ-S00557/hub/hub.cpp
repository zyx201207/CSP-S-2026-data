#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, k;
vector<int>G[N];
inline void read(int& x) {
    x = 0;char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
}
inline int calc(int n, int k) { return (n - k + 1 >> 1) + 1; }
inline void special_A() {
    if (k == n) return puts("0"), void(0);
    if (k >= n >> 1) return puts("1"), void(0);
    printf("%d\n", max(calc(n >> 2, k >> 1), calc((n >> 1) + 1 >> 1, k + 1 >> 1)));
}
int f[N];
int D;
inline void chmn(int& x, int y) { x = x > y ? y : x; }
inline void chmx(int& x, int y) { x = x > y ? x : y; }
int dis[25][25];
inline void dfs(int u, int fa) {
    f[u] = 0;
    for (int v : G[u])
        if (v != fa) {
            dfs(v, u);
            chmx(D, f[u] + f[v] + 1);
            chmx(f[u], f[v] + 1);
        }
}
inline void k2() {
    D = 0;
    dfs(1, 0);
    if (k == 1) {
        printf("%d\n", D + 1 >> 1);
        return;
    }
    printf("%d\n", D + 2 >> 2);
}
int fa[N];
inline int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
inline void baoli() {
    for (int i = 1;i <= n;++i)
        for (int j = 1;j <= n;++j) dis[i][j] = n + 1;
    for (int i = 1;i <= n;++i) dis[i][i] = 0;
    for (int u = 1;u <= n;++u)
        for (int v : G[u]) dis[u][v] = 1;
    for (int k = 1;k <= n;++k)
        for (int i = 1;i <= n;++i)
            for (int j = 1;j <= n;++j) chmn(dis[i][j], dis[i][k] + dis[k][j]);
    int ans = n + 1;
    for (int msk = 0;msk < 1 << n;++msk)
        if (__builtin_popcount(msk) == k) {
            for (int u = 1;u <= n;++u) fa[u] = u;
            for (int u = 0;u < n;++u)
                if (msk >> u & 1)
                    for (int v : G[u + 1])
                        if (msk >> v - 1 & 1) fa[find(u + 1)] = find(v);
            set<int>s;
            for (int u = 0;u < n;++u)
                if (msk >> u & 1) s.insert(find(u + 1));
            if (s.size() > 2) continue;
            int mx = 0;
            for (int u = 1;u <= n;++u)
                if (!(msk >> u - 1 & 1)) {
                    int mn = n + 1;
                    for (int v = 1;v <= n;++v)
                        if (msk >> v - 1 & 1) chmn(mn, dis[u][v]);
                    chmx(mx, mn);
                }
            chmn(ans, mx);
        }
    printf("%d\n", ans);
}
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int testcase, T;read(testcase), read(T);
    while (T--) {
        for (int i = 1;i <= n;++i) G[i].clear();
        read(n), read(k);
        for (int i = 1;i < n;++i) {
            int u, v;read(u), read(v);
            G[u].push_back(v), G[v].push_back(u);
        }
        if (testcase == 13 || testcase == 14) special_A();
        else if (k <= 2) k2();
        else baoli();
    }
    return 0;
}