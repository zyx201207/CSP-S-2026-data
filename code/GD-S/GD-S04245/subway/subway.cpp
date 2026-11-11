#include<bits/stdc++.h>
using namespace std;
#define fst first
#define scd second
#define rep(i,s,t) for(int i=s;i<=t;++i)
#define dep(i,s,t) for(int i=s;i>=t;--i)
#define endl '\n'
#define pb push_back
#define file(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

const int M=5e5+10,N=510;

ll a[M],dis[N][N];
vector<pll> g[M];
void __solve(){
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    rep(i,1,m) cin>>a[i];
    rep(i,1,n){
        int k;cin>>k;
        while(k--){
            int a,b;cin>>a>>b;
            g[a].pb({i,b});
        }
    }
    memset(dis,0x3f,sizeof(dis));
    rep(k,1,m){
        int n=g[k].size();
        rep(i,0,n-1) rep(j,0,n-1) if(i!=j){
            int u=g[k][i].fst,v=g[k][j].fst;
            dis[u][v]=min(dis[u][v],g[k][i].scd+g[k][j].scd);
        }
    }
    rep(k,1,n) rep(i,1,n) rep(j,1,n)
        dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    rep(i,1,n) dis[i][i]=0;
    // rep(i,1,n) rep(j,1,n) cerr<<dis[i][j]<<' ';
    // cerr<<endl;
    while(q--){
        int x,y;cin>>x>>y;
        int w1=g[x].size(),w2=g[y].size();
        ll ans=LLONG_MAX;
        rep(i,0,w1-1) rep(j,0,w2-1){
            ans=min(ans,g[x][i].scd+g[y][j].scd+a[x]+a[y]+dis[g[x][i].fst][g[y][j].fst]);
        }
        cout<<ans<<endl;
    }
}
int main(){
#ifndef DEBUG
    file(subway)
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--) __solve();
    return 0;
}