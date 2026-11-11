#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N=5e5+5;
ll c,n,m,d,q;
ll w[N];
vector<pair<int,int> > jg[N];
vector<pair<int,int> > g[N];
ll dis[505][505];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;i++){
        cin>>w[i];
    }
    for (int i=1;i<=n;i++){
        ll k;
        cin>>k;
        for (int j=1;j<=k;j++){
            ll aa,tt;
            cin>>aa>>tt;
            jg[aa].push_back({i,tt});
            g[aa].push_back({i+m,tt});
            g[i+m].push_back({aa,tt});
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            dis[i][j]=1e18;
        }
        dis[i][i]=0;
    }
    for (int i=1;i<=n;i++){ // O(d^2*m)
        for (const auto &j:g[i+m]){
            ll v=j.first,w=j.second;
            for (const auto &k:g[v]){
                ll vv=k.first,ww=k.second;
                dis[i][vv-m]=min(dis[i][vv-m],w+ww);
            }
        }
    }
    for (int k=1;k<=n;k++){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    // for (int i=1;i<=n;i++){
    //     for (int j=1;j<=n;j++){
    //         cout<<dis[i][j]<<" \n"[j==n];
    //     }
    // }
    while(q--){
        ll x,y;
        cin>>x>>y;
        ll ans=1e18;
        for (const auto &i:jg[x]){
            for (const auto &j:jg[y]){
                ans=min(ans,w[x]+w[y]+i.second+j.second+dis[i.first][j.first]);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}