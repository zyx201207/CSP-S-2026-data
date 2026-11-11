#include<iostream>
#include<vector>
#include<climits>
#define ll long long
using namespace std;
const int MAXN=500,MAXM=5e5;
struct Line
{
    int l;
    ll d;
};
int w[MAXM+5];
vector<Line>li[MAXM+5];
ll g[MAXN+5][MAXN+5],dis[MAXN+5][MAXN+5];
int c,n,m,d,q;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(i==j)
            {
                dis[i][j]=0;
            }
            else
            {
                dis[i][j]=LLONG_MAX/2-1;
            }
        }
    }
    for(int i=1;i<=m;++i)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;++i)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;++j)
        {
            ll a,t;
            cin>>a>>t;
            li[a].push_back({i,t});
        }
    }
    for(int i=1;i<=m;++i)
    {
        for(int j=0;j<li[i].size();++j)
        {
            for(int k=0;k<li[i].size();++k)
            {
                int u=li[i][j].l,v=li[i][k].l;
                dis[u][v]=min(dis[u][v],li[i][j].d+li[i][k].d);
                dis[v][u]=dis[v][u];
            }
        }
    }
    for(int k=1;k<=n;++k)
    {
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                dis[j][i]=dis[i][j];
            }
        }
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        ll res=LLONG_MAX;
        for(auto i:li[x])
        {
            for(auto j:li[y])
            {
                res=min(res,dis[i.l][j.l]+w[x]+w[y]+i.d+j.d);
            }
        }
        cout<<res<<'\n';
    }
    return 0;
}
