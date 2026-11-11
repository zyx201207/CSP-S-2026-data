#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define db double
using namespace std;
const ll mx=505,mxx=5e5+5;
ll c,n,m,d,q,dis[mx][mx],w[mxx];
vector<pii>v[mxx];//v subwaystation
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++){
        ll sm;
        cin>>sm;
        for(int j=1;j<=sm;j++){
            ll x,y;
            cin>>x>>y;
            v[x].push_back({i,y});
        }
    }
    for(int i=1;i<=m;i++){
        ll t=v[i].size();
        for(int j=0;j<t;j++){
            for(int k=j+1;k<t;k++){
                int u=v[i][j].first,s=v[i][k].first;
                dis[u][s]=dis[s][u]=min(dis[u][s],v[i][j].second+v[i][k].second);
            }
        }
    }
    for(int i=1;i<=n;i++)dis[i][i]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
    while(q--){
        ll x,y,ans=1e18;
        cin>>x>>y;
        for(pii i:v[x]){
            for(pii j:v[y]){
                ans=min(ans,w[x]+w[y]+i.second+j.second+dis[i.first][j.first]);
            }
        }cout<<ans<<"\n";
    }
    return 0;
}