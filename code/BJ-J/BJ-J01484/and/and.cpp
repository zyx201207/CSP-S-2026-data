#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[200010];
int dp[200010];
int n,m;

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(m==1)
    {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans=max(ans,a[i]);
        }
        cout<<ans;
    }
    else if(m==2&&n<=3000)
    {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<i;j++)
            {
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
    }
    else if(m==n)
    {
        int ans=a[1];
        for(int i=2;i<=n;i++)
        {
            ans&=a[i];
        }
        cout<<ans;
    }
    else
    {
        dp[0]=(1<<30)-1;
        for(int i=1;i<=n;i++)
        {
            for(int j=min(i,m+1);j>=1;j--)
            {
                dp[j]=max(dp[j],dp[j-1]&a[i]);
            }
        }
        cout<<dp[m];
    }
    return 0;
}
