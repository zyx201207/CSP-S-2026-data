#include <cstdio>
#include <algorithm>
using namespace std;
namespace pnl{
    typedef long long lnt;
    constexpr lnt N = 2000100;
    lnt tid, tct, n, m, ans;
    lnt a[N], lst[N], nxt[N], f[N], g[N];
    inline int _01() {
        scanf("%lld%lld", &n, &m);
        ans = 0;
        for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
        a[0] = a[1] - m - 1;
        a[n + 1] = a[n] + m + 1;
        for (int i = 1, j = 1; i <= n + 1; ++i) {
            for (; a[i] - a[j] > m; ++j);
            lst[i] = j; 
        }

        for (int i = n, j = n; i >= 0; --i) {
            for (; a[j] - a[i] > m; --j);
            nxt[i] = j;
        }

        for (int i = 1; i <= n; ++i) {
            int j = lst[i];
            int k = lst[i + 1];
            if (i == j || j == k) {
                f[i] = 0;
                continue;
            }

            f[i] = f[j] + k - j;
        }

        for (int i = n; i >= 1; --i) {
            int j = nxt[i];
            int k = nxt[i - 1];
            if (i == j || j == k) {
                g[i] = 0;
                continue;
            }

            g[i] = g[j] + j - k;
        }

        for (int i = 1; i <= n - 1; ++i) {
            if (lst[i + 1] < i && nxt[i] > i + 1 && lst[i + 1] < lst[i + 2] && nxt[i] > nxt[i - 1]) {
                lnt t1p = min(lst[i + 2], (lnt)i);
                lnt t2p = max(nxt[i - 1], (lnt)i + 1);
                if (lst[i] == lst[i + 1] && nxt[i] == nxt[i + 1]) {
                    ans += (f[lst[i + 1]] + t1p - lst[i + 1]) * (g[nxt[i]] + nxt[i] - t2p);
                } else if (lst[i] == lst[i + 1]) {
                    ans += (f[lst[i + 1]] + t1p - lst[i + 1]) * (nxt[i] - t2p);
                } else if (nxt[i] == nxt[i + 1]) {
                    ans += (t1p - lst[i + 1]) * (g[nxt[i]] + nxt[i] - t2p);
                } else {
                    ans += (t1p - lst[i + 1]) * (nxt[i] - t2p);
                }
            }
        }

        printf("%lld\n", ans);
        return 0;
    }

    inline int _00() {
        scanf("%lld%lld", &tid, &tct);
        for (int i = 1; i <= tct; ++i) {
            int res = _01();
        }

        return 0;
    }
}

int main() {
    // Audaces fortuna iuvat
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    return pnl::_00();
}