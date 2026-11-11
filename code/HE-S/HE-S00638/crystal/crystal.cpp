#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

const int N = 5e5 + 10;

#define int long long

int a[N], s[N], n, m, ans;

signed main()
{
    freopen("data.in", "r", stdin); freopen("data.out", "w", stdout);
    freopen("crystal.in", "r", stdin); freopen("crystal.out", "w", stdout);
    ios :: sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    for (int i = 1; i <= n; i++)
    {
        int l = 1, r = i, pos = i;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if ((i - mid + 1) * a[i] - (s[i] - s[mid - 1]) <= m) pos = mid, r = mid - 1;
            else l = mid + 1;
        }
        ans = max(ans, i - pos + 1);
    }
    cout << ans << '\n';

    return 0;
}