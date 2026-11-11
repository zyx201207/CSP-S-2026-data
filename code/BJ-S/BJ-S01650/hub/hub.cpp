#include<bits/stdc++.h>
using namespace std;
int c;
int t;
int n;
int k;
struct node{
    int u;
    int v;
};
node e[105];
int b[105];
vector<int> adj[105];
bool vis[105];
int d[200005];
void bfs(int x){
    queue<int> q;
    q.push(x);
    d[x]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=1;
        for(int v:adj[u]){
            if(d[u]+1<d[v]){
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
}
void dfs1(int x){
    if(vis[x]){
        return;
    }
    vis[x]=1;
    for(int v:adj[x]){
        dfs1(v);
    }
}
int ans=1e9;
void dfs(int x){
    if(x>n){
        int cnt=0;
        for(int i=1;i<=n;i++){
            cnt+=b[i];
        }
        if(cnt!=k){
            return;
        }
        for(int i=1;i<=n;i++){
            adj[i].clear();
        }
        for(int i=1;i<n;i++){
            int u=e[i].u;
            int v=e[i].v;
            if(b[u] and b[v]){
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        cnt=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                cnt++;
                dfs1(i);
            }
        }
        if(cnt!=2){
            return;
        }
        int maxx=0;
        for(int i=1;i<=n;i++){
            adj[i].clear();
        }
        for(int i=1;i<n;i++){
            int u=e[i].u;
            int v=e[i].v;
            adj[u].push_back(v);
                adj[v].push_back(u);
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                d[j]=1e9;
            }
            bfs(i);
            int minn=1e9;
            for(int j=1;j<=n;j++){
                minn=min(minn,d[j]);
            }
            maxx=max(maxx,minn);
        }
        ans=min(ans,maxx);
        return;
    }
    b[x]=1;
    dfs(x+1);
    b[x]=0;
    dfs(x+1);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u;
            int v;
            cin>>u>>v;
            e[i]={u,v};
        }
        dfs(1);
        cout<<ans<<"\n";
    }
    return 0;
}
