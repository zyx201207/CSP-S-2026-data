#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
bool cmp(int x,int y)
{
    return x-y<y-x;
}
long long dp[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        dp[i]=dp[i-1]+(a[i]-a[i-1])*(i-1);
        if(dp[i]>m)
        {
            printf("%d",i-1);
            return 0;
        }
    }
    return 0;
}
