#include<bits/stdc++.h>
using namespace std;
const int MAXM=5e5+5;
int w[MAXM],num[505];
long long dis[505][505];
vector<pair<int,int> > a[MAXM];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,n,m,d,q,x,y,s,t;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>num[i];
        for(int j=1;j<=num[i];j++)
        {
            cin>>s>>t;
            a[s].push_back({i,t});
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dis[i][j]=1e18;
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<a[i].size();j++)
        {
            int u=a[i][j].first;
            for(int k=0;k<a[i].size();k++)
            {
                int v=a[i][k].first;
                dis[u][v]=a[i][j].second+a[i][k].second;
            }
        }
    }
    for(int i=1;i<=n;i++)
        dis[i][i]=0;
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    for(int i=1;i<=q;i++)
    {
        cin>>x>>y;
        long long ans=1e18;
        for(int j=0;j<a[x].size();j++)
        {
            int u=a[x][j].first;
            for(int k=0;k<a[y].size();k++)
            {
                int v=a[y][k].first;
                ans=min(ans,dis[u][v]+a[x][j].second+a[y][k].second+w[x]+w[y]);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
