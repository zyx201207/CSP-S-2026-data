#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <array>

namespace {
    typedef long long lnt;

    const int inf = 0x3f3f3f3f;

    // const int _max_n = 4;
    // const int max_n = 1 << _max_n;
    

} // 没结果啊

namespace NORMAL {
    const int max_n = 5010;

    lnt d, a[max_n];
    int n, f[max_n], scnt[max_n], ls[max_n], rt[max_n];

    void solve() {
        std::cin >> n >> d;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }

        for (int i = 1; i <= n; ++i) {
            for (int e = i; e >= 1; --e) {
                if (a[i] - a[e] <= d) ls[i] = e;
            }
        }

        int ans = 0;

        for (int i = 1; i <= n - 1; ++i) {
            std::memset(f, 0, sizeof(f));
            std::memset(scnt, 0, sizeof(scnt));
            std::memset(rt, 0, sizeof(rt));
            f[i] = 0, scnt[i - 1] = 0, scnt[i] = 1, rt[0] = i;
            for (int e = i + 1; e <= n; ++e) {
                int lf = std::max(i, ls[e]);
                if (lf == e) break;

                f[e] = f[lf] + 1;
                rt[f[e]] = e;
                
                int flag = 1, cnt = scnt[rt[f[lf]]] - scnt[lf - 1];

                if (cnt == 2) ++ans;
            
                scnt[e] = scnt[e - 1] + cnt;
            }
        }

        std::printf("%d\n", ans);

    }
}

namespace PRA {
    int n, len;
    lnt a, b, d, ans;

    void solve() {
        std::cin >> n >> d;
        if (n == 1) {
            std::cin >> a; return;
        }

        std::cin >> a >> b;
        lnt x;
        for (int i = 1; i <= n - 2; ++i) std::cin >> x;
        
        len = std::min(lnt(n), d / (b - a));
        
        ans = 0;
        if (len >= 2) {
	    	ans = std::max(0ll, lnt(n) - 2 * (len - 1) - 1);
		}
        std::printf("%lld\n", ans);
    }
}

int main() {
    std::freopen("migrate.in", "r", stdin);
    std::freopen("migrate.out", "w", stdout);

    std::cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1, c; std::cin >> c >> T;
    for (int i = 0; i < T; ++i) {
        if (c <= 10) NORMAL::solve();
        else if (c <= 12) PRA::solve();
    }

    return 0;
}