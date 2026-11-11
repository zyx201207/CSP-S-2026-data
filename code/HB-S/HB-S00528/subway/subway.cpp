#include<bits/stdc++.h>

using namespace std;

using i64 = long long;

i64 w[510000], vis[510][510];
vector<pair<i64, i64>> st[510000];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    i64 c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            vis[i][j] = 1LL << 60;
        }
    }
    for (int i = 0; i < n; ++i) {
        vis[i][i] = 0;
    }
    for (int i = 1; i <= m; ++i) {
        cin >> w[i];
    }
    for (int i = 0; i < n; ++i) {
        i64 k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            i64 a, t;
            cin >> a >> t;
            st[a].emplace_back(i, t);
        }
    }
    for (int i = 0; i < m; ++i) {
        for (auto &j: st[i]) {
            for (auto &k: st[i]) {
                i64 val = j.second + k.second;
                vis[j.first][k.first] = min(vis[j.first][k.first], val);
                vis[k.first][j.first] = min(vis[k.first][j.first], val);
            }
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                vis[i][j] = min(vis[i][j], vis[i][k] + vis[k][j]);
            }
        }
    }
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        i64 res = 1LL << 60;
        for (auto &j: st[l]) {
            for (auto &k: st[r]) {
                res = min(res, w[l] + w[r] + j.second + k.second + vis[j.first][k.first]);
            }
        }
        cout << res << endl;
    }
    return 0;
}