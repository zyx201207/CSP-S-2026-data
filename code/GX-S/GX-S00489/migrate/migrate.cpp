#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6;
ll T,n,a[N+5],zd[N+5],d,sum[N+5],dp[N+5],c;
void work()
{
    cin>>n>>d;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(ll i=1;i<=n+1;i++)
    {
        zd[i]=0;
        for(ll j=i+1;j<=n&&a[j]-a[i]<=d;j++) zd[i]=j;
    }
    ll ans=0;
    for(ll i=1;i<=n;i++)
    {
        ll l=i,r=i;
        for(ll j=1;j<=n;j++) dp[j]=sum[j]=0;
        sum[i]=dp[i]=1;
        while(zd[r])
        {
            ll nex=zd[r];
            for(ll j=r+1;j<=nex;j++)
            {
                while(a[j]-a[l]>d) l++;
                if(l<=r) dp[j]=min(sum[r]-sum[l-1],3ll);
                sum[j]=sum[j-1]+dp[j];
            }
            l=r+1;
            r=nex;
        }
        for(ll j=i+1;j<=n;j++) ans+=(dp[j]==2);
    }
    cout<<ans<<'\n';
}
void sol2()
{
    cin>>n>>d;
    for(ll i=1;i<=n;i++) cin>>a[i];
    if(n==1) cout<<0<<'\n';
    else
    {
        ll gc=a[2]-a[1];
        ll tims=d/gc;
        if(tims<=1) cout<<0<<'\n';
        else
        {
            ll ans=0;
            for(ll i=1;i<=n;i++)
            {
                if(i+tims+tims-1<=n) ans++;
            }
            cout<<ans<<'\n';
        }
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>T;
    //c=11;
    if(c<=10||c>12)
    {
        while(T--) work();
    }
    else if(c<=12)
    {
        while(T--) sol2();
    }
    return 0;
}
