#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int N=500+6,M=5e5+6;
const ll inf=0x3f3f3f3f3f3f3f3fll;
int c,n,m,d,q;
ll w[M],dis[N][N];
vector<pair<ll,int>> e[M];

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (i!=j) dis[i][j]=inf;
    for (int i=1;i<=m;i++) cin>>w[i];
    for (int i=1;i<=n;i++) {
        int k; cin>>k;
        for (int j=1;j<=k;j++) {
            int u,t; cin>>u>>t;
            e[u].push_back({t,i});
        }
    }
    for (int i=1;i<=m;i++) {
        for (int j=0;j<e[i].size();j++) {
            ll t=e[i][j].first;
            int u=e[i][j].second;
            for (int k=0;k<e[i].size();k++) {
                ll tt=e[i][k].first;
                int v=e[i][k].second;
                if (u==v) continue;
                dis[u][v]=min(dis[u][v],t+tt);
            }
        }
    }
    for (int k=1;k<=n;k++) {
        for (int i=1;i<=n;i++) {
            if (i==k||dis[i][k]==inf) continue;
            for (int j=1;j<=n;j++) {
                if (j==k||j==i||dis[k][j]==inf) continue;
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while (q--) {
        int x,y; cin>>x>>y;
        ll ans=inf;
        for (int i=0;i<e[x].size();i++) {
            ll t=e[x][i].first;
            int u=e[x][i].second;
            for (int j=0;j<e[y].size();j++) {
                ll tt=e[y][j].first;
                int v=e[y][j].second;
                if (dis[u][v]==inf) continue;
                ans=min(ans,w[x]+t+dis[u][v]+tt+w[y]);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
