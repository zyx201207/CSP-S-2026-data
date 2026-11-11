#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m,a[N],ans,c[N],s[N];
bool check(ll mid)
{
    ll cnt=m;
    bool flag=0;
    for(ll i=1;i<=n;i++)
    {
        cnt=m;
        ll goal=a[i+mid-1];
        if(i+mid-1>n)
        continue;
        if(s[i+mid-1]-s[i-1]+cnt>=goal*mid)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    return 1;
    else
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        s[i]=s[i-1]+a[i];
    }
    ll l=1,r=n;
    while(l<=r)
    {
        ll mid=(r+l)/2;
        if(check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
