#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,T;
int n,m;
int ans;
int vis[1000005];
int vis2[1000005];
int dis[1000005];
vector<int> G[1000005];
void dfs(int x){
    if(!vis[x]||vis2[x]) return ;
    vis2[x]=1;
    for(auto nx:G[x]) dfs(nx);
}
int bfs(){
    for(int i=1;i<=n;i++) dis[i]=-1;
    queue<int> q;
    for(int i=1;i<=n;i++) if(vis[i]){
        q.push(i);
        dis[i]=0;
    }
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto nx:G[x]){
            if(dis[nx]!=-1) continue;
            dis[nx]=dis[x]+1;
            q.push(nx);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,dis[i]);
    return ans;
}
bool check(){
    int cnt=0;
    for(int i=1;i<=n;i++){
        cnt+=vis[i];
        vis2[i]=0;
    }
    if(cnt!=m) return 0;
    for(int i=1;i<=n;i++){
        if(!vis[i]) continue;
        dfs(i);
        break;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]||vis2[i]) continue;
        dfs(i);
        break;
    }
    bool flag=1;
    for(int i=1;i<=n;i++) flag&=(vis2[i]||!vis[i]);
    return flag;
}
void dbs(int x){
    if(x==n+1){
        if(!check()) return;
        ans=min(ans,bfs());
        return ;
    }
    vis[x]=1;
    dbs(x+1);
    vis[x]=0;
    dbs(x+1);
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>m;
        ans=0x3f3f3f3f3f3f3f3f;
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dbs(1);
        cout<<ans<<"\n";
    }
}