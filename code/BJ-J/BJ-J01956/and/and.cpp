#include<bits/stdc++.h>
int n,m,ans,a[200001],dp[200001];
void dfs(int b,int c,int d)
{
    if(c==m)
    {
        ans=std::max(ans,d);
        return;
    }
    if(b>n)
    {
        return;
    }
    dfs(b+1,c+1,d&a[b]);
    dfs(b+1,c,d);
}
int main()
{
    memset(dp,0xff,sizeof(dp));
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    std::cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        std::cin>>a[i];
    }
    if(n<=23)
    {
        dfs(1,0,0x7fffffff);
        std::cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=1;j--)
        {
            dp[j]=std::max(dp[j],dp[j-1]&a[i]);
        }
    }
    std::cout<<dp[m];
    return 0;
}
