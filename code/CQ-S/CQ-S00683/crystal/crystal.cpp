#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 10;

int n;
ll m, a[MAXN];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    ll miku = 0, st = 1, ans = 1;
    for (int i = 2; i <= n; i++) {
        // add i
        miku += 1ll * (i - st) * (a[i] - a[i - 1]);
        while (miku > m) {
            miku -= (a[i] - a[st++]);
        }
        ans = max(ans, i - st + 1);
    }
    cout << ans << "\n";
    return 0;
}