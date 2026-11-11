#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200010],dp[200010];
int main ()
{
    freopen ("and.in","r",stdin);
    freopen ("and.out","w",stdout);
    scanf ("%lld %lld",&n,&m);
    for (ll i = 1;i <= n;i++)
    {
        scanf ("%lld",&a[i]);
    }
    if (m == 1) cout << 0;
    else if (m == n)
    {
        ll sum = 0;
        for (ll i = 1;i <= n;i++)
        {
            sum &= a[i];
        }
        cout << sum;
    }
    else if (m == 2)
    {
        ll ans = 0;
        for (ll i = 1;i <= n;i++)
        {
            for (ll j = i+1;j <= n;j++)
            {
                ans = max (ans,a[i]&a[j]);
            }
        }
        cout << ans;
    }
    else if (m == n-1)
    {
        ll sum = 0,ans = 0;
        for (ll i = 1;i <= n;i++)
        {
            for (ll j = 1;j <= n;j++)
            {
                if (i == j) continue;
                sum &= a[j];
            }
            ans = max (ans,sum);
        }
        cout << ans;
    }
    else
    {
        for (ll i = 1;i <= n;i++)
        {
            for (ll j = i-1;j >= i-m+1 && j >= 1;j--)
            {
                dp[i] = max (dp[i],dp[j]&a[i]);
            }
        }
        cout << dp[n];
    }
    return 0;
}
