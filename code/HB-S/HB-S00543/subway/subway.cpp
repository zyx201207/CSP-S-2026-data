#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505,M=5e5+5,INF=1e18;
int c,n,m,d,q;
int w[M],dis[N][N];
vector< pair<int,int> > h[M];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dis[i][j]=INF;
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int u,t;
            cin>>u>>t;
            for(int r=0;r<h[u].size();r++)
            {
                int v=h[u][r].first;
                int w=h[u][r].second;
                dis[i][v]=dis[v][i]=min(dis[i][v],t+w);
            }
            h[u].push_back({i,t});
        }
    }
    for(int i=1;i<=n;i++)
        dis[i][i]=0;
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        int cnt=w[x]+w[y];
        int minn=INF;
        for(int i=0;i<h[x].size();i++)
        {
            int u=h[x][i].first;
            int w1=h[x][i].second;
            for(int j=0;j<h[y].size();j++)
            {
                int v=h[y][j].first;
                int w2=h[y][j].second;
                minn=min(minn,dis[u][v]+w1+w2);
            }
        }
        cout<<cnt+minn<<'\n';
    }
}