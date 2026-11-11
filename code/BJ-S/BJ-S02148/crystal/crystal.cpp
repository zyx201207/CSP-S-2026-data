#include<bits/stdc++.h>
using namespace std;
const int N = 500050;
using ll = long long;
ll a[N],d[N];
ll n,m;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(ll i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    d[0] = 0;
    for(ll i=1;i<=n;i++) d[i] = d[i-1] + a[i];

    ll ans = 0;

    for(ll i=1;i<=n;i++)
    {
        ll l=1,r=i;
        while(l <= r)
        {
            ll mid = (l+r)/2;
            if(a[i]*(i-mid) - (d[i-1] - d[mid-1]) <= m)
            {
                ans = max(ans,i-mid+1);
                r = mid - 1;
            }
            else l = mid + 1;
        }
    }
    cout << ans;
    return 0;
}