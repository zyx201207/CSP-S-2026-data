#include <bits/stdc++.h>
using namespace std;

int n, ans;
long long m, a[500005], s[500005];

bool check(int x)
{
    for (int i = 1; i <= n - x + 1; i++)
    {
        if (x * a[i + x - 1] - (s[i + x - 1] - s[i - 1]) <= m) return 1;
    }
    return 0;
}

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    int l = 1, r = n, mid;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (check(mid))
        {
            l = mid + 1;
            ans = mid;
        }
        else r = mid - 1;
    }
    //cout << check(4);
    cout << ans;
    return 0;
}
