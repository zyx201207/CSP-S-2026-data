#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=505,MAXM=500005;
int c,n,m,d,q,w[MAXM];
ll dis[MAXN][MAXN];
vector<array<int,2>>mp[MAXM];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k{};cin>>k;
        while(k--)
        {
            int x{},t{};cin>>x>>t;
            mp[x].push_back({i,t});
        }
    }
    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=n;i++)dis[i][i]=0;
    for(int i=1;i<=m;i++)
        for(int j=0;j<mp[i].size();j++)
            for(int k=j+1;k<mp[i].size();k++)
            {
                array<int,2> u=mp[i][j],v=mp[i][k];
                dis[u[0]][v[0]]=dis[v[0]][u[0]]=min<ll>(dis[u[0]][v[0]],u[1]+v[1]);
            }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--)
    {
        int x{},y{};cin>>x>>y;
        ll ans=w[x]+w[y],minn=LLONG_MAX;
        for(int j=0;j<mp[x].size();j++)
            for(int k=0;k<mp[y].size();k++)
                minn=min(minn,mp[x][j][1]+dis[mp[x][j][0]][mp[y][k][0]]+mp[y][k][1]);
        cout<<ans+minn<<'\n';
    }
    return 0;
}