#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

#define ll long long

const int N = 501, M = 5 * 1e5 + 1, Q = 1e5 + 1;
unordered_set<int> ways1[N];
vector<int> ways2[N];
int w[M], t[N][M], r[Q][2];
int c, n, m, d, q;

void dfs(int x, int y, int T, ll& ans) {
    if(x == y) return;
    for(int i = 0; i < n; ++i) {
        if(ways1[i].find(x) != ways1[i].end()) {
            ll mt = 3 * M * 1e9;
            for(int j = 0; j < ways2[i].size(); ++j) {
                int st = ways2[i][j];
                if(st != x) {
                    ll tt = 0;
                    dfs(st, y, T, ans);
                    mt = min(mt, tt);
                }
                ans += (2 * T + mt);
            } 
        }
    }
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    cin >> c >> n >> m >> d >> q;
    for (int i = 0; i < m; ++i)
        cin >> w[i];
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int a;
            cin >> a;
            ways1[i].insert(a);
            ways2[i].push_back(a);
            cin >> t[i][a];
        }
    }
    for (int i = 0; i < q; ++i) 
        cin >> r[i][0] >> r[i][1];

    if(c >= 12 && c <= 19) {
        for(int i = 0; i < q; ++i) {
            int T = t[0][0];
            int x = r[i][0], y = r[i][1];
            ll ans = w[x] + w[y] + 2 * T;
            dfs(x, y, T, ans);
            cout << ans << endl;
        }
    }
    return 0;
}
