#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
ll n,m;
ll a[500010];
ll sum[500010];
ll maxi=-1e18;
ll ans=-1e18;
int main()
{
    freopen("crystal3.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+(a[i]-a[i-1])*(i-1);
    }
    for(int i=1;i<=n;i++)
    {
        ll y=sum[i]-m;
        ll x=lower_bound(sum+1,sum+i,y)-sum;
        ans=max(ans,i-x+1);
    }
    cout<<ans;
    return 0;
}
