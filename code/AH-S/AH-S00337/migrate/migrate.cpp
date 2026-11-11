#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 66;
int c, T, n, d, a[N], l[N], t[N];
vector<int> to[N];
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> c >> T;
    while (T--) {
        cin >> n >> d;
        for (int i = 1; i <= n; i++)
            cin >> a[i], to[i].clear();
        if (c == 13 || c == 14) {
            int pos = 0;
            for (int i = 1; i <= n; i++) {
                if (a[i] - a[1] <= d && a[n] - a[i] <= d) {
                    pos = i;
                    break;
                }
            }
            int sum = 0;
            for (int i = 1; i < pos; i++) {
                if (a[n] - a[i] <= d) break;
                int L = pos + 1, R = n, s = 0, e = 0;
                while (L <= R) {
                    int mid = (L + R) / 2;
                    if (a[mid] - a[i] <= d) {
                        s = mid;
                        L = mid + 1;
                    } else R = mid - 1;
                }
                L = i, R = pos - 1;
                while (L <= R) {
                    int mid = (L + R) / 2;
                    if (a[s + 1] - a[mid] <= d) {
                        e = mid;
                        R = mid - 1;
                    } else L = mid + 1;
                }
                int len = s - e + 1;
                if (len == 2) sum++;
            }
            cout << sum << "\n";
            continue;
        }
        if (c == 11 || c == 12) {
            int x = a[2] - a[1];
            int k = d / x;
            if (k <= 1) {
                cout << "0\n";
                continue;
            }
            int sum = 0;
            for (int i = 1; i <= n; i++) {
                if (i + k * 2 - 1 <= n) sum++;
            }
            cout << sum << "\n";
            continue;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (a[j] - a[i] > d) break;
                to[i].push_back(j);
            }
        }
        int ans = 0;
        for (int p = 1; p <= n; p++) {
            for (int i = p; i <= n; i++) l[i] = 1e18, t[i] = 0;
            l[p] = 0, t[p] = 1;
            for (int i = p; i <= n; i++) {
                for (auto j : to[i]) {
                    int len = l[i] + 1;
                    if (l[j] > len) {
                        l[j] = len;
                        t[j] = t[i];
                    } else if (l[j] == len) {
                        t[j] += t[i];
                    }
                }
            }
            for (int i = p + 1; i <= n; i++)
                if (t[i] == 2) ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}
