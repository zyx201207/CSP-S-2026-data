#include<bits/stdc++.h>
using namespace std;
int c__,n,m,d__,q,w[500010];
long long f[510][510];
struct dat
{
    int v,len;
};
vector<dat> b[500010];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d %d %d %d %d",&c__,&n,&m,&d__,&q);
    for(int i=1;i<=m;i++)scanf("%d",&w[i]);
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++)f[i][i]=0;
    for(int i=1;i<=n;i++)
    {
        int te,u,l_;
        scanf("%d",&te);
        //cout<<te<<endl;
        while(te--)
        {
            scanf("%d %d",&u,&l_);
            b[u].push_back(dat{i,l_});
        }
    }
    for(int x=1;x<=m;x++)
    {
        for(int i=0;i<(int)b[x].size();i++)
        {
            for(int j=i+1;j<(int)b[x].size();j++)
            {
                int u=b[x][i].v,v=b[x][j].v;
                f[u][v]=f[v][u]=min(min(f[u][v],f[v][u]),1ll*b[x][i].len+b[x][j].len);
            }
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            if(i==k)continue;
            for(int j=1;j<=n;j++)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
        }
    }
    while(q--)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        long long ans=1e18;
        for(dat u:b[x])
        {
            for(dat v:b[y])
            {
                ans=min(ans,f[u.v][v.v]+u.len+v.len);
            }
        }
        printf("%lld\n",ans+w[x]+w[y]);
    }
    return 0;
}
