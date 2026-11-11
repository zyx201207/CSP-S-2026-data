#include "bits/stdc++.h"
using namespace std;
int start, end, c, n, m, d, q, w[500005], lj, tj, ans; // lj: station of line; tj: time of station to line
struct _station {
    int _id;
    int time1; // time1: time of station <==> ground
    vector<pair<int, int>> to_line; // time of station to per line, <int, int> -> line, time
    vector<int> line_list;
} station[500005];
vector<int> lines[505]; // station id of lines
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> station[i].time1;
    for (int i = 1; i <= n; i++) {
        cin >> lj >> tj;
        station[lj].to_line.push_back(make_pair(i, tj));
        lines[i].push_back(lj);
        station[lj].line_list.push_back(i);
    }
    for (int i = 1; i <= q; i++) {
        cin >> start >> end;
        ans += station[start].time1;
        for (auto line : station[start].line_list) {
            int index = lower_bound(lines[line].begin(), lines[line].end(), start) - lines[line].begin() - 1;
            if (index) {
                ans += station[lines[line][index - 1]].time1;
            } else {
                ans += station[lines[line][index + 1]].time1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}