#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf=1e18;
int e[505][500005],c,n,m,d,q;
ll w[505][505],ex[500005],dis[505][505];
vector<int> in[500005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)   cin>>ex[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dis[i][j]=inf;
        }
        dis[i][i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        while(k--)
        {
            int pos,val;
            cin>>pos>>val;
            e[i][pos]=val;
            in[pos].push_back(i);
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<in[i].size();j++)
        {
            for(int k=j+1;k<in[i].size();k++)
            {
                int u=in[i][j],v=in[i][k];
                if(e[u][i]+e[v][i]<dis[u][v])
                {
                    dis[u][v]=dis[v][u]=e[u][i]+e[v][i];
                }
            }
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        ll ans=inf;
        for(int i=0;i<in[x].size();i++)
        {
            for(int j=0;j<in[y].size();j++)
            {
                int u=in[x][i],v=in[y][j];
                ans=min(ans,e[u][x]+dis[u][v]+e[v][y]);
            }
        }
        cout<<ans+ex[x]+ex[y]<<'\n';
    }
    return 0;
}
