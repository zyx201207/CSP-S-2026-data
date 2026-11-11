#include<bits/stdc++.h>
using namespace std;

int c, n, m, d, q;
vector<long long> w;
vector< vector< pair<int, long long> > > k; // a t
vector< vector< pair<int, long long> > > in_walk;
long long line2line[505][505];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    cin >> c >> n >> m >> d >> q;

    w.resize(m + 1, 0);
    in_walk.resize(m + 1);
    k.resize(n + 1);

    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }

    for (int i = 1; i <= n; i++) {
        int ki;
        cin >> ki;
        vector< pair<int, long long> > at;
        for (int i2 = 0; i2 < ki; i2++) {
            int a;
            long long t;
            cin >> a >> t;
            // at.push_back({a, t});
            at.emplace_back(a, t);
            // in_walk[a].push_back({i, t});
            in_walk[a].emplace_back(i, t);
        }
        k[i] = at;
    }

    for (int i = 1; i <= n; i++) {
        for (int i2 = 1; i2 <= n; i2++) {
            if (i == i2) line2line[i][i2] = 0;
            else line2line[i][i2] = 0x3f3f3f3f3f3f3f3fll;
        }
    }

    for (int i = 1; i <= m; i++) {
        vector< pair<int, long long> > in_walki = in_walk[i];
        int iw_size = in_walki.size();
        for (int i2 = 0; i2 < iw_size; i2++) {
            for (int i3 = 0; i3 < iw_size; i3++) {
                if (i2 == i3) continue;
                pair<int, long long> pr_i2 = in_walki[i2];
                pair<int, long long> pr_i3 = in_walki[i3];
                long long cost_time = pr_i2.second + pr_i3.second;
                if (cost_time < line2line[pr_i2.first][pr_i3.first]) {
                    line2line[pr_i3.first][pr_i2.first] = line2line[pr_i2.first][pr_i3.first] = cost_time;
                }
            }
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int i2 = 1; i2 <= n; i2++) {
                line2line[i2][i] = line2line[i][i2] = min(line2line[i][i2], line2line[i][k] + line2line[k][i2]);
            }
        }
    }

    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        long long first_cost = w[x] + w[y];
        long long second_cost = 0x3f3f3f3f3f3f3f3fll;

        for (pair<int, int> x_pair : in_walk[x]) {
            for (pair<int, int> y_pair : in_walk[y]) {
                second_cost = min(second_cost, x_pair.second + y_pair.second + line2line[x_pair.first][y_pair.first]);
            }
        }

        cout << (first_cost + second_cost) << '\n';
    }

    return 0;
}