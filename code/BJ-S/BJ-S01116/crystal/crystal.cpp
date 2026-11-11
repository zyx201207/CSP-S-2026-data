#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;

int a[500005], s[500005];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    a[n + 1] = -1e18;
    int nas = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == a[i + 1])
            continue;
        int l = 1, r = i, L = -1;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (a[i] * (i - mid + 1) - (s[i] - s[mid - 1]) <= m)
            {
                L = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        nas = max(nas, i - L + 1);
    }
    cout << nas;
    return 0;
}