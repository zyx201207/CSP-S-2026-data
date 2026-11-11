#include<bits/stdc++.h>
using namespace std;

#define int long long
constexpr int N = 500050;
int x[N], pre[N];

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n, m, ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> x[i];
    sort(x + 1, x + n + 1);
    for (int i = 1; i <= n; ++i)   
        pre[i] = pre[i - 1] + x[i];
    for (int i = 1; i <= n; ++i)
    {
        int l = 1, r = i;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (x[i] * (i - mid + 1) - (pre[i] - pre[mid - 1]) > m) l = mid + 1;
            else r = mid;
        }
        ans = max(ans, i - l + 1);
    }
    cout << ans;
    return 0;
}