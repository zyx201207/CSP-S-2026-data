#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,c,d,q,w[N],k[505],f[505][505],x,y,minn;
vector<ll>a[505],t[505];
vector<pair<ll,ll>>g[N];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(f,0x3f,sizeof(f));
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        a[i].push_back(0);
        t[i].push_back(0);
        for(int j=1;j<=k[i];j++)
        {
            cin>>x>>y;
            a[i].push_back(x);
            t[i].push_back(y);
            g[x].push_back({i,y});
        }
    }
    for(int i=1;i<=n;i++)f[i][i] = 0;
    for(int i=1;i<=m;i++)for(int j=0;j<g[i].size();j++)for(int k=0;k<g[i].size();k++)f[g[i][j].first][g[i][k].first] = min(f[g[i][j].first][g[i][k].first],g[i][j].second+g[i][k].second);
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)for(int k=1;k<=n;k++)f[j][k] = min(f[j][k],f[j][i]+f[i][k]);
    while(q--)
    {
        cin>>x>>y;
        minn = LLONG_MAX;
        for(int i=0;i<g[x].size();i++)for(int j=0;j<g[y].size();j++)minn = min(minn,w[x]+g[x][i].second+f[g[x][i].first][g[y][j].first]+g[y][j].second+w[y]);
        cout<<minn<<endl;
    }
    return 0;
}