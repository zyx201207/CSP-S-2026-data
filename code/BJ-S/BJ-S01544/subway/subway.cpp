#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],dis[505][505];
struct node{
    int u,w;
};
vector<node> adj[500005];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int C,n,m,D,q,k,u,v,w;
    cin>>C>>n>>m>>D>>q;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>u>>w;
            adj[u].push_back({i,w});
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<adj[i].size();j++){
            for(int k=0;k<adj[i].size();k++){
                int x1=adj[i][j].u,w1=adj[i][j].w;
                int x2=adj[i][k].u,w2=adj[i][k].w;
                dis[x1][x2]=min(dis[x1][x2],w1+w2);
                dis[x2][x1]=min(dis[x2][x1],w1+w2);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        cin>>u>>v;
        int ans=1e18;
        for(int i=0;i<adj[u].size();i++){
            for(int j=0;j<adj[v].size();j++){
                int x1=adj[u][i].u,x2=adj[v][j].u;
                int w1=adj[u][i].w,w2=adj[v][j].w;
                ans=min(ans,a[u]+a[v]+w1+w2+dis[x1][x2]);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
