#include <cstdio>
#include <algorithm>
using namespace std;
namespace pnl{
    typedef long long lnt;
    constexpr lnt N = 500100;
    lnt n, m, ans = 1;
    lnt a[N];
    inline int _00() {
        scanf("%lld%lld", &n, &m);
        for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
        sort(a + 1, a + n + 1);
        lnt tmp = 0;
        for (int i = 2, j = 1; i <= n; ++i) {
            tmp += (a[i] - a[i - 1]) * (i - j);
            while (tmp > m) {
                tmp -= a[i] - a[j];
                ++j;
            }

            ans = max(ans, (lnt)i - j + 1);
        }

        printf("%lld\n", ans);
        return 0;
    }
}

int main() {
    // Audaces fortuna iuvat
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    return pnl::_00();
}