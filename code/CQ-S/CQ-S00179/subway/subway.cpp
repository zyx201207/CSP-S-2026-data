// Author: lzm0107
// 15:05

#include <bits/stdc++.h>
#include <cassert>

using namespace std;

constexpr long long kInf64 = 0x3f3f3f3f3f3f3f3f;

template<typename T>
T& chmin(T &x, T y) { return (x = min(x, y)); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    vector<int> w(m + 1);
    for (int i = 1; i <= m; i++) { cin >> w[i]; }
    vector<int> k(n);
    vector<vector<int>> a(n), t(n);
    for (int i = 0; i < n; i++) {
        cin >> k[i];
        a[i].resize(k[i]), t[i].resize(k[i]);
        for (int j = 0; j < k[i]; j++) {
            cin >> a[i][j] >> t[i][j];
        }
    }
    
    vector<vector<pair<int, int>>> station_to_line(m + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k[i]; j++) {
            station_to_line[a[i][j]].emplace_back(i, t[i][j]);
        }
    }
    vector<long long> _line_dis(n * n, kInf64);
    auto line_dis = [&_line_dis, n](int i, int j) -> long long& {
        return _line_dis[i * n + j];
    };
    for (int i = 0; i < n; i++) { line_dis(i, i) = 0; }
    for (int i = 1; i <= m; i++) {
        for (int i0 = 0; i0 < (int)station_to_line[i].size(); i0++) {
            for (int i1 = i0 + 1; i1 < (int)station_to_line[i].size(); i1++) {
                int l0 = station_to_line[i][i0].first, d0 = station_to_line[i][i0].second;
                int l1 = station_to_line[i][i1].first, d1 = station_to_line[i][i1].second;
                chmin(line_dis(l0, l1), (long long)d0 + d1);
                chmin(line_dis(l1, l0), (long long)d0 + d1);
            }
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                chmin(line_dis(i, j), line_dis(i, k) + line_dis(k, j));
            }
        }
    }

    for (int x, y, i = 1; i <= q; i++) {
        cin >> x >> y;
        long long res = kInf64;
        for (int i0 = 0; i0 < (int)station_to_line[x].size(); i0++) {
            for (int i1 = 0; i1 < (int)station_to_line[y].size(); i1++) {
                int l0 = station_to_line[x][i0].first, d0 = station_to_line[x][i0].second;
                int l1 = station_to_line[y][i1].first, d1 = station_to_line[y][i1].second;
                chmin(res, (long long)w[x] + w[y] + d0 + d1 + line_dis(l0, l1));
            }
        }
        cout << res << '\n';
    }
    return 0;
}