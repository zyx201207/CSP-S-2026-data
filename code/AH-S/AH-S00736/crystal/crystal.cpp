#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 5;

int n;
ll m, a[N], sum[N], ans;

bool check(int mid)
{
    ll mn = 2e18;
    for (int i = mid; i <= n; ++i)
    {
        if (a[i] * mid - sum[i] + sum[i - mid] <= mn)
            mn = a[i] * mid - sum[i] + sum[i - mid];
    }
    return m >= mn;
}

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
        sum[i] = sum[i - 1] + a[i];
    int l = 1, r = n, mid;
    while (l <= r)
    {
        mid = l + r >> 1;
        if (check(mid))
        {
            l = mid + 1;
            ans = mid;
        }
        else r = mid - 1;
    }
    cout << ans;
    return 0;
}
