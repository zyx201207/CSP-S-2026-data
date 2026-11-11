#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll w[N];
ll f[505][505];
struct node
{
    ll station;
    ll t;
};
vector<node>line[505];
struct edge
{
    int way;
    int id;
};
vector<edge>mid[N];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        mid[i].reserve(d+5);
        cin>>w[i];
    }
    int k;
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        line[i].resize(k+5);
        for(int j=1;j<=k;j++)
        {
            cin>>line[i][j].station>>line[i][j].t;
            mid[line[i][j].station].push_back({i,j});
        }
    }
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++)
    {
        f[i][i]=0;
    }
    for(int i=1;i<=m;i++)
    {
        for(edge &j:mid[i])
        {
            for(edge &k:mid[i])
            {
                int u=j.way;
                int v=k.way;
                if(u==v)
                {
                    continue;
                }
                ll w=line[u][j.id].t+line[v][k.id].t;
                f[u][v]=min(f[u][v],w);
            }
        }
    }
    for(int mid=1;mid<=n;mid++)
    {
        for(int l=1;l<=n;l++)
        {
            for(int r=1;r<=n;r++)
            {
                f[l][r]=min(f[l][r],f[l][mid]+f[mid][r]);
            }
        }
    }
    int x,y;
    for(int r=1;r<=q;r++)
    {
        cin>>x>>y;
        ll ans=1e18;
        for(edge &i:mid[x])
        {
            for(edge &j:mid[y])
            {
                int u=i.way;
                int v=j.way;
                ll add=w[x]+w[y]+line[u][i.id].t+line[v][j.id].t;
                ans=min(ans,f[u][v]+add);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}