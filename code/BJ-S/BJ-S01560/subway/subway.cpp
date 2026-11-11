#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=5e5+10;
ll c,n,m,d,q,w[N],t[210][N],a[210][N],ans,vis[N],f[300],k[210],dis[300][300];
vector<ll> v[N];
ll Find(ll x){return x==f[x]?x:f[x]=Find(f[x]);}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    //freopen("subway.in","r",stdin);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(ll i=1;i<=n;i++){
        f[i]=i;
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            dis[i][j]=LLONG_MAX;
        }
    }
    for(ll i=1;i<=n;i++)dis[i][i]=0;
    for(ll i=1;i<=m;i++){
        cin>>w[i];
    }
    for(ll i=1;i<=n;i++){
        cin>>k[i];
        for(ll j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][a[i][j]];
            vis[a[i][j]]++;
            v[a[i][j]].push_back(i);
            f[a[i][j]]=i;
        }
    }
    for(ll i=1;i<=m;i++){
        if(vis[i]>1){
            for(ll x:v[i]){
                for(ll y:v[i]){
                    if(x!=y){
                        dis[x][y]=t[x][i]+t[y][i];
                    }
                }
            }
        }
    }
    for(ll p=1;p<=n;p++){
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][p]+dis[p][j]);
            }
        }
    }
    while(q--){
        //clear!!!!!!!!
        ans=0;
        ll x,y;cin>>x>>y;
        ll u=Find(x),v=Find(y);
        ans=w[x]+w[y]+dis[u][v]+t[u][x]+t[v][y];
        cout<<ans<<'\n';
    }
    /*
    while(q--){
        ll x;
        cin>>x;
        cout<<Find(x)<<'\n';
    }
    */
    return 0;
}