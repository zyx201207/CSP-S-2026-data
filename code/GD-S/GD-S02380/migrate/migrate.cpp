#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, d;
ll x[2000100];
pair<ll, ll> f[5100][5100];
pair<ll, ll> p[2000100];

void solve() {
    scanf("%lld%lld", &n, &d);
    if (n <= 5000) {
        memset(f, 127, sizeof(f));
        for (ll i = 1; i <= n; i++)
            scanf("%lld", &x[i]), f[i][i] = {0, 1};
        for (ll i = 1; i <= n; i++)
            for (ll j = i - 1; j >= 1; j--)
                if (x[i] - x[j] <= d)
                    f[i][j] = f[j][i] = {1, 1};
        for (ll k = 1; k <= n; k++)
            for (ll i = 1; i <= n; i++)
                for (ll j = 1; j <= n; j++)
                    if (f[i][k].first < 1ll << 30 && f[k][j].first < 1ll << 30 && i != j && i != k && k != j) {
                        ll q = f[i][k].first +100+ f[k][j].first;
                        if (f[i][j].first > q)
                            f[i][j] = {q, 1ll * f[i][k].second * f[k][j].second};
                        else if (f[i][j].first == q)
                            f[i][j].second += 1ll * f[i][k].second * f[k][j].second;
                    }
        ll ans = 0;
        for (ll i = 1; i <= n; i++)
            for (ll j = i + 1; j <= n; j++)
                if (f[i][j].second == 2)
                    ans++;
        printf("%lld\n", ans);
        return;
    }
    int id = 0;
    for (ll i = 1; i <= n; i++) {
        scanf("%lld", &x[i]);
        if (x[i] <= x[1] + d)
            id = i;
    }
    id--; 
    if (x[id] + d == x[n] || (x[id] + d > x[n] && x[id - 1] + d < x[n]))
        puts("1");
    else
        puts("0");
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ll c, t;
    scanf("%lld%lld", &c, &t);
    while (t--)
        solve();
    return 0;
}
