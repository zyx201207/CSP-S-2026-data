#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll N = 5e5;

ll n, m;
ll a[N + 5], s[N + 5];

ll lbound(ll i)
{
    ll l = 1;
    ll r = i;

    while (l < r)
    {
        ll mid = l + r >> 1;
        if (a[i] * (i - mid) - (s[i - 1] - s[mid - 1]) <= m) r = mid;
        else l = mid + 1;
    }

    return l;
}

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (ll i = 1; i <= n; ++i) cin >> a[i];

    sort(a + 1, a + n + 1);
    ll ans = 0;

    for (ll i = 1; i <= n; ++i)
    {
        s[i] = s[i - 1] + a[i];
        ans = max(ans, i - lbound(i) + 1);
    }

    cout << ans << endl;

    return 0;
}