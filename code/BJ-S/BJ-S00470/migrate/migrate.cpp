#include <climits>
#include <cstdio>
#include <utility>
#include <map>

using namespace std;

typedef long long ll;

const ll MAXN = 2000005;

ll n, d;
ll x[MAXN];
map<pair<ll, ll>, ll> dp;

ll dfs(ll start, ll end) {
    if (dp[{start, end}] != 0) {
        return dp[{start, end}];
    }

    if (start > end) {
        return 0;
    }

    if (start == end || x[end] - x[start] <= d) {
        return dp[{start, end}] = 1;
    }

    ll ans = 0;
    for (ll i = start + 1; i < end; ++i) {
        if (x[i] - x[start] <= d) {
            ans += dfs(i, end);
        }
    }
    return dp[{start, end}] = ans;
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    ll c, t;
    scanf("%lld %lld", &c, &t);

    while (t--) {
        scanf("%lld %lld", &n, &d);

        for (ll i = 1; i <= n; ++i) {
            scanf("%lld", &x[i]);
        }

        ll ans = 0;

        for (ll i = 1; i <= n; ++i) {
            for (ll j = i + 3; j <= n; ++j) {
                dp.clear();
                if (dfs(i, j) == 2) {
                    ++ans;
                }
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}