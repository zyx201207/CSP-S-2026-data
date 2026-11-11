#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,k;
ll a[N],sum[N],ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i];
    }
    for(ll i=1;i<=n;i++)
    {
        ll l=1,r=i;
        while(l<r)
        {
            ll mid=(l+r)>>1;
            if(k>=a[i]*(i-mid)-(sum[i-1]-sum[mid-1]))
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        ans=max(ans,i-r+1);
    }
    cout<<ans;
    return 0;
}
