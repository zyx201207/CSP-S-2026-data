#include<bits/stdc++.h>
using namespace std;
int w[505],a[505][505],t[505][505],k[1005],dis[1005][1005];
vector<pair<int,int>> g[1005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,m,n,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<k[i];j++)
        {
            for(int p=j+1;p<=k[i];p++)
            {
                g[a[i][p]].push_back(make_pair(a[i][j],t[i][j]+t[i][p]));
                g[a[i][j]].push_back(make_pair(a[i][p],t[i][j]+t[i][p]));
            }
        }
    }
    fill(&dis[0][0],&dis[0][0]+1005*1005,0x3f3f3f3f);
    for(int i=1;i<=m;i++)
    {
        dis[i][i]=0;
        for(auto e:g[i])
        {
            int v=e.first;
            dis[i][v]=e.second;
            dis[v][i]=e.second;
        }
    }
    for(int k=1;k<=m;k++)
    {
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=m;j++)
            {
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        cout<<dis[x][y]+w[x]+w[y]<<endl;
    }
    return 0;
}
