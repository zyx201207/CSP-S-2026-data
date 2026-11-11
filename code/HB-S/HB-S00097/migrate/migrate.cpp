// migrate
#include <iostream>
using namespace std;

const int N = 2e6 + 1023;
int c, t, n;
long long e[305][305], x[N], d, cnt[305][305];

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t--) {
        cin >> n >> d;
        for (int i = 1; i <= n; ++i) cin >> x[i];
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                e[i][j] = 0x3f3f3f3f;
                cnt[i][j] = 0;
            }
            e[i][i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (abs(x[i] - x[j]) <= d && i != j) {
                    e[i][j] = 1;
                    cnt[i][j] = 1;
                }
            }
        }
        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (e[i][k] + e[k][j] < e[i][j]) {
                        e[i][j] = e[i][k] + e[k][j];
                        cnt[i][j] = cnt[i][k] * cnt[k][j];
                    } else if (e[i][k] + e[k][j] == e[i][j]) {
                        cnt[i][j] += cnt[i][k] * cnt[k][j];
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j)
                if (cnt[i][j] == 2)
                    ++ans;
        cout << ans << '\n';
    }
    return 0;
}
