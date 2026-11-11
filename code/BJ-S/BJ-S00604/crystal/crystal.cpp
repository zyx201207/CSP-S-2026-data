#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],dp[500005]={0},ans=1;
int k,s=1;
void f1()
{
    for(int i=1;i<=n;i++)
    {
        memset(dp,0,sizeof(dp));
        for(int j=i+1;j<=n;j++)
        {
            dp[j]=dp[j-1]+(a[j]-a[j-1])*(j-i);
            if(dp[j]<=m)
            {
                ans=max(ans,j-i+1ll);
            }
            else
            {
                break;
            }
        }
    }
    return ;
}
void f2()
{
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+(a[i]-a[i-1])*(i-1);
        if(dp[i]<=m)
        {
            ans=i;
        }
    }
    return ;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i==2)
        {
            k=a[i]-a[i-1];
        }
        else
        {
            if(k!=a[i]-a[i-1])
            {
                s=0;
            }
        }
    }
    sort(a+1,a+n+1);
    if(s==1)
    {
        f2();
    }
    else
    {
        f1();
    }
    cout<<ans;
    return 0;
}