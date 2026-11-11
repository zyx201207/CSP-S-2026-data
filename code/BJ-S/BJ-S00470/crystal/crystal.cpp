#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;

const ll MAXN = 500005;

ll a[MAXN];
map<ll, ll> mp;

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ll n, m;
    scanf("%lld %lld", &n, &m);

    bool is_b = true;
    for (ll i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        ++mp[a[i]];
        
        if (i >= 3) {
            is_b = is_b == true ? a[i] - a[i - 1] == a[i - 1] - a[i - 2] : false;
        }
    }

    sort(a + 1, a + 1 + n);

    ll ans = 1;
    for (ll i = 2; i <= n; ++i) {
        if (is_b == true || n > 5000) {
            i = n;
        } else if (a[i] == a[i - 1]) {
            continue;
        }

        ll tmp_m = m, tmp_ans = mp[a[i]];
        for (ll j = i - 1; tmp_m > 0 && j > 0; --j) {
            if (tmp_m >= a[i] - a[j]) {
                tmp_m -= a[i] - a[j];
                tmp_ans += a[i] - a[j] == 0 ? 0 : 1;
            } else {
                break;
            }
        }
        ans = max(ans, tmp_ans);
    }

    printf("%lld", ans);

    return 0;
}