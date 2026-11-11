#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define st first
#define nd second
using namespace std;
const int N=505;
const int M=5e5+5;
const int INF=0x3f3f3f3f3f3f3f3f;
int n,m,d,q;
int w[M];
vector<pii> e[M];
int dis[N][N];
int len[M];

void solve() {
    cin>>n>>m>>d>>q;
    for(int i=1;i<=m;++i) cin>>w[i];
    for(int i=1;i<=n;++i) {
        int k;
        cin>>k;
        for(int j=1;j<=k;++j) {
            int v,w;
            cin>>v>>w;
            e[v].push_back({i+m,w});
            len[v]++;
        }
    }
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=n;++j) {
            dis[i][j]=(i==j?0:INF);
        }
    }
    for(int k=1;k<=m;++k) {
        for(int i=0;i<len[k];++i) {
            for(int j=0;j<len[k];++j) if(i!=j) {
                int u=e[k][i].st-m;
                int v=e[k][j].st-m;
                int dis1=e[k][i].nd;
                int dis2=e[k][j].nd;
                dis[u][v]=min(dis[u][v],dis1+dis2);
                dis[v][u]=min(dis[v][u],dis1+dis2);
            }
        }
    }
    for(int k=1;k<=n;++k) {
        for(int i=1;i<=n;++i) {
            for(int j=1;j<=n;++j) {
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--) {
        int u,v;
        cin>>u>>v;
        int ans=INF;
        for(int i=0;i<len[u];++i) {
            for(int j=0;j<len[v];++j) {
                int tou=e[u][i].st-m;
                int tov=e[v][j].st-m;
                int dis1=e[u][i].nd;
                int dis2=e[v][j].nd;
                ans=min(ans,dis1+dis2+dis[tou][tov]);
            }
        }
        cout<<ans+w[u]+w[v]<<'\n';
    }
    return ;
}

signed main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c;
    cin>>c;
    solve();
    return 0;
}