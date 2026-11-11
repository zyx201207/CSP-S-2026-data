#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 5e5 + 5;
typedef long long ll;
ll n, m, a[N], pre[N], res;
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i-1] + a[i];
    for (int i = 1; i <= n; i++)
    {
        ll l = 1, r = i, ans = -1;
        while (l <= r)
        {
            ll mid = (l + r) / 2;
            //cout << "i=" << i << ",mid=" << mid << ",cal:" << a[i]*(i-mid)-(pre[i-1]-pre[mid-1]) << "\n";
            if (1ll*a[i]*(i-mid)-(pre[i-1]-pre[mid-1]) <= m)
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        //cout << "get to" << i << ":ans=" << ans << "\n";
        res = max(res, i-ans+1);
    }
    cout << res << "\n";
    return 0;
}
