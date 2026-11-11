#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
const ll M=5e5,N=500;
ll w[M+5];
vector<pair<ll,ll>> v[M+5];
ll dis[N+5][N+5];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(ll i=1;i<=m;i++) cin>>w[i];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dis[i][j]=1e18;
        }
    }
    for(ll i=1,k;i<=n;i++){
        cin>>k;
        dis[i][i]=0;
        for(ll a,t,j=1;j<=k;j++){
            cin>>a>>t;
            for(auto it:v[a]){
                dis[i][it.first]=it.second+t;
                dis[it.first][i]=it.second+t;
            }
            v[a].pb({i,t});
        }
    }
    for(ll k=1;k<=n;k++){
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        ll u,to;
        cin>>u>>to;
        ll ans=1e18;
        for(auto it1:v[u]){
            for(auto it2:v[to]){
                ans=min(ans,it1.second+it2.second+dis[it1.first][it2.first]);
            }
        }
        cout<<ans+w[u]+w[to]<<'\n';
    }
    return 0;
}
