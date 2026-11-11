#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxlines = 525, maxstations = 5e5 + 25;
constexpr ll ll_inf = 1e18 + 25;
int c, total_lines, total_stations, d, q;
int station_to_hall[maxstations];
vector<pair<int, int>> station[maxstations];
ll floyd[maxlines][maxlines];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    scanf("%d%d%d%d%d", &c, &total_lines, &total_stations, &d, &q);
    for (int i = 1; i <= total_stations; ++i) {
        scanf("%d", &station_to_hall[i]);
    }
    for (int i = 1; i <= total_lines; ++i) {
        int sz;
        scanf("%d", &sz);
        for (int j = 1; j <= sz; ++j) {
            int ls, hp;
            scanf("%d%d", &ls, &hp);
            station[ls].emplace_back(i, hp);
        }
    }
    for (int i = 1; i <= total_lines; ++i) {
        for (int j = 1; j <= total_lines; ++j) {
            floyd[i][j] = floyd[j][i] = (i == j ? 0 : ll_inf);
        }
    }
    for (int i = 1; i <= total_stations; ++i) {
        for (int k1 = 0; k1 < static_cast<signed>(station[i].size()); ++k1) {
            for (int k2 = k1 + 1; k2 < static_cast<signed>(station[i].size()); ++k2) {
                auto [line1, time1] = station[i][k1];
                auto [line2, time2] = station[i][k2];
                floyd[line1][line2] = floyd[line2][line1] = min(
                    floyd[line2][line1], static_cast<ll>(time1) + time2);
            }
        }
    }
    for (int k = 1; k <= total_lines; ++k) {
        for (int i = 1; i <= total_lines; ++i) {
            for (int j = 1; j <= total_lines; ++j) {
                floyd[i][j] = min({ll_inf, 
                    floyd[i][j], floyd[i][k] + floyd[k][j]});
            }
        }
    }
    while (q--) {
        int x, y;
        scanf("%d%d", &x, &y);
        ll ans = numeric_limits<ll>::max();
        for (auto [st_line, st_hall_to_platform] : station[x]) {
            for (auto [ed_line, ed_hall_to_platform] : station[y]) {
                ans = min(ans, 
                    station_to_hall[x] + st_hall_to_platform + 
                    floyd[st_line][ed_line] + 
                    ed_hall_to_platform + station_to_hall[y]);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}