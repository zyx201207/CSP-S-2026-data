#include <bits/stdc++.h>
using namespace std;

const int N = 510, M = int(5e5) + 10;

long long w[M], dis[N][N];
vector<pair<int, long long>> vec[M];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        while (k--) {
            int u;
            long long v;
            cin >> u >> v;
            vec[u].emplace_back(i, v);
        }
    }
    memset(dis, 0x3f, sizeof dis);
    for (int i = 1; i <= n; i++) dis[i][i] = 0;
    for (int i = 1; i <= m; i++)
        for (auto j : vec[i])
            for (auto k : vec[i]) if (j != k)
                dis[j.first][k.first] = min(dis[j.first][k.first], j.second + k.second);
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    while (q--) {
        int x, y;
        cin >> x >> y;
        long long num = 0x3f3f3f3f3f3f3f3f;
        for (auto j : vec[x])
            for (auto k : vec[y]) num = min(num, w[x] + w[y] + j.second + k.second + dis[j.first][k.first]);
        cout << num << '\n';
    }

    return 0;
}