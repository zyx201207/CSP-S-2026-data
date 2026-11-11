#include <iostream>

typedef long long ll;

int c, n, t, fl[2000000], fr[2000000], ml[2000000], mr[2000000], sl[2000000], sr[2000000];
ll d, ans, x[2000000];

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> c >> t;
    while (t--) {
        std::cin >> n >> d;
        for (int i = 0; i < n; ++i) ml[i] = mr[i] = 0;
        for (int i = 0, l = 0; i < n; ++i) {
            std::cin >> x[i];
            while (x[i] - x[l] > d) ++l;
            fl[i] = l;
        }
        for (int l = n - 1, r = n - 1; l >= 0; --l) {
            while (x[r] - x[l] > d) --r;
            fr[l] = r;
        }
        for (int i = 0; i < n; ++i) ml[i] = mr[i] = 1;
        for (int i = n - 1; i >= 0; --i) if (fr[i] > i && fl[fr[i]] == i) mr[i] += mr[fr[i]];
        for (int i = 0; i < n; ++i) if (fl[i] < i && fr[fl[i]] == i) ml[i] += ml[fl[i]];
        for (int i = 0; i < n; ++i) {
            ++ml[i], ++mr[i];
            if (i) ml[i] += ml[i - 1], mr[i] += mr[i - 1];
        }
        ans = 0;
        for (int i = 1; i + 2 < n; ++i) ans += (ll)(mr[fr[i]] - mr[fr[i - 1]]) * ((fl[i + 2] ? ml[fl[i + 2] - 1] : 0) - (fl[i + 1] ? ml[fl[i + 1] - 1] : 0));
        std::cout << ans << '\n';
    }
    return 0;
}