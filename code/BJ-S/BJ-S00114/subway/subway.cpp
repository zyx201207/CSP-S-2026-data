#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int N=5e5+10,M=510,inf=0x3f3f3f3f3f3f3f3f;
int w[N],k[N];
vector<pii> g[N];
int dis[M][M];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    int a,t;
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a>>t;
            g[a].push_back({i,t});
        }
    }
    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int i=1;i<=m;i++)
    {
        for(auto j:g[i])
        {
            for(auto l:g[i])
            {
                if(j.first==l.first) continue;
                dis[j.first][l.first]=min(dis[j.first][l.first],j.second+l.second);
                dis[l.first][j.first]=min(dis[l.first][j.first],j.second+l.second);
            }
        }
    }
    for(int l=1;l<=n;l++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                dis[i][j]=min(dis[i][j],dis[i][l]+dis[l][j]);
                dis[j][i]=dis[i][j];//min(dis[j][i],dis[j][l]+dis[l][i]);
            }
        }
    }
    int u,v;
    while(q--)
    {
        cin>>u>>v;
        int ans=inf;
        for(auto i:g[u])
        {
            for(auto j:g[v])
            {
                ans=min(ans,dis[i.first][j.first]+i.second+j.second);
            }
        }
        cout<<ans+w[u]+w[v]<<"\n";
    }
    return 0;
}