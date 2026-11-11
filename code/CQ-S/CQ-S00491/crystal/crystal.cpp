#include <bits/stdc++.h>
//#define int long long
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int N = 5e5 + 10; /// change the range
ll a[N];
signed main()
{
    freopen ("crystal.in", "r", stdin); ///write the name
    freopen ("crystal.out", "w", stdout); ///write the name
    ll n, m; scanf ("%lld %lld", &n, &m);
    for (int i = 1; i <= n; i++) scanf ("%lld", a + i);
    sort (a + 1, a + n + 1);
    ll r = 1, l = 1, val = 0, res = 0;
    for (; r <= n; r++)
    {
        val += (r - l) * (a[r] - a[r - 1]);
        while (val > m)
        {
            val -= a[r] - a[l];
            l++;
        }
        res = max (res, r - l + 1);
    }
    printf ("%lld\n", res);
    return 0;
}