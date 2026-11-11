#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int c,n,m,d,q;
ll w[500010],dis[510][510];
vector<pair<int,ll> >a[500010];

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++)
        cin >> w[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin >> k;
        for(int j=1;j<=k;j++)
        {
            int x;ll t;
            cin >> x >> t;
            a[x].push_back(make_pair(i,t));
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j)dis[i][j]=1e18;
    for(int i=1;i<=m;i++)
    {
        int len=a[i].size();
        for(int j=0;j<len;j++)
        {
            for(int k=0;k<len;k++)
            {
                int u=a[i][j].first,v=a[i][k].first;
                ll val=a[i][j].second+a[i][k].second;
                dis[u][v]=min(dis[u][v],val);
            }
        }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--)
    {
        int u,v;
        cin >> u >> v;
        ll ans=1e18;
        for(int i=0;i<a[u].size();i++)
        {
            for(int j=0;j<a[v].size();j++)
            {
                int x=a[u][i].first,y=a[v][j].first;
                ll val=a[u][i].second+a[v][j].second;
                ans=min(ans,w[u]+w[v]+dis[x][y]+val);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
