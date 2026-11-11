#include <iostream>
#include <algorithm>
using namespace std;

long long n, m, a[500005], cnt = 0, ans = 0, l = 1, r = 1;
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 2; i <= n; i++)
    {
        cnt += (i - 1) * (a[i] - a[i - 1]);
        if (cnt > m)
        {
            cnt -= (i - 1) * (a[i] - a[i - 1]);
            ans = i - 1;
            break;
        }
    }
    r = ans + 1;
    for (; r <= n; r++)
    {
        cnt += (r - l) * (a[r] - a[r - 1]);
        while (cnt > m && l <= n - 1)
        {
            l++;
            cnt -= a[r] - a[l - 1];
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans;
    return 0;
}
