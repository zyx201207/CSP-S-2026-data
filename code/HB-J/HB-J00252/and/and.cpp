#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
long long a[200005],dp[200005],t;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        dp[1]=max(dp[1],a[i]);
        if(dp[1]=a[i]){t=i;}
    }
    a[t]=0;
    for(int i=2;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[i]=max(dp[i],dp[i-1]&a[j]);
            if(dp[i]==dp[i-1]&a[j]){t=j;}
        }
        a[t]=0;
    }
    cout<<dp[m];
    return 0;
}
