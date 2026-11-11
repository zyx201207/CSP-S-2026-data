#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans,a[200005],w=1,dp[2005][2005];
void dfs(int l,int k,ll sc)//k is number of chosen,sc is result
{
    if(k==m)
    {
        if(sc!=w)
            ans=max(ans,sc);
        return;
    }
    if(l>n)return;
    dfs(l+1,k,sc);
    dfs(l+1,k+1,(sc&a[l]));
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    for(int i=1;i<=32;i++)w*=2;
    w--;//w代表没选择的默认值,不可能存在于正式结果中
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    if(n<=20)
    {
        dfs(1,0,w);
        printf("%lld\n",ans);
        return 0;
    }
    for(int i=1;i<=n;i++)
        dp[i][1]=max(dp[i-1][1],a[i]);
    for(int i=2;i<=n;i++)
        for(int j=2;j<=i;j++)
            dp[i][j]=max(dp[i-1][j],(dp[i-1][j-1]&a[i]));
    printf("%lld\n",dp[n][m]);
    return 0;
}
