#include <bits/stdc++.h>
using namespace std;
struct node{
    long long to;
    long long val;
};
long long testt,n,m,maxx,q,x,y;
long long kk,a,v,w[500005];
vector<node> adj[500005];
long long ans,dis[505][505];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> testt >> n >> m >> maxx >> q;
    for (int i=1;i<=m;i++)
    {
        cin >> w[i];
    }
    for (int i=1;i<=n;i++)
    {
        cin >> kk;
        for (int j=1;j<=kk;j++)
        {
            cin >> a >> v;
            adj[a].push_back({i,v});
        }
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            dis[i][j]=1e18;
        }
        dis[i][i]=0;
    }
    for (int i=1;i<=m;i++)
    {
        for (node ii:adj[i])
        {
            for (node jj:adj[i])
            {
                dis[ii.to][jj.to]=min(dis[ii.to][jj.to],ii.val+jj.val);
            }
        }
    }
    for (int k=1;k<=n;k++)
    {
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while (q--)
    {
        cin >> x >> y;
        ans=1e18;
        for (node i:adj[x])
        {
            for (node j:adj[y])
            {
                ans=min(ans,i.val+j.val+dis[i.to][j.to]);
            }
        }
        cout << ans+w[x]+w[y] << endl;
    }
    return 0;
}