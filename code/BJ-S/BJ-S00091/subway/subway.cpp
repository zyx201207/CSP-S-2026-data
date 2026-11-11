#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1005,N=505,D=25,inf=1e12;
int c,n,m,d,q;
int w[M],dis[M][M];
int a[N][D],t[N][D];
bool vis[M][M];
vector<pair<int,int> > g[M];
void dij(int s)
{
    priority_queue<pair<int,int> > q;
    q.push({0,s});
    while(q.size())
    {
        int u=q.top().second;
        q.pop();
        if(vis[s][u]) continue;
        vis[s][u]=1;
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i].first;
            int w=g[u][i].second;
            if(dis[s][v]>dis[s][u]+w)
            {
                dis[s][v]=dis[s][u]+w;
                dis[v][s]=dis[s][u]+w;
                q.push({-dis[s][v],v});
            }
        }
    }
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1,k;i<=n;i++)
    {
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>a[i][j]>>t[i][j];
            for(int l=1;l<j;l++)
            {
                g[a[i][l]].push_back({a[i][j],t[i][j]+t[i][l]});
                g[a[i][j]].push_back({a[i][l],t[i][j]+t[i][l]});
            }
        }
    }
    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++)
            dis[i][j]=inf;
    for(int i=1;i<=m;i++) dis[i][i]=0;
    for(int i=1;i<=m;i++) dij(i);
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        cout<<dis[x][y]+w[x]+w[y]<<endl;
    }
    return 0;
}
