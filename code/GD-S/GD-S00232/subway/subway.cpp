#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
const int M=510;
const ll inf=1e18;
vector<pair<int,ll>> g[N];
int n,m,c,d,Q;
ll w[N],dis[M][M];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>Q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int u;
            ll w;
            cin>>u>>w;
            g[u].push_back({i,w});
        }
        for(int j=1;j<=n;j++){
            if(i!=j)dis[i][j]=inf;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<g[i].size();j++){
            for(int k=j+1;k<g[i].size();k++){
                int u=g[i][j].first,v=g[i][k].first;
                ll w=g[i][j].second+g[i][k].second;
                dis[u][v]=min(dis[u][v],w);
                dis[v][u]=min(dis[v][u],w);
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
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<dis[i][j]<<' ';
    //     }
    //     cout<<"\n";
    // }
    while(Q--){
        int u,v;
        ll ans=inf;
        cin>>u>>v;
        for(auto now1:g[u]){
            for(auto now2:g[v]){
                int a=now1.first,b=now2.first;
                ll c=now1.second,d=now2.second;
                ans=min(ans,dis[a][b]+w[u]+w[v]+c+d);
            }
        }
        cout<<ans<<"\n";
    }
}