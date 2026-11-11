#include<bits/stdc++.h>
using namespace std;
#define FILE(x) freopen(x".in","r",stdin); freopen(x".out","w",stdout);
#define ll long long 
const int N = 1e6 + 5, inf = 1e9;
vector<int>e[N];
int n, k, a[N];
int fa[N], dep[N];
int f[N], ans;
int top[N], sz[N], son[N];
inline void dfs2(int u, int dad){
    fa[u] = dad; dep[u] = dep[dad] + 1; sz[u] = 1; 
    for(int v : e[u]) {
        if(v == dad) continue;
        dfs2(v, u); sz[u] += sz[v];
        if(sz[v] > sz[son[u]]) son[u] = v;
    }
}
inline void dfs3(int u, int fir){
    top[u] = fir;
    if(son[u]) dfs3(son[u], fir);
    for(int v : e[u]){
        if(v == fa[u] || v == son[u]) continue;
        dfs3(v, v);
    }
}
inline int lca(int x, int y){
    while(top[x] != top[y]){
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        x = fa[top[x]];
    }
    return dep[x] < dep[y] ? x : y;
}
inline int dis(int x, int y){ return dep[x] + dep[y] - 2 * dep[lca(x, y)]; }
inline int find(int x){ return f[x] == x ? f[x] : f[x] = find(f[x]); }
inline void merge(int x, int y){
    x = find(x), y = find(y);
    if(x != y) f[x] = y;
}
vector<int>mp;
inline void chk(){
    mp.clear();
    for(int i=1;i<=n;i++){
        if(a[i]) mp.emplace_back(i);
        f[i] = i;
    }
    if(mp.size() != k) return; 
    for(int i=1;i<=n;i++) if(a[i]) for(int v : e[i]) if(a[v]) merge(i, v);
    int cnt = 0, mn = 0;
    for(int i=1;i<=n;i++) if(a[i] && f[i] == i) ++cnt;
    if(cnt > 2) return;
    for(int i=1;i<=n;i++) {
        if(a[i]) continue;
        int val = inf;
        for(int p : mp) val = min(val, dis(i, p));
        mn = max(mn, val);
    }
    ans = min(ans, mn);
}
inline void dfs(int u){
    if(u == n + 1) return chk(), void();
    a[u] = 1; dfs(u + 1);
    a[u] = 0; dfs(u + 1);
}
inline void solve(){
    cin >> n >> k; ans = 1e9;
    for(int i=1;i<=n;i++) vector<int>().swap(e[i]), fa[i] = dep[i] = son[i] = top[i] = 0;
    for(int i=1;i<n;i++) {
        int u, v; cin >> u >> v;
        e[u].emplace_back(v), e[v].emplace_back(u);
    }
    dfs2(1, 0); dfs3(1, 1);
    dfs(1); cout << ans << '\n';
}
inline void solvek(){
    cin >> n >> k; ans = 1e9;
    for(int i=1;i<=n;i++) vector<int>().swap(e[i]), fa[i] = dep[i] = son[i] = top[i] = 0;
    for(int i=1;i<n;i++) {
        int u, v; cin >> u >> v;
        e[u].emplace_back(v), e[v].emplace_back(u);
    }
    dfs2(1, 0); dfs3(1, 1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i == j) continue;
            int val = 0;
            for(int k=1;k<=n;k++) if(k != i && k != j) val = max(val, min(dis(i, k), dis(k, j)));
            ans = min(ans, val);
        }
    }
    cout << ans << '\n';
}
signed main(){
    FILE("hub");
    cin.tie(nullptr) -> sync_with_stdio(false);
    int cid, T; cin >> cid >> T;
    while(T--) {
        if(cid == 7) solvek();
        else solve();
    }
    return 0;
}