#include <bits/stdc++.h>
using namespace std;
const int N=505;
const int M=5e5+5;
int C,n,m,d,q;
int w[N];
int dis[N][N];

int p[N];
int t[N];

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>C>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=n;i++)
    {
        int tot;
        cin>>tot;
        for(int j=0;j<tot;j++)
        {
            cin>>p[j]>>t[j];
        }
        for(int j=0;j<tot;j++)
        {
            for(int k=j+1;k<tot;k++)
            {
                int u=p[j];
                int v=p[k];
                dis[u][v]=min(dis[u][v],t[j]+t[k]);
                dis[v][u]=min(dis[v][u],t[j]+t[k]);
            }
        }
    }
    // for(int i=1;i<=m;i++)
    // {
    //     for(int j=1;j<=m;j++)
    //     {
    //         if(dis[i][j]==0x3f3f3f3f) cout<<"inf ";
    //         else cout<<fixed<<setw(3)<<dis[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
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
    for(int i=0;i<q;i++)
    {
        int u,v;
        cin>>u>>v;
        cout<<dis[u][v]+w[u]+w[v]<<endl;
    }
    return 0;
}