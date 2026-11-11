#include <bits/stdc++.h>
#define fi first
#define se second
typedef long long ll;
typedef double db;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;
typedef __int128 LL;
typedef unsigned long long ull;

ll a[200200];

int main() {
    #ifndef LOCAL
        freopen("and.in", "r", stdin);
        freopen("and.out", "w", stdout);
    #endif
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    ll n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    ll mask = 0;
    for (ll i = 30; i >= 0; i--) {
        ll cnt = 0;
        for (ll j = 1; j <= n; j++) {
            if ((a[j] & (mask + (1 << i))) == (mask + (1 << i))) {
                cnt++;
            }
        }
        if (cnt >= m) {
            mask += (1 << i);
        }
    }
    std::cout << mask;
    return 0;
}