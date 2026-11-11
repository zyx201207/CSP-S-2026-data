#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[500005], s[500005], n, m, ans = -1;

bool check(ll x, ll i)
{
    return a[i] * (i - x + 1) - s[i] + s[x - 1] <= m;
}

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    for (int i = 1; i <= n; i++)
    {
        if (i < n && a[i] == a[i + 1]) continue;
        ll l = 1, r = i, p = i;
        while (l <= r)
        {
            ll mid = l + r >> 1;
            if (check(mid, i)) p = min(p, mid), r = mid - 1;
            else l = mid + 1;
        }
        ans = max(ans, i - p + 1);
    }
    cout << ans;
}