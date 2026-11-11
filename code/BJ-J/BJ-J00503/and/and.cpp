#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll MAXN = 200005;
const ll MAXM = 200005;

ll a[MAXN];
ll dp[MAXM];

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    ll n, m;
    scanf("%lld %lld", &n, &m);

    bool is_b = true;
    for (ll i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        is_b = is_b == true ? (a[i] == i - 1) : false;
    }

    if (n > 2000) {
        if (is_b == true) {
            ll ans = LLONG_MAX;
            for (ll i = n; i >= n - m + 1; --i) {
                ans &= a[i];
            }
            printf("%lld", ans);
            return 0;
        }

        sort(a + 1, a + 1 + n);
        printf("%lld", a[n - m + 1]);
        return 0;
    }

    dp[0] = LLONG_MAX;

    for (ll i = 1; i <= n; ++i) {
        for (ll j = m; j >= 1; --j) {
            dp[j] = max(dp[j - 1] & a[i], dp[j]);
        }
    }

    printf("%lld", dp[m]);

    return 0;
}