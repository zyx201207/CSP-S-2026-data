#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
int a[500005];
int c[500005];
int s[500005];
int ans = 1;

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++)
        c[i] = a[n] - a[i],
        s[i] = s[i-1] + c[i];
    for(int i = 1; i <= n; i++)
    {
        int l = 1, r = i;
        int ret = 0x3f3f3f3f3f3f3f3f;
        while(l <= r)
        {
            int mid = l + r >> 1;
            int tmp = s[i] - s[mid-1] - (i - mid + 1) * (a[n] - a[i]);
            if(tmp <= m)
            {
                ret = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        ans = max(ans, i - ret + 1);
    }
    cout << ans;

    return 0;
}