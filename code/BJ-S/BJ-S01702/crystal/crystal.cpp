#include <bits/stdc++.h>
#define fi first
#define se second
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef __int128 LL;
typedef unsigned long long ull;

ll a[500500];

int main() {
    #ifndef LOCAL
        freopen("crystal.in", "r", stdin);
        freopen("crystal.out", "w", stdout);
    #endif
    ll n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    std::sort(a + 1, a + n + 1);
    if (n <= 5000) {
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            ll cnt = 1, sum = 0;
            int j1, j2;
            for (j1 = i, j2 = i; j1 > 1 || j2 < n;) {
                ll ncost1 = m + 1;
                if (j1 > 1) {
                    ncost1 = std::abs(a[j1 - 1] - a[i]);
                }
                ll ncost2 = m + 1;
                if (j2 < n) {
                    ncost2 = std::abs(a[j2 + 1] - a[i]);
                }
                if (ncost1 < ncost2) {
                    if (ncost1 + sum <= m) {
                        sum += ncost1;
                        j1--;
                        cnt++;
                    }
                    else {
                        break;
                    }
                }
                else {
                    if (ncost2 + sum <= m) {
                        sum += ncost2;
                        j2++;
                        cnt++;
                    }
                    else {
                        break;
                    }
                }
                // std::cout << j1 << ' ' << j2 << '\n';
            }
            ans = std::max(ans, cnt);
        }
        std::cout << ans;
        return 0;
    }
    else {
        ll d = a[2] - a[1];
        ll l = 0, r = 1e12;
        while (l + 1 < r) {
            ll mid = (l + r) >> 1;
            ll t = mid / 2;
            ll s = (t + 1) * t;
            if (mid % 2) {
                s += mid / 2 + 1;
            }
            if (s > m) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        std::cout << l;
    }
    return 0;
}