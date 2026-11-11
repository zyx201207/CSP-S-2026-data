#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 5;
int t, n, d, ncnt[N], x[N], l[N], r[N], L[N], R[N];
int fl[N], fr[N], numl[N], numr[N], ans;
int calcl(int x) {
    int now = l[x], ans = 0;
    if (now == x) return 0;
    if (r[now] == x + 1) ans = L[now];
    int nl = max(now, fr[x + 1]),
    nr = min(x - 1, fr[x + 2] - 1);
    if (nl <= nr) ans += nr - nl + 1;
    return ans;
}
int calcr(int x) {
    int now = r[x + 1], ans = 0;
    if (now == x) return 0;
    if (l[now] == x) ans = R[now];
    int nl = max(x + 2, fl[x]),
    nr = min(now, fl[x + 1] - 1);
    if (nl <= nr) ans += nr - nl + 1;
    return ans;
}
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t >> t;
    while (t--) {
        cin >> n >> d, ans = 0;
        for (int i = 1; i <= n; i++) cin >> x[i];
        l[1] = 1, r[n] = n;
        for (int i = 2; i <= n; i++) {
            l[i] = l[i - 1];
            while (x[i] - x[l[i]] > d) l[i]++;
        }
        for (int i = n - 1; i >= 1; i--) {
            r[i] = r[i + 1];
            while (x[r[i]] - x[i] > d) r[i]--;
        }
        fr[n + 1] = fl[n + 1] = n + 1;
        for (int i = 1; i <= n; i++) {
            fl[i] = fl[i - 1], fr[i] = fr[i - 1];
            while (fl[i] <= n && l[fl[i]] < i) fl[i]++;
            while (fr[i] <= n && r[fr[i]] < i) fr[i]++;
        }
        for (int i = 1; i <= n; i++) {
            int nl = max(i + 1, fl[i]),
            nr = min(r[i], fl[i + 1] - 1);
            numr[i] = max(nr - nl + 1, 0ll);
            nl = max(l[i], fr[i]),
            nr = min(i - 1, fr[i + 1] - 1);
            numl[i] = max(nr - nl + 1, 0ll);
        }
        for (int i = 1; i <= n; i++) {
            if (l[i] != i && r[l[i]] == i)
                L[i] = L[l[i]] + numl[i];
            else L[i] = numl[i];
        }
        for (int i = n; i >= 1; i--) {
            if (r[i] != i && l[r[i]] == i)
                R[i] = R[r[i]] + numr[i];
            else R[i] = numr[i];
        }
        for (int i = 1; i < n; i++) ans += calcl(i) * calcr(i);
        cout << ans << '\n';
    }
    return 0;
}
