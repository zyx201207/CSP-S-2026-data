#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> pii;
const int N=1e6+6,M=1e3+3,inf=2e18;
int testid,n,m,D,q,a[N],g[M][M],dis[M][M],qwq[N];
vector<pii>path[N],adj[N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>testid>>m>>n>>D>>q;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++){
        int sz;cin>>sz;
        for(int j=1;j<=sz;j++){
            int u,t;cin>>u>>t;adj[u].push_back({i,t});
            path[i].push_back({u,t});
        }
    }
    for(int i=1;i<=n;i++)qwq[i]=inf;
    for(int i=1;i<=m;i++)for(int j=1;j<=m;j++)
        g[i][j]=(i==j)?0:inf;
    for(int i=1;i<=m;i++){
        for(auto item:path[i])qwq[item.first]=item.second;
        for(int j=1;j<=m;j++){
            if(i==j)continue;
            for(auto item:path[j])g[i][j]=min(g[i][j],item.second+qwq[item.first]);
        }
        for(auto item:path[i])qwq[item.first]=inf;
    }
    for(int i=1;i<=m;i++)for(int j=1;j<=m;j++)dis[i][j]=g[i][j];
    for(int i=1;i<=m;i++)
        for(int k=1;k<=m;k++)
            for(int j=1;j<=m;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--){
        int x,y,ans=inf;cin>>x>>y;
        for(auto item:adj[x])
            for(auto jtem:adj[y])
                ans=min(ans,item.second+jtem.second+dis[item.first][jtem.first]);
        cout<<a[x]+a[y]+ans;if(q)cout<<'\n';
    }
    return 0;
}