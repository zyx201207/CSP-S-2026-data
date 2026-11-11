#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

const int N = 5e5+5;
int n, m, a[N], s, ans;

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1, j = 1; i <= n; ++i)
    {
        s += (a[i] - a[i-1]) * (i - j);
        while (s > m)
        {
            s -= a[i] - a[j];
            ++j;
        }
        ans = max(ans, i-j+1);
    }
    cout << ans;
    return 0;
}
