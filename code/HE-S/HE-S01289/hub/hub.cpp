#include <bits/stdc++.h>

using namespace std;

// #define int long long

using i64 = long long;
using pii = pair<int, int>;

#define fi first 
#define se second
#define mkp make_pair

const int N = 2e6 + 20;
const int INF = 0x3f3f3f3f;

int c, t, n, k;

vector<int> G[N]; 

int cnt, dfn[N], top[N], siz[N], son[N], fa[N], vis[N], dep[N];

void dfs(int u, int f){
    siz[u] = 1; 
    fa[u] = f; 
    for(auto v : G[u]){
        if(v != f){
            dfs(v, u);
            siz[u] += siz[v];
            if(siz[v] > siz[son[u]]) son[u] = v; 
        }
    }
}
void dfs_(int u, int tp){
    top[u] = tp;
    dfn[u] = ++cnt; 
    dep[u] = dep[fa[u]] + 1;
    if(son[u]) dfs_(son[u], tp);
    for(auto v : G[u]){
        if(v == fa[u] || v == son[u]) continue;
        dfs_(v, v);
    }
}
int lca(int u, int v){
    if(u == v) return u;
    while(top[u] != top[v]){
        if(dep[top[u]] < dep[top[v]]) swap(u, v);
        u = fa[top[u]]; 
    }
    if(dep[u] > dep[v]) swap(u, v);
    return u;  
}
int dis(int x, int y){
    return dep[x] + dep[y] - 2 * dep[lca(x, y)]; 
}

int b[N], ans; 
int ff[N]; 
int find(int x){
    return x == ff[x] ? ff[x] : ff[x] = find(ff[x]);
}
void merge(int x, int y){
    if((x = find(x)) != (y = find(y))) 
        ff[x] = y; 
}

void check(){
    int cc = 0;
    for(int i = 1; i <= n; ++i)
        if(b[i]) cc++;
    if(cc != k) return;  
    for(int i = 1; i <= n; ++i) ff[i] = i;
    for(int i = 1; i <= n; ++i){
        if(b[i]){
            for(int j = i + 1; j <= n; ++j){
                if(b[j]){
                    if(dis(i, j) == 1) merge(i, j); 
                }   
            }
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; ++i){
        if(b[i])
            cnt += (i == find(i)); 
    }
    if(cnt != 2) return;
    int res = 0; 
    for(int i = 1; i <= n; ++i){
        int rrc = INF;
        for(int j = 1; j <= n; ++j){
            if(b[j]){
                rrc = min(rrc, dis(i, j)); 
            }
        } 
        res = max(res, rrc);
    }
    ans = min(ans, res); 
}

void dfs__(int x){
    if(x == n + 1){
        check();
        return;
    }
    b[x] = 1;
    dfs__(x + 1);
    b[x] = 0;
    dfs__(x + 1); 
}

void S(){
    cin >> n >> k;
    for(int i = 1, u, v; i < n; ++i){
        cin >> u >> v;
        G[u].push_back(v), G[v].push_back(u); 
    }
    dfs(1, 0); 
    dfs_(1, 1);
    ans = INF; 
    dfs__(1);
    cout << ans << '\n'; 
    for(int i = 1; i <= n; ++i){
        vis[i] = dfn[i] = siz[i] = top[i] = son[i] = fa[i] = 0; 
    } 
    cnt = 0; 
    for(int i = 1; i <= n; ++i) G[i].clear();
}

signed main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> c >> t;
    while(t--) S(); 
    return 0; 
}
