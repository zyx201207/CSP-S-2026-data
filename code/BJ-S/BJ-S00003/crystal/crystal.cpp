#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[500010], sum[500010];
signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i];
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        int l = 1, r = i, mid;
        while(l <= r)
        {
            mid = (l + r) >> 1;

            if((i - mid + 1) * a[i] - (sum[i] - sum[mid - 1]) <= m)
            {
                ans = max(ans, i - mid + 1);
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
    }
    cout << ans << "\n";
    return 0;
}
//T1
