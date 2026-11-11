#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
ll n, m;
ll a[N];
ll check (ll cur)
{
    ll sum = 0;
    for (int i = 1; i <= cur; i ++)
        sum += a[i];
    if (cur * a[cur] - sum <= m) return 1;
    for (int i = cur + 1; i <= n; i ++)
    {
        sum -= a[i - cur];
        sum += a[i];
        if (cur * a[i] - sum <= m) return 1;
    }
    return 0;
}
int main ()
{
    freopen ("crystal.in", "r", stdin);
    freopen ("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    sort (a + 1, a + 1 + n);
    ll l = 1, r = n, ans = 0;
    while (l <= r)
    {
        ll mid = (l + r) >> 1;
        if (check (mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << ans;
    return 0;
}
/*
几分钟秒了
二分答案即可
八十中的电脑神了
*/