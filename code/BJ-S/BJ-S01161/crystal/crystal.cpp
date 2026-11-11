#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n, m, a[N], sum[N];
signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        int l = 1, r = i, cur = -1;
        while(l <= r)
        {
            int mid = l + r >> 1;
            if((i - mid + 1) * a[i] - (sum[i] - sum[mid - 1]) <= m)
            {
                cur = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        if(cur == -1)   continue;
        //cout << cur <<endl;
        ans = max(ans, i - cur + 1);
    }
    cout << ans <<endl;
    return 0;
}
