#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using u64 = unsigned long long;

constexpr int N = 666;
constexpr int M = 5e5 + 6;

i64 c, n, m, d, q;
i64 w[M];
i64 k[N], s[M];
vector<i64> a[M], t[M];
i64 dis[N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dis[i][j] = 1e18;
        }
    }
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= m; i++) a[i].push_back(0), t[i].push_back(0);
    for (int i = 1; i <= n; i++) {
        dis[i][i] = 0;
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++) {
            i64 tmpa, tmpt;
            cin >> tmpa >> tmpt;
            a[tmpa].push_back(i);
            t[tmpa].push_back(tmpt);
            s[tmpa]++;
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= s[i]; j++) {
            for (int l = 1; l <= s[i]; l++) {
                if (j == l) continue;
                dis[a[i][j]][a[i][l]] = min(dis[a[i][j]][a[i][l]], t[i][j] + t[i][l]);
                dis[a[i][l]][a[i][j]] = dis[a[i][j]][a[i][l]];
            }
        }
    }
    for (int mid = 1; mid <= n; mid++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;
                dis[i][j] = min(dis[i][mid] + dis[mid][j], dis[i][j]);
            }
        }
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        i64 ans = 1e18;
        for (int i = 1; i <= s[x]; i++) {
            for (int j = 1; j <= s[y]; j++) {
                ans = min(ans, w[x] + w[y] + t[x][i] + t[y][j] + dis[a[x][i]][a[y][j]]);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}