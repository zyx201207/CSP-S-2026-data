#include <bits/stdc++.h>
#define For(i, j, k) for (int i = j; i <= k; i ++)
#define Fro(i, j, k) for (int i = j; i >= k; i --)
#define File(s) freopen(s".in", "r", stdin); freopen(s".out", "w", stdout)
using namespace std;
const int N = 2e5 + 5, B = 35;
int n, m, a[N], cnt[B], ans[N], cur;
signed main()
{
    File("and");
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    For (i, 1, n)
    {
        cin >> a[i];
        For (j, 0, 29) if (a[i] & (1 << j)) cnt[j] ++;
    }
    Fro (j, 29, 0)
    {
        if (cnt[j] < m) continue;
        For (i, 1, n) if (a[i] & (1 << j)) ans[++ cur] = a[i];
        sort(ans + 1, ans + cur + 1, greater <int>());
        int res = ans[1];
        For (i, 2, m) res &= ans[i];
        cout << res;
        return 0;
    }
    cout << 0;
    return 0;
}