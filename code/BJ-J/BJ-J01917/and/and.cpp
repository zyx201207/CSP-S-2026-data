#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL n,m,a[200001],dp[200001];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(LL i=1;i<=n;i++)
    {
        cin>>a[i];
        for(LL j=m;j>=1;j--)
        {
            if(j==1)
            {
                dp[j]=max(dp[j],a[i]);
            }
            else
            {
                dp[j]=max(dp[j-1]&a[i],dp[j]);
            }
        }
    }
    cout<<dp[m];
    return 0;
}
