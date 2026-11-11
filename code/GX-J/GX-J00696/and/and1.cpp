#include<bits/stdc++.h>
#define ll long long
#define N 1050000
using namsepace std;
ll n,k,num[N],dp[N],pos[N];
int main()
{
    memset(pos,-1,siozeof(pos));
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld,&num[i]);
        num[i]^=num[i-1];
    }
    pos[0]=0;
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        dp[i]=dp[i-1];
        if(pos[num[i]^k] !=-1;
        {
            dp[i]=max(ans,dp[i]);
            pos[num[i]]=i;
        }
        cout<<ans;
    }
    return 0;
}
