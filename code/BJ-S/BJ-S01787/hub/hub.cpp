#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
int C,T,n,K,dis[maxn][maxn],vis[maxn],tans[maxn],ans,d[maxn][maxn],fa[maxn];

int find(int x)
{
    if(fa[x]==x)
        return x;
    return fa[x]=find(fa[x]);
}
void hb(int x,int y)
{
    int a = find(x);
    int b =  find (y);
    fa[a] = b;
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&C,&T);//printf("%lld\n",T);
    while(T--)
    {

        ans = 1e7;
        scanf("%d%d",&n,&K);
        for(int i =1;i<=n;++i)
        {
            for(int j =1;j<=n;++j)
            {
                dis[i][j] = 1e8;
                d[i][j] = 0;
            }

            dis[i][i] = 0;
            fa[i] = i;
        }

        for(int i=1;i<n;++i)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            dis[u][v] = dis[v][u]=d[v][u]=d[u][v] =1;
        }
        for(int k =1;k<=n;++k)
        {
            for(int i =1;i<=n;++i)
                for(int  j=1;j<=n;++j)
                {
                    dis[i][j] = min(dis[i][k]+dis[k][j],dis[i][j]);
                    dis[j][i] =dis[i][j];
                }
        }
        for(int i =0;i<(1LL<<n);++i)
        {
            int sum =0,cnt=0;
            for(int j=1;j<=n;++j)
            {
                if((1LL<<(j-1))&i)
                {
                    vis[j] =1;
                    ++sum;
                }
                else
                    vis[j] = 0;
            }
            for(int j=1;j<=n;++j)
            {
                if(!vis[j])
                    continue;
                for(int k =1;k<=n;++k)
                    if(d[j][k]&&vis[k])
                    {
                        hb(j,k);
                    }

            }
            for(int j=1;j<=n;++j)
                if(vis[j]&&find(j)==j)
                    ++cnt;
            if(cnt>2)
                continue;
            if(sum!=K)
                continue;
            for(int j=1;j<=n;++j)
            {
                tans[j] = 1e5;
                for(int k =1;k<=n;++k)
                {
                    if(vis[k])
                        tans[j] = min(tans[j],dis[j][k]);
                }
            }
            int uu = 0;
            for(int j =1;j<=n;++j)
                uu=max(uu,tans[j]);
            ans=min(ans,uu);
        }
        printf("%d\n",ans);
    }
    return 0;
}
