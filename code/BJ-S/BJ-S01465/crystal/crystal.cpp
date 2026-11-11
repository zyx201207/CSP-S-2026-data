#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
ll a[500001],sum[500001];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m,ans=0;
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i];
    }
    int l=1,s=0;
    for(ll i=1;i<=n;i++)
    {
        s=s+(a[i]-a[i-1])*(i-l);
        while(s>m && l<=i)
        {
            s-=(a[i]-a[l]);
            l++;
        }
        if(l<=i) ans=max(ans,i-l+1);
    }
    cout<<ans<<endl;
    cout<<flush;
    return 0;
}
