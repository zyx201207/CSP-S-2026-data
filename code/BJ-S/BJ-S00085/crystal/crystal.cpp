#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 5;
int ans;
ll n, m, d;
ll a[N], sum[N], dp[N];
bool flag = 1;
bool check(int len)
{
    for (int i = 1; i <= n - len; i ++)
        if (dp[i + len] - dp[i - 1] <= m) return 1;
    return 0;
}
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        if (a[i] - a[i - 1] != d && i > 2) flag = 0;
        else d = a[i] - a[i - 1];
    }
    if (d == 0)
    {
        cout << n << endl;
        return 0;
    }
    if (flag == 1)
    {
        int l = 1, r = n;
        if (a[n] * (n - 1) - (a[1] + a[n - 1]) * (n - 1) / 2 <= m)
        {
            cout << n << endl;
            return 0;
        }
        while (l < r)
        {
            ll mid = l + r >> 1;
            if ((mid - 1) * mid / 2 * d <= m) l = mid + 1;
            else r = mid;
        }
        cout << l - 1 << endl;
        return 0;
    }
    sort(a + 1, a + n + 1);
    dp[1] = 0;
    for (int i = 2; i <= n; i ++)
        dp[i] = (i - 1) * (a[i] - a[i - 1]) + dp[i - 1];
    int l = 1, r = n;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) l = mid + 1;
        else r = mid;
    }
    cout << l << endl;
    return 0;
}