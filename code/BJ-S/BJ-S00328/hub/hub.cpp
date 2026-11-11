#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, L = 20;
int n, k, dep[N], f[N][L], col[N], cnt, ans, d[N];
bool vis[N];
vector<int> g[N];
void build(int u, int fa){
    dep[u] = dep[fa] + 1;
    f[u][0] = fa;
    for(int i = 1; i < L; ++i)
        f[u][i] = f[f[u][i-1]][i-1];
    for(auto v : g[u])
        if(v != fa)
            build(v, u);
}
int lca(int u, int v){
    if(dep[u] < dep[v]) swap(u, v);
    for(int i = L-1; i >= 0; --i)
        if(dep[f[u][i]] >= dep[v])
            u = f[u][i];
    if(u == v) return u;
    for(int i = L-1; i >= 0; --i)
        if(f[u][i] != f[v][i]){
            u = f[u][i];
            v = f[v][i];
        }
    return f[u][0];
}
int dist(int u, int v){
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}
void flood(int x){
    col[x] = cnt;
    for(auto y : g[x])
        if(vis[y] && !col[y])
            flood(y);
}
int calc(){
    cnt = 0;
    for(int i = 1; i <= n; ++i)
        col[i] = 0;
    for(int i = 1; i <= n; ++i)
        if(vis[i] && !col[i]){
            if(cnt == 2) return 1e9;
            cnt++;
            flood(i);
        }
    int res = 0;
    for(int i = 1; i <= n; ++i){
        d[i] = 1e9;
        for(int j = 1; j <= n; ++j)
            if(vis[j])
                d[i] = min(d[i], dist(i, j));
        res = max(res, d[i]);
    }
    return res;
}
void dfs(int x){
    if(x > k){
        ans = min(ans, calc());
        return;
    }
    for(int i = 1; i <= n; ++i){
        if(!vis[i]){
            vis[i] = true;
            dfs(x + 1);
            vis[i] = false;
        }
    }
}
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, t;
    scanf("%d%d", &c, &t);
    while(t--){
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; ++i)
            g[i].clear();
        for(int i = 1; i < n; ++i){
            int u, v;
            scanf("%d%d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        build(1, 0);
        ans = 1e9;
        dfs(1);
        printf("%d\n", ans);
    }
    return 0;
}