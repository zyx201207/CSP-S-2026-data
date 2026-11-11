#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+5;
ll a[maxn],n,m;
ll pre[maxn];
bool check(ll x)
{
    for(int i=x;i<=n;i++)
    {
        ll sum=pre[i]-pre[i-x];
        ll need=a[i]*x;
        if(need-sum<=m)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        pre[i]=pre[i-1]+a[i];
    }
    ll l=1,r=n,ans=1;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        if(check(mid))
        {
            l=mid+1;
            ans=mid;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
