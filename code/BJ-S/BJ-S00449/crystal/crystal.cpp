#include<bits/stdc++.h>
using namespace std;
#define int long long

const int nr = 5e5 + 10;
int n, m, a[nr], pre[nr];

bool check(int l, int r)
{
    return a[r] * (r - l + 1) - (pre[r] - pre[l - 1]) <= m;
}

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        int l = 1, r = i, cur = i;
        while (l <= r)
        {
            int mid = l + r >> 1;
            if (check(mid, i)) cur = mid, r = mid - 1;
            else l = mid + 1;
        }
        res = max(res, i - cur + 1);
    }
    cout << res << '\n';
    return 0;
}
