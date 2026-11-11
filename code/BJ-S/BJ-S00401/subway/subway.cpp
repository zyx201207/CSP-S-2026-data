#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=1e18;
int c,n,m,d,q;
ll w[500005];
vector<pair<int,ll>> V[500005];//每个站转到的地图线路编号即换乘时间
ll dis[505][505];
void floyd(){
    for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
        dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(dis,0x3f,sizeof(dis));
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        dis[i][i]=0;
        int k;cin>>k;
        for(int j=1;j<=k;j++){
            int u;ll t;
            cin>>u>>t;
            V[u].push_back({i,t});
        }
    }
    for(int i=1;i<=m;i++){
        if(V[i].size()){
            int u=0,v=0;
            ll val=0;
            for(int x=0;x<(int)V[i].size();x++){
                for(int y=x+1;y<(int)V[i].size();y++){
                    val=V[i][x].second+V[i][y].second;
                    u=V[i][x].first,v=V[i][y].first;
                    dis[u][v]=min(dis[u][v],val);
                    dis[v][u]=min(dis[v][u],val);
                }
            }
        }
    }
    floyd();
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        ll ans=inf;
        for(auto u:V[x]) for(auto v:V[y]){
            ans=min(ans,dis[u.first][v.first]+u.second+v.second);
        }
        ans+=w[x]+w[y];
        cout<<ans<<"\n";
    }
    return 0;
}