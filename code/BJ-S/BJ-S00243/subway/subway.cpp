#include <bits/stdc++.h>
using namespace std;

long long c, n, m, d, q;
long long w[500005], len[500005];
long long dp[505][505];
vector<long long> a[500005], t[500005], mp[500005];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    cin >> c >> n >> m >> d >> q;

    memset(dp, 0x10, sizeof(dp));

    for (int i = 1; i <= m; i++) {
        cin >> w[i];
        dp[i][i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        cin >> len[i];

        a[i].resize(len[i] + 1), t[i].resize(len[i] + 1);

        for (int j = 1; j <= len[i]; j++) {
            cin >> a[i][j] >> t[i][j];

            mp[a[i][j]].push_back(i);

            dp[a[i][j]][a[i][j - 1]] = dp[a[i][j - 1]][a[i][j]] = min(min(dp[a[i][j]][a[i][j - 1]], dp[a[i][j - 1]][a[i][j]]), t[i][j] + t[i][j - 1]);
        }
    }

    for (int k = 1; k <= m; k++) {
        for (auto en : mp[k]) {
            for (auto st : mp[k]) {
                for (int i = 1; i <= m; i++) {
                    for (int j = 1; j <= m; j++) {
                        if (en == st) {
                            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                        } else {
                            dp[i][j] = min(dp[i][j], dp[i][k] + t[en][k] + t[st][k] + dp[k][j]);
                        }
                    }
                }
            }
        }
    }

    while (q--) {
        int x, y;

        cin >> x >> y;

        cout << w[x] + w[y] + dp[x][y] << endl;
    }

    return 0;
}