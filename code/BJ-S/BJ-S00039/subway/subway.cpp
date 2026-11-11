#include<bits/stdc++.h>
using namespace std;
struct node
{
    int v,w;
};
int n,m,c,q,d,w[500010],dis[1510][1510];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c;
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    int h=m;
    memset(dis,0x3f,sizeof(dis));
    for(int i=1; i<=m; i++)
    {
        scanf("%d",&w[i]);
    }
    if(c<=6)
    {
        for(int i=1; i<=n; i++)
        {
            int k;
            scanf("%d",&k);
            h++;
            for(int j=1; j<=k; j++)
            {
                int v,w;
                scanf("%d%d",&v,&w);
                dis[v][h]=w;
                dis[h][v]=w;
            }
        }
        m=h;
    }
    else
    {
        for(int i=1; i<=n; i++)
        {
            int k;
            scanf("%d",&k);
            int u,v,h1,h2;
            scanf("%d%d%d%d",&u,&h1,&v,&h2);
            dis[u][v]=h1+h2;
            dis[v][u]=h1+h2;
        }
    }
    for(int k=1; k<=m; k++)
    {
        for(int u=1; u<=m; u++)
        {
            if(u!=k)
            {
                for(int v=1; v<=m; v++)
                {
                    if(v!=u&&v!=k)
                    {
                        if(dis[u][k]+dis[k][v]<dis[u][v])
                        {
                            dis[u][v]=dis[u][k]+dis[k][v];
                            //cout<<u<<"#"<<v<<" "<<dis[u][v]<<endl;
                        }
                    }
                }
            }
        }
    }
    while(q--)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        printf("%d\n",dis[u][v]+w[u]+w[v]);
    }
}
