#include <bits/stdc++.h>
using namespace std;
const long long inf=0x3f3f3f3f3f3f3f3fll;
int C,n,m,D,q;
int w[500005];
struct Line
{
    int id,t;
    Line():id(),t(){}
    Line(int id_,int t_):id(id_),t(t_){}
};
vector<Line> e[500005];
long long d[505][505];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>C>>n>>m>>D>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        while(k--)
        {
            int a,t;
            cin>>a>>t;
            e[a].push_back(Line(i,t));
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            d[i][j]=inf;
    for(int i=1;i<=n;i++)
        d[i][i]=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<e[i].size();j++)
            for(int k=j+1;k<e[i].size();k++)
            {
                int u=e[i][j].id,v=e[i][k].id;
                long long w=e[i][j].t+e[i][k].t;
                d[u][v]=min(d[u][v],w);
                d[v][u]=min(d[v][u],w);
            }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        long long ans=inf;
        for(int i=0;i<e[x].size();i++)
            for(int j=0;j<e[y].size();j++)
                ans=min(ans,e[x][i].t+e[y][j].t+d[e[x][i].id][e[y][j].id]);
        cout<<ans+w[x]+w[y]<<"\n";
    }
}
