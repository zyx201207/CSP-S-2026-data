#include<bits/stdc++.h>
#define endl '\n'
#define pb push_back

using namespace std;
typedef long long ll;;
typedef pair<ll,ll> pll;

const int N=505,M=5e5+233;
int c,n,m,d,q;
ll w[M];
vector<pll> lne[M];
ll g[N][N],dis[N][N];
const ll inf=1e18;


int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;i++) cin>>w[i];
    for (int i=1;i<=n;i++)
    {
        int k,a,t;
        cin>>k;
        for (int j=1;j<=k;j++)
            cin>>a>>t,lne[a].pb({i,t});
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) g[i][j]=inf;
    for (int i=1;i<=n;i++) dis[i][i]=0;
    for (ll i=1,u,v,w;i<=m;i++)
    {
        for (int j=0;j<lne[i].size();i++)
        {
            for (int k=j+1;k<lne[i].size();k++)
            {
                u=lne[i][j].first,v=lne[i][k].first,
                w=lne[i][j].second+lne[i][k].second;
                if (w<g[u][v]) g[u][v]=g[v][u]=w;
            }
        }
    }
    memset(dis,0x3f,sizeof dis);
    for (int i=1;i<=n;i++) dis[i][i]=0;

    for (int s=1;s<=n;s++)
    {
        priority_queue<pll,vector<pll>,greater<pll> > q;
        q.push({dis[s][s],s});
        while (q.size())
        {
            int u=q.top().second; q.pop();
            for (int i=1;i<=n;i++)
            {
                if (dis[s][i]>dis[s][u]+g[u][i])
                {
                    dis[s][i]=dis[s][u]+g[u][i];
                    q.push({dis[s][i],i});
                }
            }
        }
    }
    while (q--)
    {
        int x,y;
        cin>>x>>y;
        ll ans=dis[0][0];
        for (int i=0;i<lne[x].size();i++)
        {
            for (int j=0;j<lne[y].size();j++)
            {
                int u=lne[x][i].first,v=lne[y][j].first;
                ans=min(ans,dis[u][v]+lne[x][i].second+lne[y][j].second+w[x]+w[y]);
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}


