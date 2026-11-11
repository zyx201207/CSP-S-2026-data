#include<bits/stdc++.h>
#define ll long long
#define MAXN 500005
#define inf 0x3f3f3f3f
using namespace std;
struct ang{
    ll id,t;
};
vector<ang>c[MAXN];
ll n,m,ans,a[MAXN],C,d,q,f[MAXN],w[MAXN],dt[505][505];
void solve(){
    cin>>C>>n>>m>>d>>q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j)
                dt[i][j]=inf;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int j=1;j<=n;j++){
        ll k;
        cin>>k;
        for(int i=1;i<=k;i++){
            ll u,t1;
            cin>>u>>t1;
            c[u].push_back({j,t1});
        }
    }
    for(int i=1;i<=m;i++)
        for(auto j:c[i])
            for(auto k:c[i])
                if(j.id!=k.id){
                    dt[k.id][j.id]=dt[j.id][k.id]=min(dt[j.id][k.id],j.t+k.t);
                }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dt[i][j]=min(dt[i][j],dt[i][k]+dt[k][j]);
    while(q--){
        ll u,v;
        cin>>u>>v;
        ll cnt=inf;
        ans=w[u]+w[v];
        for(auto i:c[u])
            for(auto j:c[v])
                cnt=min(dt[i.id][j.id]+i.t+j.t,cnt);
        cout<<ans+cnt<<'\n';
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    ll t;
    t=1;
    while(t--)
        solve();
    return 0;
}
