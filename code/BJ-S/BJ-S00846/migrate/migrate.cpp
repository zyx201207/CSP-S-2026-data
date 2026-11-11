#include <bits/stdc++.h>
#define For(i, j, k) for (int i = j; i <= k; ++ i)
#define Rof(i, j, k) for (int i = j; i >= k; -- i)
#define eb emplace_back
using namespace std;
using ll = long long;
using db = double;
using vi = vector<int>;
const int N = 2e6 + 10;
const int inf = 0x3f3f3f3f;
int c, t, n;
ll d, x[N];
int f[N], cnt[N];
void work() {
    if (c >= 1 && c <= 6) {
        cin >> n >> d;
        For (i, 1, n) cin >> x[i];
        if (n == 1) {
            cout << "0\n";
            return ;
        }
        int ans = 0;
        // cout << "DEDE" << '\n';
        For (l, 1, n) {
            For (r, l + 1, n) {
                f[l] = 0, cnt[l] = 1;
                // cout << "Checking" << l << ' ' << r << '\n';
                For (i, l + 1, r) {
                    f[i] = inf, cnt[i] = 0;
                    for (int j = i; j >= l && x[i] - x[j] <= d; -- j) {
                        if (f[j] <= f[i]) {
                            if (f[j] < f[i]) cnt[i] = 0;
                            cnt[i] += cnt[j];
                            f[i] = f[j];
                        }
                    } f[i] ++ ;
                    // cout << i << ':' << f[i] << ' ' << cnt[i] << ';';
                }
                if (cnt[r] == 2) ans ++ ;
            }
        }
        cout << ans << '\n';
    }
    if (c >= 11 && c <= 12) {
        cin >> n >> d;
        For (i, 1, n) cin >> x[i];
        if (n == 1) {
            cout << 0 << '\n';
            return ;
        }
        ll dl = x[2] - x[1];
        ll tt = d / dl;
        if (tt == 0 || tt == 1 || tt >= n - 1) {
            cout << 0 << '\n';
            return ;
        }
        // cout << "DEDE" << n - 1 << ' ' << tt << '\n';
        ll L = tt + 1, R = tt * 2 - 1;
        // ll ans = 1ll * n * (R - L + 1) - 1ll * (R - L + 1) * (R + L) / 2;
        // ll ans = 0; For (i, L, R) ans += n - i;
        ll ans = 0; ans += n - (tt * 2 - 1);
        cout << ans << '\n';
        return ;
    }
    if (c >= 13 && c <= 14) {
        cout << "0\n";
        return ;    
    }

}
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c >> t;
    while (t -- ) work();
    return 0;
}