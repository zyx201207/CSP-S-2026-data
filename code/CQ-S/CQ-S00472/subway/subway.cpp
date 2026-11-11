#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <unordered_map>
#define endl '\n'
using namespace std;
typedef long long ll;

int main(int argc, char* argv[]) {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int cse{}, n{}, m{}, d{}, times{};
    cin >> cse >> n >> m >> d >> times;
    vector<int> w(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    vector<unordered_map<int, ll>> a(n);
    vector<bitset<int(5e5) + 5>> res(n);
    vector<vector<pair<int, int>>> idx(m + 1);
    for (int i = 0; i < n; i++) {
        int len{}; cin >> len;
        for (int j = 0; j < len; j++) {
            int x{}; ll t{};
            cin >> x >> t;
            a[i][x] = t, res[i][x] = true, idx[x].emplace_back(i, t);
        }
    }
    vector<vector<ll>> g(n, vector<ll>(n, ll(4e18)));
    for (int i = 0; i < n; i++) {
        g[i][i] = 0;
    }
    for (int i = 1; i <= m; i++)
    for (int k1 = 0; k1 < idx[i].size(); k1++)
    for (int k2 = k1 + 1; k2 < idx[i].size(); k2++) {
        int u = idx[i][k1].first, v = idx[i][k2].first;
        g[u][v] = g[v][u] = min(g[u][v], a[u][i] + a[v][i]);
    }
    for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    }
    while (times--) {
        int s{}, t{};
        cin >> s >> t;
        ll ans = ll(4e18);
        for (int i = 0; i < idx[s].size(); i++)
        for (int j = 0; j < idx[t].size(); j++) {
            ans = min(ans, idx[s][i].second + g[idx[s][i].first][idx[t][j].first] + idx[t][j].second);
        }
        ans += (w[s] + w[t]);
        cout << ans << endl;
    }
    return 0;
}