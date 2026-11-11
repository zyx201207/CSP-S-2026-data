#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
const int N=505,M=5e5+5,NM=M+N;
int c,n,m,d,q,w[NM],dist[N][NM];
bool vis[NM];
vector<pii>g[M];
signed main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    rep(i,1,m) cin>>w[i];
    rep(i,1,n) {
        int k; cin>>k;
        rep(j,1,k) {
            int a,t; cin>>a>>t;
            g[i].push_back({n+a,t});
            g[n+a].push_back({i,t});
        }
    }
    rep(i,1,n) {
        rep(j,1,n+m) dist[i][j]=1e18,vis[j]=0;
        dist[i][i]=0;
        priority_queue<pii> q;
        q.push({0,i});
        while(!q.empty()) {
            int u=q.top().se; q.pop();
            if(vis[u]) continue;
            vis[u]=1;
            if(u<i) {
                rep(j,1,n+m) dist[i][j]=min(dist[i][j],dist[i][u]+dist[u][j]);
                continue;
            }
            for(pii x:g[u]) {
                int v=x.fi,w=x.se;
                if(dist[i][v]>dist[i][u]+w) {
                    dist[i][v]=dist[i][u]+w;
                    q.push({-dist[i][v],v});
                }
            }
        }
    }
    rep(t,1,q) {
        int x,y; cin>>x>>y;
        int ans=1e18;
        rep(i,1,n) ans=min(ans,dist[i][n+x]+dist[i][n+y]);
        cout<<ans+w[x]+w[y]<<'\n';
    }
    //cerr<<'\n'<<1.0*clock()/CLOCKS_PER_SEC<<'\n';
    return 0;
}
