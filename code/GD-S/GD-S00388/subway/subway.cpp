#include <iostream>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

using pii = pair<int, int>;

int c, n, m, d, q;
int w[500005];

vector<int> ways[500005];
map<int, int> walk[502];

long long change[502][502];

int fast_io = []() {
    cin.tie(0) -> sync_with_stdio(false);
    return 0;
}();

int file_io = []() {
    string ios = "subway";
    string is = ios + ".in";
    string os = ios + ".out";
    freopen(is.c_str(), "r", stdin);
    freopen(os.c_str(), "w", stdout);
    return 0;
}();

int main() {
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }

    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        for (int j = 1; j <= k; j++) {
            int a, t;
            cin >> a >> t;
            ways[a].push_back(i);
            walk[i][a] = t;
            // cerr << i << ' ' << a << ' ' << walk[i][a] << endl;
        }
    }

    memset(change, 0x3f, sizeof change);
    for (int s = 1; s <= m; s++) {
        int k = ways[s].size(); // cerr << k << endl;
        for (int i = 1; i < k; i++) {
            for (int j = 0; j < i; j++) {
                int wi = ways[s][i], wj = ways[s][j];
                long long t = walk[wi][s] + walk[wj][s];
                change[wi][wj] = change[wj][wi] = min(t, change[wi][wj]);
            }
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (i == k) continue;
            for (int j = 1; j <= n; j++) {
                if (i == j || j == k) continue;
                change[i][j] = min(change[i][k] + change[k][j], change[i][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) change[i][i] = 0;

    while (q--) {
        int s, t;
        cin >> s >> t;
        
        long long ans = 9e18;
        
        int ws = ways[s].size(), wt = ways[t].size();
        for (int i = 0; i < ws; i++) {
            int wi = ways[s][i];
            for (int j = 0; j < wt; j++) {
                int wj = ways[t][j];
                ans = min(change[wi][wj] + walk[wi][s] + walk[wj][t], ans);
                // cerr << change[wi][wj] << endl;
            }
        }

        cout << ans + w[s] + w[t] << '\n';
    }
}