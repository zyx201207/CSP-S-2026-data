#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e6 + 10;

ll n, d, a[N], l[N], r[N], mn[N];
ll sum[N], f[N], g[N];

ll getA(int l, int r) {
    if (l > r) return 0;
    return sum[r] - sum[l - 1];
}

void solve() {
    cin >> n >> d;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    
    for (int i = 1, j = 1; i <= n; i ++ ) {
        while (a[i] - a[j] > d) j ++;
        l[i] = j; if (!mn[j]) mn[j] = i;
    }
    for (int i = n, j = n; i; i -- ) {
        while (a[j] - a[i] > d) j --;
        r[i] = j;
    }

    ll ans = 0;

    for (int i = 0; i <= n; i ++ ) mn[i] = 0;

    for (int i = 1; i <= n; i ++ ) {
        f[i] = 0, g[i] = 1, mn[0] = i, sum[i] = 1;
        for (int j = i + 1; j <= n; j ++ ) {
            if (l[j] == j) continue;
            int p = max(l[j], (ll)i);
            f[j] = f[p] + 1, sum[j] = sum[j - 1];
            if (!mn[f[j]]) mn[f[j]] = j;
            g[j] = getA(max(p, i), mn[f[j]] - 1);
            if (g[j] == 2) ans ++;
            sum[j] = sum[j - 1] + g[j];
        }
        for (int j = 0; j <= n; j ++ ) mn[j] = f[j] = g[j] = sum[j] = 0;
        
    }

    cout << ans << '\n';

    for (int i = 1; i <= n; i ++ ) f[i] = g[i] = l[i] = r[i] = sum[i] = a[i] = mn[i] = 0;
}

int main() {

    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    int c, T; cin >> c >> T;
    while (T -- ) solve();

    return 0;
}