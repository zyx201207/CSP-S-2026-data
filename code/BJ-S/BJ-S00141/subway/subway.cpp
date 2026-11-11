#include <iostream>
#include <vector>
#include <utility>
#define int long long
using namespace std;
constexpr int M=5e5+3,N=503;
int w[M];
vector<pair<int,int> > line[N];
int f[N][N];
vector<pair<int,int> > trans[M];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen(R"(/home/rdfz/code/problem/subway/subway7.in)","r",stdin);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for (int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for (int j=1;j<=k;j++)
        {
            int a_,t_;
            cin>>a_>>t_;
            line[i].push_back(make_pair(a_,t_));
            trans[a_].push_back(make_pair(i,t_));
        }
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            f[i][j]=1e18;
        }
        f[i][i]=0;
    }
    for (int u=1;u<=n;u++)
    {
        for (auto sta:line[u])
        {
            int a=sta.first,tu=sta.second;
            for (auto x:trans[a])
            {
                int v=x.first,tv=x.second;
                if (u==v) continue;
                f[u][v]=min(f[u][v],tu+tv);
            }
        }
    }
    for (int k=1;k<=n;k++)
    {
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    while (q--)
    {
        int x,y;
        cin>>x>>y;
        int ans=1e18;
        for (auto p:trans[x])
        {
            int u=p.first,tu=p.second;
            for (auto q:trans[y])
            {
                int v=q.first,tv=q.second;
                ans=min(ans,tu+f[u][v]+tv);
            }
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }
}
