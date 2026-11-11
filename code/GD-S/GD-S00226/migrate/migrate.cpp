#include <bits/stdc++.h>
#define For(i, j, k) for (long long i = j; i <= k; i ++)
#define Fro(i, j, k) for (long long i = j; i >= k; i --)
#define File(s) freopen(s".in", "r", stdin); freopen(s".out", "w", stdout)
using namespace std;
const long long N = 2e6 + 5, NN = 5e3 + 5;
long long n, d, a[N], c;
void A()
{
    long long dis = a[2] - a[1];
    if (dis * 2 > d)
    {
        cout << "0\n";
        return;
    }
    long long cnt = d / dis;
    cout << max(0ll, n - cnt * 2 + 1) << "\n";
}
int pii[N];
long long dp[NN][NN];
long long cnt = 0;
void dfs(long long l, long long r, long long step, long long minn)
{
    if (step == minn)
    {
        cnt += (dp[l][r] == 1);
        return;
    }
    For (i, l + 1, n) if (dp[l][i] == 1) dfs(i, r, step + 1, minn);
}
bool calc(long long l, long long r)
{
    cnt = 0;
    dfs(l, r, 1, dp[l][r]);
    return cnt == 2;
}
void baoli()
{
    For (i, 1, n) dp[i][i] = 0;
    For (i, 1, n) For (j, i + 1, n) dp[i][j] = 0x3f3f3f3f3f3f3f3f;
    For (i, 1, n) For (j, i + 1, n)
    {
        long long l = 1, r = j - 1, res = 0;
        while (l <= r)
        {
            long long mid = (l + r) / 2;
            if (a[j] - a[mid] <= d) r = mid - 1, res = mid;
            else l = mid + 1;
        }
        For (k, res, j - 1) dp[i][j] = min(dp[i][j], dp[i][k] + 1);
    }
    long long ans = 0;
    For (i, 1, n) For (j, i + 1, n) ans += calc(i, j);
    cout << ans << "\n";
}
void solve()
{
    cin >> n >> d;
    For (i, 1, n) cin >> a[i];
    if (11 <= c && c <= 12) A();
    else baoli();
}
signed main()
{
    File("migrate");
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t; cin >> c >> t;
    while (t --) solve();
    return 0;
}