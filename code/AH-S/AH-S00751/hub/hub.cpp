#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
int c, T;
int n, k;
const int N=1e6+5;
int col[N]; int ans;
vector<int> g[N];
struct UFset{
    int fa[N];
    void init(){ for(int i = 1; i <= n; i++) fa[i] = i; }
    int find(int x){ return fa[x] == x ? x:fa[x] = find(fa[x]); }
    void join(int x, int y){ if(find(x) != find(y)) fa[find(y)] = find(x); }
    int _count(){
        int cnt = 0;
        for(int i = 1; i <= n; i++) cnt += (fa[i] == i && col[i]);
        return cnt;
    }
};
int dis[N]; bool vis[N];

int dist(int s){
    for(int i = 1; i <= n; i++) dis[i] = vis[i] = 0;
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    int mn = 1e9;
    while(q.size()){
        int u = q.front(); q.pop();
        vis[u] = true;
        for(int v:g[u]){
            if(!dis[v] && v!=s) {
                dis[v] = dis[u]+1;
                if(col[v]) mn = min(mn, dis[v]);
                q.push(v);
            }
        }
    }
    return mn;

}
int check(){
    UFset s; s.init();
    for(int i = 1; i <= n; i++)
        if(col[i]) for(int j:g[i]) if(col[j]) s.join(i,j);
    if(s._count() > 2) return -1;
    int tmp = 0;
    for(int i = 1; i <= n; i++)
    if(!col[i]) tmp = max(tmp, dist(i));
    return tmp;
}
void dfs(int x, int v){
    col[x] = v;
    if(x == n){
        int cnt = 0;
        for(int i = 1; i <= n; i++) cnt+=col[i];
        if(cnt != k) return ;
        int t = check();
        if(~t) ans = min(ans, t);
        return ;
    }
    dfs(x+1, 1);
    dfs(x+1, 0);
}
void solve(){
    cin >> n >> k;
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0,0);
    cout << ans << '\n';
    ans = 1e9;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> c >> T;
    while(T--) solve();
    return 0;
}
