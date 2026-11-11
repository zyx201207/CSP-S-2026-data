#include<bits/stdc++.h>
#define int long long
#define For(i, n) for (int i = 1; i <= (n); ++i)
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define Rep(i, n) for (int i = (n); i >= 1; --i)
#define REP(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;

const int M = 5e5 + 1000;
int w[M], k[509];

signed main() {
    freopen("subway.in", "r", stdin); freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int c, n, m, d, q; cin >> c >> n >> m >> d >> Q;
    For (i, m) cin >> w[i];
    vector<vector<int>> a(n+1, vector<int>(m+1)), t(n+1, vector<int>(m+1));
    vector<vector<int>> line[m+1];
    For (i, n) {
        cin >> k[i];
        For (j, k[i]) {
            cin >> a[i][j] >> t[i][j];
            line[a[i][j]].push_back(i);
        }
    }
    while (Q--) {
        int x, y; cin >> x >> y;
        int ans = w[x] + w[y];
        int l = line[x].size();
        FOR (i, 0, l-1) {
            For (j, k[i]) {
                
            }
        }
    }
    return 0;
}