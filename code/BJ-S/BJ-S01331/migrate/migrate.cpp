#include <bits/stdc++.h>
using namespace std;

const int N = int(2e6) + 10;

long long a[N], d;
int nxt[N], prv[N], bg[N], ed[N], valr[N], vall[N];

long long Range(int x, int y) {
    nxt[y] = y;
    bg[y] = 0;
    for (int i = x, j = x; i < y; i++) {
        while (j + 1 <= y && a[j + 1] <= a[i] + d) j++;
        nxt[i] = j;
        // cout << i << ' ' << nxt[i] << '\n';
    }
    prv[x] = x;
    ed[x] = 0;
    for (int i = x + 1, j = x; i <= y; i++) {
        while (j < i && a[j] < a[i] - d) j++;
        prv[i] = j;
        // cout << i << ' ' << prv[i] << '\n';
    }
    for (int i = y - 1; i >= x; i--) {
        valr[i] = upper_bound(prv + i + 1, prv + nxt[i] + 1, i) - lower_bound(prv + i + 1, prv + nxt[i] + 1, i);
        bg[i] = valr[i] + (prv[nxt[i]] == i) * bg[nxt[i]];
    }
    for (int i = x + 1; i <= y; i++) {
        vall[i] = upper_bound(nxt + prv[i], nxt + i, i) - lower_bound(nxt + prv[i], nxt + i, i);
        ed[i] = vall[i] + (nxt[prv[i]] == i) * ed[prv[i]];
    }
    // for (int i = x; i <= y - 1; i++) bg[i] += nxt[i] - i - valr[i];
    // for (int i = x + 1; i <= y; i++) ed[i] += i - prv[i] - vall[i];
    long long res = 0;
    for (int i = x + 1; i < y; i++) if (prv[i - 1] == prv[i] && nxt[i] == nxt[i - 1] && prv[nxt[i]] == i - 1 && nxt[prv[i]] == i)
        res += 1ll * bg[nxt[i]] * ed[prv[i]];
    // cout << res << '\n';
    for (int i = x + 1; i < y; i++) if (prv[i - 1] == prv[i] && nxt[prv[i]] == i) {
        int num = upper_bound(prv + i + 1, prv + nxt[i] + 1, i - 1) - lower_bound(prv + i + 1, prv + nxt[i] + 1, i - 1);
        res += 1ll * ed[prv[i]] * num;
        // cout << i << ' ' << num << '\n';
    }
    for (int i = x + 1; i < y; i++) if (nxt[i - 1] == nxt[i] && prv[nxt[i]] == i - 1) {
        int num = upper_bound(nxt + prv[i], nxt + i - 1, i) - lower_bound(nxt + prv[i], nxt + i - 1, i);
        // cout << i << ' ' << num << '\n';
        res += 1ll * bg[nxt[i]] * num;
    }
    for (int i = x + 1; i < y; i++) {
        int num = upper_bound(prv + i + 1, prv + nxt[i] + 1, i - 1) - lower_bound(prv + i + 1, prv + nxt[i] + 1, i - 1);
        int num2 = upper_bound(nxt + prv[i], nxt + i - 1, i) - lower_bound(nxt + prv[i], nxt + i - 1, i);
        res += 1ll * num * num2;
        // cout << i << ' ' << num << '\n';
    }
    // cout << res << '\n';
    return res;
}
void Solve() {
    int n;
    cin >> n >> d;
    long long res = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int l = 1;
    for (int i = 1; i < n; i++) {
        if (a[i + 1] > a[i] + d) {
            res += Range(l, i);
            l = i + 1;
        }
    }
    cout << res + Range(l, n) << '\n';
}
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c, t;
    cin >> c >> t;
    while (t--) Solve();

    return 0;
}