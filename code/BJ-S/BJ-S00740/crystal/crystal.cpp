#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N=5e5+10;
ll n,m,a[N],sum[N],ans;

bool check(ll s,ll x)
{
    ll tmp=(sum[s]-sum[x-1])-(a[s]*(s-x+1));
    //printf("s=%lld, x=%lld, tmp=%lld, sum=%lld\n",s,x,tmp,sum[s]-sum[x-1]);
    return m+tmp>=0;
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);

    cin >> n >> m;
    for(ll i=1;i<=n;i++)cin >>a[i],a[i]+=1e12;
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++)sum[i]=a[i]+sum[i-1];
    for(ll i=1;i<=n;i++)
    {
        //printf("a[%lld] = %lld\n",i,a[i]);
        ll l=0,r=i+1;
        while(l+1!=r)
        {
            ll mid=(l+r)>>1;
            if(check(i,mid))r=mid;
            else l=mid;
        }
        ans=max(ans,i-r+1);
    }
    cout << ans << endl;

    return 0;
}
