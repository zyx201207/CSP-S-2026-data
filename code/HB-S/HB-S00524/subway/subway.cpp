#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=510;
const int M=6e5+10;
const int Q=1e5+10;
const int INF=1e15+10;
int c,n,m,d,q;
int dist[2050][2050];
int tot;
int s[M];
pair<int,int>qqq[Q];
struct whm{
    int v,w;
};
vector<whm>e[M];

void floyd()
{
    for(int k=1;k<=tot;k++)
        for(int i=1;i<=tot;i++)
            for(int j=1;j<=tot;j++)
                dist[j][i]=dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
    return;
}

void solve()
{
    floyd();
    for(int i=1;i<=q;i++)
        cout<<dist[qqq[i].first][qqq[i].second]+s[qqq[i].first]+s[qqq[i].second]<<"\n";
    return;
}

signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    tot=n+m;
    memset(dist,INF,sizeof(dist));
    for(int i=1;i<=m;i++)cin>>s[i];
    for(int i=1;i<=n;i++)
    {
        int k;cin>>k;
        for(int j=1;j<=k;j++)
        {
            int v,w;
            cin>>v>>w;
            e[m+i].push_back({v,w});
            e[v].push_back({m+i,w});
            if(m+i<2000&&v<2000)dist[m+i][v]=dist[v][m+i]=w;
        }
    }
    for(int i=1;i<=q;i++)cin>>qqq[i].first>>qqq[i].second;
    solve();

    return 0;
}