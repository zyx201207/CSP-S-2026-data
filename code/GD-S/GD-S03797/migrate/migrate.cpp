#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int N = 2e6 + 10;
int T, n, d, a[N], L[N], R[N], f[N], g[N];
int tor(int x) {
    return upper_bound(a + 1, a + n + 1, x + d) - a - 1;
}
void work(int *f, int *R) {
    for (int i = n; i; i--) {
        int r = R[i] = tor(a[i]);
        f[i] = r - i + f[r];
        int rr = R[r];
        if (i < r and r < rr) {
            int x = upper_bound(a + r, a + rr + 1, a[r - 1] + d) - a;
            if (x > rr)
                f[i] = r - i;
            else
                f[i] -= x - r - 1;
        }
    }
}
void clear() {
    for (int i = 1; i <= n; i++)
        f[i] = g[i] = L[i] = R[i] = 0;
}
int getpos(int l, int r, int x) {
    int ret = 0;
    l--;
    while (l + 1 < r) {
        int mid = l + r >> 1;
        if (a[mid] + d >= x)
            r = mid;
        else
            l = mid;
    }
    if (a[r] + d >= x)
        r--;
    return r;
}
void solve() {
    clear();
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    work(f, R);
    reverse(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        a[i] = -a[i];
    work(g, L);
    reverse(a + 1, a + n + 1);
    reverse(g + 1, g + n + 1);
    reverse(L + 1, L + n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = -a[i];
        L[i] = n - L[i] + 1;
    }
    int ans = 0;
    for (int i = 2, j = 3; j < n; i++, j++) {
        if (R[i] <= j or L[j] >= i)
            continue;
        int ff = f[j], gg = g[i];
        int l = i - 1, r = j + 1;
        int x = upper_bound(a + j, a + R[j] + 1, a[l] + d) - a;
        if (x > R[j])
            continue;
        ff -= x - j - 1;
        if (R[i] != R[j])
            ff = min(R[i], R[j]) - x + 1;
        x = getpos(L[i], i, a[r]);
        if (x < L[i])
            continue;
        gg -= i - x - 1;
        if (L[i] != L[j])
            gg = x - max(L[i], L[j]) + 1;
        ans += ff * gg;
    }
    cout << ans << "\n";
}
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    IOS;
    cin >> T >> T;
    while (T--)
        solve();
    return 0;
}