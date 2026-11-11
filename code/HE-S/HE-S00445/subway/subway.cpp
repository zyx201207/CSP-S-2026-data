#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500+10,M=5e5+10;
ll dis[N][N],c,n,m,d,q,g[N][N],w[M];
vector<int> line[M];
unordered_map<ll,unordered_map<ll,ll>> t;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1,k;i<=n;i++)
    {
        cin>>k;
        for(int j=1,to,te;j<=k;j++)
        {
            cin>>to>>te;
            line[to].emplace_back(i);
            t[i][to]=te;
        }
    }
    memset(g,0x5f,sizeof g);
    for(int i=1;i<=m;i++) for(int j=0;j<line[i].size();j++) for(int k=j+1;k<line[i].size();k++) g[line[i][j]][line[i][k]]=g[line[i][k]][line[i][j]]=min(t[line[i][j]][i]+t[line[i][k]][i],g[line[i][j]][line[i][k]]);
    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) g[i][i]=0,dis[i][j]=dis[j][i]=min(dis[i][j],g[i][j]);
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==j || i==k || j==k) continue;
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--)
    {
        int x,y;
        ll ans=LLONG_MAX;
        cin>>x>>y;
        for(int start:line[x]) for(int End:line[y]) if(ans>dis[start][End]+t[start][x]+t[End][y]) ans=dis[start][End]+t[start][x]+t[End][y];
        cout<<ans+w[x]+w[y]<<'\n';
    }

    return 0;
}
