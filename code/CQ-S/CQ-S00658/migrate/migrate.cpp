#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 2000000;
int readint() {
    int x = 0; char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x;
}
ll readll() {
    ll x = 0; char ch = getchar();
    bool flag = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-') flag = 1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1ll) + (x << 3ll) + (ch ^ 48);
        ch = getchar();
    }
    return (flag ? -x:x);
}
int n;
ll d;
ll x[MAXN + 5];
int to[MAXN + 5];
ll f[MAXN + 5], g[MAXN + 5], t[MAXN + 5], tt[MAXN + 5];
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    int c, T; scanf("%d%d", &c, &T);
    while (T--) {
        scanf("%d%lld", &n, &d);
        for (int i = 0; i <= n + 3; ++i) {
            f[i] = g[i] = t[i] = tt[i] = to[i] = x[i] = 0;;
        }
        for (int i = 1; i <= n; ++i)
            x[i] = readll();
        for (int l = 1, r = 1; l <= n; ++l) {
            while (r < n && x[r + 1] - x[l] <= d) r++;
            to[l] = r;
        }
        for (int i = 3, l = 1, r = 0; i <= n; ++i) {
            l = max(l, i + 1);
            while (r < n&& x[r + 1] <= x[i - 1] + d) r++;
            while (l <= n && x[l] < x[i - 2] + d + 1) l++;

            t[i] = r - l + 1;
        }
        for (int i = 1, l = 1, r = 0; i <= n; ++i) {
            l = max(l, i + 1);
            while (r < n&&r + 1 < to[i] && x[r + 1] <= x[i] + d) r++;
            if (i != 1)
            while (l <= n && x[l] < x[i - 1] + d + 1) l++;
            tt[i] = max(0, r - l + 1);
        }
        for (int i = 1; i <= n; ++i) {
            if (to[i] == to[i - 1]) {
                f[i] = 1;
                f[to[i]]++;
                continue;
            }
            f[i]++;
            f[to[i]] += f[i];
        }
        for (int i = n; i >= 1; --i) {
            if (to[i]== i) {
                g[i] = 1;
                continue;
            }
            if (to[i] == to[i - 1]) g[i] = 1;
            else {
                if (to[to[i]] == to[to[i] - 1]) g[i] = 1 + 1 + tt[i];
                else g[i] = g[to[i]] + 1 + tt[i];
            }
        }
        ll ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (to[i] >= i + 2 && to[to[i]] != to[i] && to[to[i]] == to[to[i] - 1] && to[to[i]] != to[to[i] - 2]) {
                ans += (f[i] - ((to[i - 1] >= to[i] - 1) ? max(0ll, (f[i] - 1)) : 0)) * max(0ll, (g[to[to[i]]] - 1));
                // cout<<i<<' '<<f[i]<<' '<<(g[to[to[i]]] - 1)<<endl;
            }
            if (to[i] >= i + 2) {
                ans += (f[i] - ((to[i - 1] >= to[i] - 1) ? max(0ll, (f[i] - 1)) : 0)) * t[to[i]];
                // cout<<i<<' '<<(f[i])<<' '<<t[to[i]]<<endl;
            }
        }

        printf("%lld\n", ans);
    }
    return 0;
}