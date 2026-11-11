#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll n,m,ans;
ll a[N],s[N];
ll dp[N],p[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++)
        if(i>1)s[i-1]=a[i]-a[i-1];
    for(ll i=2;i<=n;i++)
        s[i]+=s[i-1];
    dp[1]=1;
    for(ll i=2;i<=n;i++)
    {
        p[i]=dp[i-1]*(s[i-1]-s[i-2])+p[i-1];
        dp[i]=dp[i-1]+1;
        while(p[i]>m&&dp[i]>1)
        {
            dp[i]--;
            p[i]-=(s[i-1]-s[i-dp[i]-1]);
        }
    }
    for(ll i=1;i<=n;i++)
        ans=max(ans,dp[i]);
    cout<<ans<<'\n';
    return 0;
}