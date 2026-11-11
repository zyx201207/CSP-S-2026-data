#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=505,M=5e5+5,Q=1e5+5;
const ll inf=0x3fffffffffffffff;
int c,n,m,d,q,w[M],qx[Q],qy[Q];
ll dis[N][N];
vector<pii> e[M];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&w[i]);
    }
    int k,a,t;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&k);
        for(int j=1;j<=k;j++)
        {
            scanf("%d%d",&a,&t);
            e[a].push_back({i,t});
        }
    }
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d",&qx[i],&qy[i]);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i!=j)
            {
                dis[i][j]=inf;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(auto p1:e[i])
        {
            int x=p1.first,w1=p1.second;
            for(auto p2:e[i])
            {
                int y=p2.first,w2=p2.second;
                if(x==y)continue;
                dis[x][y]=min(dis[x][y],(ll)w1+w2);
                dis[y][x]=min(dis[y][x],(ll)w1+w2);
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
    for(int i=1;i<=q;i++)
    {
        ll ans=inf;
        int a=qx[i],b=qy[i];
        for(auto p1:e[a])
        {
            int x=p1.first,w1=p1.second;
            for(auto p2:e[b])
            {
                int y=p2.first,w2=p2.second;
                ans=min(ans,dis[x][y]+w1+w2);
            }
        }
        printf("%lld\n",ans+w[a]+w[b]);
    }
    return 0;
}