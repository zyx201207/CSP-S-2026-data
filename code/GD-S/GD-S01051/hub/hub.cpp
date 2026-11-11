#include<iostream>
#include<cstring>
#include<vector>
#include<unordered_set>
using namespace std;

const int MAXN = int(1e6)+5;

vector<int> g[MAXN];
unordered_set <int>xz;
unordered_set <int>xz2;
bool vis[MAXN];
bool vis2[MAXN];
int dis[MAXN];

int n,k,ans = 0x3f3f3f3f;

void dfs2(int u,int lst){
    dis[u] = min(dis[u],dis[lst]+1);
    if(u == lst)    dis[u] = 0;
    if(xz2.size() == xz.size()){
        return ;
    }
    if(xz.find(u) != xz.end()){
        xz2.insert(u);
    }
    for(auto ed:g[u]){
        if(dis[ed] > dis[u]+1)  dfs2(ed,u);
    }
}

int calc(){
    int flag = 0;
    for(auto ed:xz){
        // cout << ed << " ";
        int fg = 1;
        for(auto u:g[ed]){
            if(xz.find(u) != xz.end())  fg = 0;
        }
        flag += fg;
    }
    // cout << flag << " \n"[flag>2];
    if(flag>2)   return 0x3f3f3f3f;
    int _ans = 0x3f3f3f3f;
    for(int i = 1;i<=n;i++){
        if(xz.find(i) != xz.end())  continue;
        memset(vis2,0,sizeof(vis2));
        memset(dis,0x3f,sizeof(dis));
        xz2.clear();
        dis[i] = 0;
        dfs2(i,i);
        int maxn = -0x3f3f3f3f;
        for(auto e:xz){
            maxn = max(maxn,dis[e]);
        }
        _ans = min(_ans,maxn);
    }
    // cout << _ans << endl;
    return _ans;
}

void dfs(int step){
    if(step == k){
        ans = min(ans,calc());
    }
    for(int i = 1;i<=n;i++){
        if(vis[i])  continue;
        vis[i] = true;
        xz.insert(i);
        dfs(step+1);
        xz.erase(i);
        vis[i] = false;
    }
}

void solve(){
    ans = 0x3f3f3f3f;
    xz.clear();
    memset(vis,0,sizeof(vis));
    cin >> n >> k;
    for(int i = 1;i<=n;i++)  g[i].clear();
    for(int i = 1;i<n;i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0);
    cout << ans << endl;
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int C,T;
    cin >> C >> T;
    while(T--){
        solve();
    }
    return 0;
}