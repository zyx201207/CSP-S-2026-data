#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define urep(i, r, l) for(int i = (r); i >= (l); i--)
constexpr int _ = 305, mod = 998244353, inf = 0x3f3f3f3f3f3f3f3f;

inline int rd()
{
    signed c = getchar();
    int res = 0, f = 1;
    for(; !isdigit(c); c = getchar()) if(c == '-') f = -1;
    for(; isdigit(c); c = getchar()) res = res * 10 + (c ^ 48);
    return res * f;
}

int c, t;
int n, d, a[_];
int pre[_], nxt[_];
int dp[_][_];

signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    c = rd(), t = rd();
    while(t--)
    {
        n = rd(), d = rd();
        rep(i, 1, n) a[i] = rd();
        rep(i, 1, n) rep(j, 1, n) dp[i][j] = inf;
        rep(i, 1, n) 
        {
            pre[i] = lower_bound(a + 1, a + i + 1, a[i]-d) - a, nxt[i] = upper_bound(a + i + 1, a + n + 1, a[i]+d) - a - 1;
        }
        int ans = 0;
        rep(l, 1, n) rep(r, l+1, n)
        {
            int p = l;
            dp[l][r] = 0;
            while(p < r)
            {
                p = nxt[p];
                dp[l][r]++;
                if(p == nxt[p] && p < r) {dp[l][r] = inf; break;}
            }
        }
        rep(l, 1, n) rep(r, l+1, n)
        {
            int cnt = 0;
            int p = l;
            while(nxt[p] <= r && nxt[p] != p)
            {
                rep(i, p + 1, nxt[p]-1) if(dp[l][i] + dp[i][r] == dp[l][r]) cnt++;
                p = nxt[p];
            }
            ans += cnt == 1;
            // cerr << l << " " << r << " " << cnt << "\n";
        }
        cout << ans << "\n";
    }
    return 0;
}

/*

*/