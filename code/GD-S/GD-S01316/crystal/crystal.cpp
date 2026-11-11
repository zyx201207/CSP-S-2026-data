#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
int n, m, ans, a[500005];
bool check(int x)
{
    int sum = 0;
    for (int i = 1; i <= x; i++)
        sum += a[x] - a[i];
    return sum <= m;
}
signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    int l = 1, r = n, mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (check(mid))
            l = mid + 1, ans = mid;
        else
            r = mid - 1;
    }
    cout << ans << endl;
    return 0;
}