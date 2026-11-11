#include <bits/stdc++.h>
#define For(i, j, k) for (long long i = j; i <= k; i ++)
#define Fro(i, j, k) for (long long i = j; i >= k; i --)
#define File(s) freopen(s".in", "r", stdin); freopen(s".out", "w", stdout)
using namespace std;
const long long N = 5e5 + 5;
long long n;
long long m, a[N], sum[N];
signed main()
{
    File("crystal");
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    For (i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    For (i, 1, n) sum[i] = sum[i - 1] + a[i];
    long long ans = 0;
    For (i, 1, n)
    {
        long long l = 1, r = i;
        long long minn = 0;
        while (l <= r)
        {
            long long mid = (l + r) / 2;
            if (a[i] * (i - mid) - (sum[i - 1] - sum[mid - 1]) <= m) r = mid - 1, minn = mid;
            else l = mid + 1;
        }
        ans = max(ans, i - minn + 1);
    }
    cout << ans;
    return 0;
}