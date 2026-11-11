#include<bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y)
{
    return x<y;
}
bool cmp2(long long x,long long y)
{
    return x>y;
}
long long n,m,a[500005],dp[500005],ls[500005],ans=0;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    long long j=1;
    dp[1]=1;
    for(long long i=2;i<=n;i++)
    {
        ls[i]=ls[i-1]+(i-j)*(a[i]-a[i-1]);
        dp[i]=dp[i-1]+1;
        while(ls[i]>m)
        {
            ls[i]-=(a[i]-a[j]);
            j++;
            dp[i]--;
        }
    }
    sort(dp+1,dp+n+1,cmp2);
    cout<<dp[1];
    return 0;
}
// 1 4 6 8 56 59 61 62 64   10
// 1 2 3 3
// 0 3 7 6
// ls[i]=ls[i-1]+(i-j)*(a[i]-a[i-1]);  ls=0-0+1*3=3/ls=3+2*2=7/ls=7+3*2=13 13-(a[i]-a[j])=6;j=2;
