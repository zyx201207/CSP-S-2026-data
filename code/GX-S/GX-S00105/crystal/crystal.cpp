#include <bits/stdc++.h>
using namespace std;
struct lb
{
    long long int cnt=0,num;
};
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long int n,m;
    cin>>n>>m;
    long long int a[n+5];
    for(long long int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    lb dp[n+5][m+5];
    for(int i=0;i<m;i++)
    {
        dp[0][i].num=a[0]+i;
        dp[0][i].cnt=1;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            dp[i][j].num=a[i]+j;
            if(a[i-1]+(m-j)>=a[i]+j)
            {
                dp[i][j].cnt=dp[i-1][a[i]+j-a[i-1]].cnt+1;
            }
        }
    }
    long long int MAX=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            MAX=max(MAX,dp[i][j].cnt);
        }
    }
    cout<<MAX;
    return 0;
}
