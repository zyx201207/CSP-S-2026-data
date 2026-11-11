#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 5e5 + 5;

int n, a[N], m, s[N];

bool check(int x)
{
    for (int i = x; i <= n; i++)
    {
        // i - x + 1 -> i
        int tmp = s[i] - s[i - x];
        if (1ll * x * a[i] - tmp <= m)
        {
            return 1;
        }
    }
    return 0;
}

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];

    int l = 1, r = n;
    while (l < r)
    {
        int mid = l + (r - l + 1) / 2;
//        cout << l << " " << r << " " << mid << " " << check(mid) << "\n";
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << "\n";
    return 0;
}
