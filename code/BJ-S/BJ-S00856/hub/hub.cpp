#include<iostream>
#include<vector>
using namespace std;
const int maxn = 1e6 + 5;
const int maxN = 10 + 5;
const int maxl = 10 + 5;
int C, T, n, k, dep[maxn], f[maxN][maxN], cnt, ok[maxN], mx, ans, fa[maxN], d[maxN][maxN], mn[maxn], id;
vector <int> e[maxn];
void dfs(int x, int pa){
    f[x][0] = pa, dep[x] = dep[pa] + 1;
    for(int i : e[x])
        if(i != pa) dfs(i, x);
}
int lca(int x, int y){
    if(dep[x] < dep[y]) swap(x, y);
    int diff = dep[x] - dep[y];
    for(int i = 0; i < maxl; ++i)
        if(diff >> i & 1) x = f[x][i];
    if(x == y) return x;
    for(int i = maxl - 1; i >= 0; --i)
        if(f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
    return f[x][0];
}
int dis(int x, int y){ return dep[x] + dep[y] - 2 * dep[lca(x, y)]; }
int find(int x){ return x == fa[x] ? x : fa[x] = find(fa[x]); }
void dfs2(int x, int pa){
    dep[x] = dep[pa] + 1;
    for(int i : e[x])
        if(i != pa) dfs2(i, x);
}
void solve(){
    cin >> n >> k;
    ans = n;
    for(int i = 1; i <= n; ++i) e[i].clear();
    for(int i = 1, u, v; i < n; ++i) cin >> u >> v, e[u].push_back(v), e[v].push_back(u);
    if(n <= 10){
    dfs(1, 0);
    for(int j = 1; j < maxl; ++j)
        for(int i = 1; i <= n; ++i) f[i][j] = f[f[i][j - 1]][j - 1];
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j) d[i][j] = dis(i, j);
    for(int i = 0; i < (1 << n); ++i){
        cnt = 0;
        for(int j = 0; j < n; ++j)
            if(i >> j & 1) ok[j + 1] = 1, cnt++, fa[j + 1] = j + 1;
            else ok[j + 1] = 0, mn[j + 1] = n;
        if(cnt != k) continue;
        for(int j = 1; j <= n; ++j)
            for(int k : e[j])
                if(ok[j] && ok[k]) fa[find(j)] = find(k);
        cnt = 0;
        for(int j = 1; j <= n; ++j)
            if(ok[j] && fa[j] == j) cnt++;
        if(cnt > 2) continue;
        // cout << "mask: " << i << '\n';
        mx = 0;
        for(int j = 1; j <= n; ++j)
            for(int k = 1; k <= n; ++k)
                if(ok[j] && !ok[k]) mn[k] = min(mn[k], d[j][k]);
        for(int j = 1; j <= n; ++j)
            if(!ok[j]) mx = max(mx, mn[j]);
        ans = min(ans, mx);
    }
    cout << ans << '\n';
    } else {
        dfs2(1, 0);
        mx = 0;
        for(int i = 1; i <= n; ++i)
            if(dep[i] > mx) mx = dep[i], id = i;
        dfs2(id, 0);
        mx = 0;
        for(int i = 1; i <= n; ++i)
            if(dep[i] > mx) mx = dep[i];
        for(int i = mx / 3 + 1; ; --i)
            if(3 * i + 1 < mx){
                cout << i + 1 << '\n';
                break;
            }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> C >> T;
    for(; T; --T) solve();
    return 0;
}
/*
0 1
5 2
1 2
2 3
3 4
4 5
*/