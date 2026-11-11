#include<bits/stdc++.h>
using namespace std;
long long int n,m,q,ans,x,y,viss[500005][505],visss[500005][505],dp[500005],w[500005];
struct node{
    int v,w;
};

vector<node>vis[500005],adj[505];

void dfs(int u){
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i].v,w=adj[u][i].w;
        if(dp[v]>dp[u]+w+visss[y][v]&&viss[y][v]){
            dp[v]=dp[u]+w+visss[y][v];
            dfs(v);
        }else if(dp[v]>dp[u]+w){
            dp[v]=dp[u]+w;
            dfs(v);
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>m>>n>>m>>q>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1,k;i<=n;i++){
        cin>>k;
        for(int j=1,a,t;j<=k;j++){
            cin>>a>>t;
            viss[a][i]=1;
            vis[a].push_back({i,t});
            visss[a][i]=t;
        }
    }
    for(int u=1;u<=n;u++)
    for(int i=0;i<vis[u].size();i++){
        int v1=vis[u][i].v,w1=vis[u][i].w;
        for(int j=i+1;j<vis[u].size();j++){
            int v2=vis[u][j].v,w2=vis[u][j].w;
            adj[i].push_back({j,w1+w2});
            adj[j].push_back({i,w1+w2});
        }
    }
    while(q--){
        cin>>x>>y;
        ans=0;
        for(int i=0;i<vis[x].size();i++){
            dfs(vis[x][i].v);
            dp[x]=0;
            ans=min(ans,w[x]+w[y]+dp[y]);
            for(int i=1;i<=m;i++)dp[i]=INT_MAX;
        }

        cout<<dp[y]<<"\n";
    }
    return 0;
}
