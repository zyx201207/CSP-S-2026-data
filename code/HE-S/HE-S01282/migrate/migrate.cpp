#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e6 + 5;

bool MBE;

int n, d;
int x[N];
int l[N], r[N];

bool MED;

namespace SUB1 {
    int t[N], sum[N];

    inline void Main() {
        cin >> n >> d;
        for (int i = 1; i <= n; ++ i) cin >> x[i];
        for (int i = 1; i <= n; ++ i) {
            int L = i, R = n;
            while (L <= R) {
                int mid = (L + R) >> 1;
                if (x[mid] - x[i] <= d) {
                    r[i] = mid;
                    L = mid + 1;
                } else R = mid - 1;
            }
            L = 1, R = i;
            while (L <= R) {
                int mid = (L + R) >> 1;
                if (x[i] - x[mid] <= d) {
                    l[i] = mid;
                    R = mid - 1;
                } else L = mid + 1;
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; ++ i) {
            for (int j = 1; j <= n; ++ j) {
                t[j] = sum[j] = 0;
            }
            int now = i;
            sum[i] = 1;
            while (now != n) {
                if (x[now + 1] - x[now] > d) break;
                int R = r[now];
                for (int j = now + 1; j <= R; ++ j) {
                    t[j] = sum[now] - sum[l[j] - 1];
                    if (t[j] == 2) ++ ans;
                    else if (t[j] > 3) t[j] = 3;
                    sum[j] = sum[j - 1] + t[j];
                }
                now = R;
            }
        }
        cout << ans << "\n";
    }
}

signed main() {
    freopen("migrate.in", "r", stdin), freopen("migrate.out", "w", stdout);
    // freopen("test.in", "r", stdin), freopen("test.out", "w", stdout);
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int c, T;
    cin >> c >> T;
    while (T --) {
        if (c <= 10) SUB1 :: Main();
    }

    // cerr << "Time: " << 1e3 * clock() / CLOCKS_PER_SEC << "ms\n";
    // cerr << "Memory: " << (&MED - &MBE) / 1024.0 / 1024.0 << "MB\n"; 
    return 0;
}