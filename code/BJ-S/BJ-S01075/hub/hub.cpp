#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5, INF = 1e9;
bool exist[105][105], vis[N];
struct Union{
    int f[N];
    inline void clear(int len){
        for(int i = 1; i <= len; i++) f[i] = i;
    }
    inline int find(int x){
        if(x == f[x]) return x;
        return f[x] = find(f[x]);
    }
    inline void merge(int x, int y){
        f[find(x)] = find(y);
    }
}uni;
int ans, n, k, now[N], dep[N], siz[N], mx_pos[N], f[N], top[N];
vector<int> edge[N];
void dfs1(int u, int fa){
    dep[u] = dep[fa] + 1, siz[u] = 1, f[u] = fa;
    //cout << "u=" << u << " dep:" << dep[u] << endl;
    for(int v : edge[u]){
        if(v == fa) continue;
        dfs1(v, u);
        siz[u] += siz[v];
        if(siz[mx_pos[u]] > siz[v]) mx_pos[u] = v;
    }
}
void dfs2(int u, int fa, int now){
    top[u] = now;
    if(mx_pos[u]) dfs2(mx_pos[u], u, now);
    for(int v : edge[u]){
        if(v == fa || v == mx_pos[u]) continue;
        dfs2(v, u, v);
    }
}
inline int lca(int u, int v){
    while(top[u] != top[v]) (dep[top[u]] > dep[top[v]] ? u = f[top[u]] : v = f[top[v]]);
    return (dep[u] < dep[v] ? u : v);
}
inline int dis(int x, int y){
    return dep[x] + dep[y] - (dep[lca(x, y)] << 1);
}
inline int check(){
    uni.clear(n);
    for(int i = 1; i <= k; i++) for(int j = 1; j <= k; j++) if(exist[now[i]][now[j]]) uni.merge(now[i], now[j]);
    int cnt = 0;
    for(int i = 1; i <= k; i++){
        if(uni.find(now[i]) == now[i]) cnt++;
    }
    if(cnt > 2) return INF;
    //cout << "point:" << endl;
    //for(int i = 1; i <= k; i++) cout << now[i] << " ";
    //cout << endl;
    int ans = 0;
    for(int j = 1; j <= n; j++){
        int tmp = INF;
        if(vis[j]) continue;
        for(int i = 1; i <= k; i++){
            //cout << "u=" << now[i] << " v=" << j << " dis=" << dis(now[i], j) << endl;
            tmp = min(tmp, dis(now[i], j));
        }
        ans = max(ans, tmp);
    }
    //cout << "ans=" << ans << endl;
    return ans;
}
void dfs(int pos, int cnt){
    if(cnt == k){
        ans = min(ans, check());
        return;
    }
    for(int i = pos + 1; i <= n; i++){
        now[cnt + 1] = i, vis[i] = 1;
        dfs(i, cnt + 1);
        now[cnt + 1] = 0, vis[i] = 0;
    }
}
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int c, _;
    cin >> c >> _;
    while(_--){
        ans = INF;
        cin >> n >> k;
        for(int i = 1; i <= n; i++) edge[i].clear(), vis[i] = now[i] = dep[i] = siz[i] = mx_pos[i] = f[i] = top[i] = 0;
        for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) exist[i][j] = 0;
        int u, v;
        for(int i = 1; i < n; i++) cin >> u >> v, edge[u].push_back(v), edge[v].push_back(u), exist[u][v] = exist[v][u] = 1;
        dfs1(1, 1);
        dfs2(1, 1, 1);
        dfs(0, 0);
        cout << ans << "\n";
    }
    return 0;
}