#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define dle long double
#define fi first
#define sec second
#define rep(i,a,b) for(int i = (a);i<=(b);i++)
#define per(i,a,b) for(int i = (a);i>=(b);i--)
#define endl '\n'  
const int MAXN = 5e5+10,MAXM = 5e2+10;
struct node {int v,w;};
int c,n,m,d,q,W[MAXN],dp[MAXM][MAXM];
vector<node> g[MAXN],e[MAXN]; // g: 地铁线 e: 地铁站所连地铁线 
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    rep(i,1,m) cin>>W[i];
    rep(u,1,n) { int k;
        cin>>k;rep(j,1,k) { 
            int v,w;cin>>v>>w;
            e[v].push_back({u,w});}
    }rep(i,1,m) rep(j,0,e[i].size()-1) 
        rep(k,j+1,e[i].size()-1) {
            int u = e[i][j].v,v = e[i][k].v,
                w = e[i][j].w+e[i][k].w;
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }
    // rep(i,1,n) { cout<<i<<": ";for(auto j:g[i]) 
    //     cout<<'{'<<j.v<<','<<j.w<<'}'<<' ';cout<<endl;}
    memset(dp,0x3f,sizeof(dp));
    rep(u,1,n) for(auto v:g[u]) 
        dp[u][v.v] = min(dp[u][v.v],v.w),
        dp[v.v][u] = min(dp[v.v][u],v.w);
    rep(u,1,n) dp[u][u] = 0;
    rep(k,1,n) rep(i,1,n) rep(j,1,n) dp[i][j] = 
        min(dp[i][j],dp[i][k]+dp[k][j]);
    while(q--) { int u,v;cin>>u>>v;
        int ans = 1e18;for(auto s:e[u]) 
            for(auto t:e[v]) ans = min(
                ans,s.w+t.w+dp[s.v][t.v]);
        cout<<ans+W[u]+W[v]<<endl;
    }
    return 0;
}