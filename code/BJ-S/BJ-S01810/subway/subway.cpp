#include<bits/stdc++.h>
#define int long long
#define faster ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pii pair<int,int>
#define fr first
#define sc second
using namespace std;
const int N=505,M=5e5+5;
vector<pii> con[M];
int C,n,m,D,q,W[M],K[M],f[N][N];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    faster;
    cin >> C >> n >> m >> D >> q;
    for(int i=1;i<=m;i++)
    {
        cin >> W[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin >> K[i];
        int a,t;
        for(int j=1;j<=K[i];j++)
        {
            cin >> a >> t;
            con[a].push_back({i,t});
        }
    }
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++)f[i][i]=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<(int)con[i].size();j++)
        {
            for(int k=j+1;k<(int)con[i].size();k++)
            {
                int u=con[i][j].fr,v=con[i][k].fr,w=con[i][j].sc+con[i][k].sc;
                f[u][v]=min(f[u][v],w);
                f[v][u]=min(f[v][u],w);
            }
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    int s,t;
    for(int i=1;i<=q;i++)
    {
        cin >> s >> t;
        int ans=1e18;
        for(int j=0;j<(int)con[s].size();j++)
        {
            for(int k=0;k<(int)con[t].size();k++)
            {
                int u=con[s][j].fr,v=con[t][k].fr,w=con[s][j].sc+con[t][k].sc;
                ans=min(ans,w+f[u][v]);
            }
        }
        cout << ans+W[s]+W[t] <<'\n';
    }
    return 0;
}