#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, d, ans, a[200005];

ll lg2(ll x)
{
    ll a = log2(x), b = 2, mul = 1;
    while (a > 0)
    {
        if (a & 1) mul *= b;
        a >>= 1, b *= b;
    }
    return mul;
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    a[0] = n;
    ll x = lg2(a[n]);
    while (x > 0)
    {
        ll b[200005], tot = 0;
        int p = lower_bound(a + 1, a + a[0] + 1, x) - a;
        if (a[0] - p + 1 >= m)
        {
            ans += x;
            for (int i = p; i <= a[0]; i++) b[++tot] = a[i] - x;
            memcpy(a, b, sizeof(a));
            a[0] = tot;
            d = 0;
        }
        else
        {
            for (int i = p; i <= a[0]; i++) a[i] -= x;
            sort(a + 1, a + a[0] + 1);
        }
        x /= 2;
    }
    cout << ans;
}