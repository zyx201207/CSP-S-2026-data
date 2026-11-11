#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 7;
long long a[N], suma[N];

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) suma[i] = suma[i - 1] + a[i];
    int mx = 1;
    for (int i = 1; i <= n; ++i)
    {
        int l = 1, r = i, mid, ans;
        while (l <= r)
        {
            mid = (l + r) >> 1;
            if (1ll * a[i] * (i - mid + 1) - (suma[i] - suma[mid - 1]) <= m)
            {
                ans = i - mid + 1, r = mid - 1;
            }
            else l = mid + 1;
        }
        mx = max(mx, ans);
    }
    cout << mx << endl;
    return 0;
}
