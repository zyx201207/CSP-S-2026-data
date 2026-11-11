#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=6e5;
ll a[N],s[N];
ll n,m;

ll pd(ll x)
{

    for(int i=1;i<=n-x+1;i++)
    {
        if(a[i+x-1]*(i+x-1)-(s[i+x-1]-s[i-1])<=m)
            return 1;
    }
    return 0;
}


int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {

        s[i]=s[i-1]+a[i];
    }
    ll l=1,r=n,mid=(l+r)/2;
    ll ans=-1;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        if(pd(mid))
        {
            ans=mid,l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
