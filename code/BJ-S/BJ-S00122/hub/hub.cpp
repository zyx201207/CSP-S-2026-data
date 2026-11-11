#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
namespace pnl{
    typedef long long lnt;
    constexpr lnt N = 1000100;
    lnt tid, tct, n, m, ans;
    lnt vis[N], dis[N], fat[N];
    vector<int> edg[N];
    inline int fnd(int __x) {
        if (fat[__x] == __x) return __x;
        return fat[__x] = fnd(fat[__x]);
    }

    inline int _01() {
        scanf("%lld%lld", &n, &m);
        ans = n;
        for (int i = 1; i <= n; ++i) {
            edg[i].clear();
        }

        for (int i = 1; i <= n - 1; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            edg[x].push_back(y);
            edg[y].push_back(x);
        }

        if (n <= 20) {
            for (int i = 1; i < 1 << n; ++i) if (__builtin_popcount(i) == m) {
                queue<int> q;
                for (int j = 1; j <= n; ++j) vis[j] = 0;
                for (int j = 0; j < n; ++j) if (i >> j & 1) {
                    vis[j + 1] = 1;
                    dis[j + 1] = 0;
                    q.push(j + 1);
                }

                for (int j = 1; j <= n; ++j) fat[j] = j;
                for (int j = 1; j <= n; ++j) if (vis[j]) for (int k : edg[j]) if (vis[k]) fat[fnd(j)] = fnd(k);
                int cnt = 0;
                for (int j = 1; j <= n; ++j) if (vis[j] && fat[j] == j) ++cnt;
                if (cnt > 2) continue;
                while (q.size()) {
                    int x = q.front();
                    q.pop();
                    for (int y : edg[x]) if (!vis[y]) {
                        vis[y] = 1;
                        dis[y] = dis[x] + 1;
                        q.push(y);
                    }
                }

                dis[0] = 0;
                for (int j = 1; j <= n; ++j) dis[0] = max(dis[0], dis[j]);
                ans = min(ans, dis[0]);
            }

            printf("%lld\n", ans);
        } else {
            if (n == m) ans = 0;
            else {
                n = n >> 1;
                if (n <= m) ans = 1;
                else ans = (n - m + 3) / 4 + 1; 
            }

            printf("%lld\n", ans);
        }

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
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    return pnl::_00();
}