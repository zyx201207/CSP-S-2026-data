#include<bits/stdc++.h>
#define ll long long
#define N 505050
#define qck ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
struct node{
    ll to;
    ll l;
};
vector<node> g[N];
ll c,n,m,d,q,s,kt;
ll cp[515][515];
ll w[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    qck;
    ll k,i,j;
    cin>>c>>n>>m>>d>>q;
    for(i=1;i<=m;++i) cin>>w[i];
    ll a,t;
    for(i=1,kt;i<=n;++i){
        cin>>kt;
        for(j=1;j<=kt;++j){
            cin>>a>>t;
            g[a+n].push_back({i,t});
            g[i].push_back({a+n,t});
        }
    }
    memset(cp,0x3f,sizeof(cp));
    for(i=1;i<=n;++i){
        for(auto trans:g[i]){
            for(auto jj:g[trans.to]){
                if(i==jj.to) cp[i][jj.to]=0;
                else cp[i][jj.to]=min(cp[i][jj.to],trans.l+jj.l);
            }
        }
    }
    for(k=1;k<=n;++k){
        for(i=1;i<=n;++i){
            for(j=i+1;j<=n;++j){
                cp[i][j]=min(cp[i][j],cp[i][k]+cp[k][j]);
            }
        }
    }
    ll u,v;
    for(i=1;i<=q;++i){
        cin>>u>>v;
        ll ans=1e18;
        for(auto jj:g[u+n]){
            for(auto kk:g[v+n]){
                ans=min(ans,min(cp[jj.to][kk.to],cp[kk.to][jj.to])+w[u]+w[v]+jj.l+kk.l);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}