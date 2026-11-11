#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e5 + 5;

bool MBE;

int n, m;
int a[N];
int sum[N];

bool MED;

signed main() {
    freopen("crystal.in", "r", stdin), freopen("crystal.out", "w", stdout);
    // freopen("test.in", "r", stdin), freopen("test.out", "w", stdout);
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++ i) sum[i] = sum[i - 1] + a[i];
    int ans = 1;
    for (int i = 2; i <= n; ++ i) {
        int l = 1, r = i, pos = i;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if ((i - mid + 1) * a[i] - (sum[i] - sum[mid - 1]) <= m) {
                pos = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        ans = max(ans, i - pos + 1);
    }
    cout << ans << "\n";

    // cerr << "Time: " << 1e3 * clock() / CLOCKS_PER_SEC << "ms\n";
    // cerr << "Memory: " << (&MED - &MBE) / 1024.0 / 1024.0 << "MB\n";
    return 0;
}