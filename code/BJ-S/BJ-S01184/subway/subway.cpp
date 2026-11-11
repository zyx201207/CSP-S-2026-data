#include<bits/stdc++.h>
using namespace std;
int c,n,m,q;
int w[500001];
long long d[501][501];
vector<pair<int,int>>g[500001];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&c,&q);
    for(int i=1;i<=m;i++)scanf("%d",&w[i]);
    for(int i=1,k;i<=n;i++)
    {
        scanf("%d",&k);
        while(k--)
        {
            int x,t;
            scanf("%d%d",&x,&t);
            g[x].push_back({i,t});
        }
    }
    memset(d,0x3f,sizeof d);
    for(int i=1;i<=n;i++)d[i][i]=0;
    for(int i=1;i<=m;i++)
        for(pair<int,int>j:g[i])
            for(pair<int,int>k:g[i])d[j.first][k.first]=min(d[j.first][k.first],1ll*j.second+k.second);
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    while(q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(x==y)
        {
            printf("0\n");
            continue;
        }
        long long res=1e18;
        for(pair<int,int>l1:g[x])
            for(pair<int,int>l2:g[y])res=min(res,d[l1.first][l2.first]+l1.second+l2.second);
        printf("%lld\n",res+w[x]+w[y]);
    }
    return 0;
}
