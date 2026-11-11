#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
char c[N];
int n, a[N];
long long l[N], r[N];

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i] >> c[i];
    l[1] = 1, r[1] = a[1];
    for (int i = 2; i <= n; i++) l[i] = l[i - 1] + a[i - 1], r[i] = r[i - 1] + a[i];
    long long mid = 0;
    for (int i = 1; i <= n; i++) mid += a[i];
    mid >>= 1;
    long long ans = 0;
    for (long long i = l[1], j = r[n]; i <= mid && j > mid; ) {
        int p = lower_bound(r + 1, r + n + 1, i) - r, q = upper_bound(l + 1, l + n + 1, j) - l - 1;
        long long x = min(r[p], mid) - i + 1, y = j - max(l[q], mid) + 1;
        if (c[p] != c[q]) ans += min(x, y);
        i += min(x, y), j -= min(x, y);
    }
    return cout << ans, 0;
}