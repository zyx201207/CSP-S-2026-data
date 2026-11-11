#include<bits/stdc++.h>
using namespace std;
const int N=505;
int w[N],sum[N],t[N][N];
int c,n,m,d,q;
bool flag=1;
set<int> a[N];
int dis[N][N];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        if(k>2)
            flag=0;
        for(int j=1;j<=k;j++)
        {
            int v,w;
            cin>>v>>w;
            t[i][v]=w;
            a[i].insert(v);
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++)
    {
        for(auto u:a[i])
        {
            for(int v:a[i])
            {
                if(u!=v)
                {
                    dis[u][v]=min(dis[u][v],t[i][u]+t[i][v]);
                }
            }
        }
    }
    for(int k=1;k<=m;k++)
    {
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=m;j++)
            {
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[j][k]);
                //cout<<dis[i][j]<<' ';
            }
            //cout<<'\n';
        }
        //cout<<'\n';
    }
    while(q--)
    {
        int u,v;
        cin>>u>>v;
        cout<<w[u]+w[v]+dis[u][v]<<'\n';
    }
    return 0;
}
