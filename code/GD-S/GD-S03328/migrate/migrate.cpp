#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1 << 30;
const ll INF = 1ll << 60;

const int N = 2e6 + 3;

ll a[N];

int l[N], r[N], f[2][N];

bool b[N];

void solve () {
    int n;
    ll d;
    scanf ("%d%lld", &n, &d);
    for (int i = 1; i <= n; i++) scanf ("%lld", &a[i]);
    for (int i = 1; i <= n; i++) {
        int L = 0, R = i;
        while (L + 1 < R) {
            int M = (L + R) / 2;
            if (a[M] >= a[i] - d) R = M;
            else L = M;
        }
        l[i] = R;
        L = i; R = n + 1;
        while (L + 1 < R) {
            int M = (L + R) / 2;
            if (a[M] <= a[i] + d) L = M;
            else R = M;
        }
        r[i] = L;
    }
    for (int i = 1; i <= n; i++) b[i] = 0;
    for (int i = 1; i <= n; i++) if (r[i] > i && l[r[i]] == i - 1) b[i] = 1;
    for (int i = 1; i <= n; i++) f[0][i] = f[1][i] = 0;
    for (int i = 1; i <= n; i++) if (r[i] > i) f[0][r[i]]++;
    for (int i = 1; i <= n; i++) if (r[i] > i) {
        if (!b[i]) {
            f[0][r[i]] += f[0][i];
            f[1][r[i]] += f[1][i];
        }
        else f[1][r[i]] += f[0][i];
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) ans += 1ll * f[1][i];
    for (int i = 1; i <= n; i++) if (r[i] > i) {
        int L = i, R = r[i];
        while (L + 1 < R) {
            int M = (L + R) / 2;
            if (l[M] >= i) R = M;
            else L = M;
        }
        --R;
        while (R > i && l[R] == i - 1) {
            ans += 1ll * f[0][i];
            --R;
        }
    }
    printf("%lld\n", ans);
}

int main () {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    scanf ("%d%d", &c, &t);
    for (; t--; ) solve();
}