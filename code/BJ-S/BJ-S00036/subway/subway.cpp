#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define d(x) cout<<"# "<<x<<" ";
ll c,n,m,d,q,w[500005],k[500005],sz[500005],dis[505][505];
struct acess{
    ll id,l;
};
vector<acess> g[500005];
int main(){
    ios::sync_with_stdio(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(ll i=1;i<=m;++i){
        cin>>w[i];
    }
    for(ll i=1;i<=n;++i){
        cin>>k[i];
        for(ll j=1;j<=k[i];++j){
            int id,l;
            cin>>id>>l;
            g[id].push_back({i,l});
        }
    }
    for(int i=1;i<=m;++i){
        sz[i]=g[i].size();
    }
    memset(dis,0x3f,sizeof(dis));
    for(ll i=1;i<=m;++i){
        for(ll x=0;x<sz[i];++x){
            for(ll y=x+1;y<sz[i];++y){
                ll x_=g[i][x].id,y_=g[i][y].id;
                dis[x_][y_]=dis[y_][x_]=min(dis[x_][y_],g[i][x].l+g[i][y].l);
            }
        }
    }
    for(ll k=1;k<=n;++k){
        dis[k][k]=0;
        for(ll i=1;i<=n;++i){
            for(ll j=1;j<=n;++j){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        ll x,y,ans=0x7f7f7f7f7f7f7f7f;
        cin>>x>>y;
        for(int i=0;i<sz[x];++i){
            for(int j=0;j<sz[y];++j){
                ans=min(ans,dis[g[x][i].id][g[y][j].id]+g[x][i].l+g[y][j].l);
            }
        }
        cout<<ans+w[x]+w[y]<<"\n";
    }
    return 0;
}
