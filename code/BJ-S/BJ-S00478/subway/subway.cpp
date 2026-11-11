#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fst first
#define scd second
using namespace std;
const int N=505;
const int M=5e5+5;
const int inf=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q;
int w[M];
vector <pii> e[N];
vector <pii> line[M];
int ans[N][N];

void init()
{
    for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++) ans[i][j]=(i==j?0:inf);

    for (int i=1;i<=m;i++)
    {
        int _size=line[i].size();
        for (int j=0;j<_size;j++)
        for (int k=j+1;k<_size;k++) 
        {
            int u=line[i][j].fst,v=line[i][k].fst;
            ans[u][v]=min(ans[u][v],line[i][j].scd+line[i][k].scd);
            ans[v][u]=ans[u][v];
        }
    }

    for (int k=1;k<=n;k++)
    for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++) ans[i][j]=min(ans[i][j],ans[i][k]+ans[k][j]);
}
int calc(int x,int y)
{
    int res=inf,size1=line[x].size(),size2=line[y].size();
    for (int i=0;i<size1;i++)
    for (int j=0;j<size2;j++) res=min(res,ans[line[x][i].fst][line[y][j].fst]+line[x][i].scd+line[y][j].scd);
    return res;
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;i++) cin>>w[i];
    for (int i=1;i<=n;i++)
    {
        int k,u,v; cin>>k;
        for (int ii=1;ii<=k;ii++)
        {
            cin>>u>>v;
            e[i].push_back({u,v}); 
            line[u].push_back({i,v});
        }
    }
    init(); int x,y;
    while (q--) { cin>>x>>y; cout<<calc(x,y)+w[x]+w[y]<<"\n"; } return 0;
}
//mj