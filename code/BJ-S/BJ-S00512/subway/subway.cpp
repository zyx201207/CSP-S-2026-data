#include <bits/stdc++.h>
using namespace std;
long dp[501][501],ro[500001][21],rt[500001][21];
int w[500001];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            dp[i][j]=dp[j][i]=20000000000000l;
        }
    }
    for(int i=1;i<=m;i++)
        scanf("%d",&(w[i]));
    for(int i=1;i<=n;i++)
    {
        int k;
        scanf("%d",&k);
        while(k--)
        {
            int a,t;
            scanf("%d %d",&a,&t);
            ro[a][++ro[a][0]]=i;
            rt[a][ro[a][0]]=t;
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<ro[i][0];j++)
        {
            for(int k=j+1;k<=ro[i][0];k++)
            {
                dp[ro[i][j]][ro[i][k]]=dp[ro[i][k]][ro[i][j]]=rt[i][j]+rt[i][k];
            }
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                dp[i][j]=dp[j][i]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    while(q--)
    {
        int x,y;
        long ans=20000000000000ll;
        scanf("%d %d",&x,&y);
        for(int i=1;i<=ro[x][0];i++)
        {
            for(int j=1;j<=ro[y][0];j++)
            {
                ans=min(ans,dp[ro[x][i]][ro[y][j]]+rt[x][i]+rt[y][j]);
            }
        }
        printf("%ld\n",(ans+w[x]+w[y]));
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
