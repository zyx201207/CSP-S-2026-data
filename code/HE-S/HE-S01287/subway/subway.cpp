#include<bits/stdc++.h>
#define int long long
#define PI pair<int,int>
#define fi first
#define se second
using namespace std;

const int N=505,M=5e5+5,inf=1e18;
PI st[M][25];
int cnt[M];
int dis[N][N];
int vis[N];
int val[N][N];
vector<int> g[N];
int w[M];
int c,n,m,d,q;
priority_queue<PI> pq;

void dij(int s) {
    dis[s][s]=0;
    memset(vis,0,sizeof(vis));
    pq.push({dis[s][s],s});
    while(pq.size()) {
        int u=pq.top().se;
        pq.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto v : g[u]) {
            if(dis[s][v]>dis[s][u]+val[u][v]) {
                dis[s][v]=dis[s][u]+val[u][v];
                pq.push({-dis[s][v],v});
            }
        }
    }
}

signed main() {
    freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) val[i][j]=dis[i][j]=inf;
    for(int i=1;i<=n;i++) {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++) {
            int a,t;
            cin>>a>>t;
            st[a][++cnt[a]]={i,t};
        }
    }
    for(int i=1;i<=m;i++) {
        for(int j=1;j<=cnt[i];j++) {
            for(int k=1;k<=cnt[i];k++) {
                if(j==k) continue;
                int u=st[i][j].fi,v=st[i][k].fi;
                int W=st[i][j].se+st[i][k].se;
                val[u][v]=min(val[u][v],W);
                val[v][u]=min(val[v][u],W);
            }
        }
    }    
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(val[i][j]==inf) continue;
            g[i].push_back(j);
        }
    }
    for(int i=1;i<=n;i++) dij(i);
    for(int i=1;i<=q;i++) {
        int x,y,ans=inf;
        cin>>x>>y;
        for(int j=1;j<=cnt[x];j++) {
            for(int k=1;k<=cnt[y];k++) {
                int u=st[x][j].fi,v=st[y][k].fi,W=st[x][j].se+st[y][k].se;
                ans=min(ans,dis[u][v]+W);
            }
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}