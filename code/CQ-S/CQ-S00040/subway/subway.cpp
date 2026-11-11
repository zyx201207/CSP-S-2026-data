#include <bits/stdc++.h>
#define int long long
using namespace std;

namespace _ {
    
    const int N = 5e2+10;
    const int M = 5e5+10;
    const int inf = 0x3f3f3f3f3f3f3f3f;

    struct edge {
        int v, w;
    };

    int c, n, m, d, Q;

    int w[M], k[N];

    vector<int> a[N], t[N];

    vector<pair<int, int> > centre[M];

    int dp[N][N];

    void chkmin(int &x, int &y, int z) {
        x = y = min(min(x, y), z);
        return ;
    }

    signed main() {

        freopen("subway.in","r",stdin);
        freopen("subway.out","w",stdout);

        cin.tie(0)->sync_with_stdio(false);

        cin >> c >> n >> m >> d >> Q;
        for (int i = 1;i<= m;i++) {
            cin >> w[i];
        }
        for (int i = 1;i<= n;i++) {
            cin >> k[i];
            a[i].push_back(0);
            t[i].push_back(0);
            for (int j = 1;j<= k[i];j++) {
                int x, y; cin >> x >> y;
                a[i].push_back(x);
                t[i].push_back(y);
                centre[x].push_back({i, j});
            }
        }

        memset(dp, 0x3f, sizeof dp);
        for (int i = 1;i<= n;i++) dp[i][i] = 0;        

        for (int i = 1;i<= m;i++) {

            int len = (int)(centre[i].size()) - 1;

            for (int j = 0;j<= len;j++) {

                auto X = centre[i][j];

                for (int k = j+1;k<= len;k++) {

                    auto Y = centre[i][k];

                    chkmin(dp[X.first][Y.first], dp[Y.first][X.first], t[X.first][X.second] + t[Y.first][Y.second]);

                }

            }

        }

        for (int k = 1;k<= n;k++) {
            for (int i = 1;i<= n;i++) {
                for (int j = 1;j<= n;j++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }

        int x, y;
        while (Q--) {

            cin >> x >> y;

            int ans = inf;

            for (auto X : centre[x]) {

                for (auto Y : centre[y]) {

                    ans = min(ans, dp[X.first][Y.first] + t[X.first][X.second] + t[Y.first][Y.second]);

                }

            }

            cout << ans + w[x] + w[y] << '\n';

        }

        return 0;
    }

}

signed main() {
    int bg = clock();
    int re = _::main();
    int ed = clock();
    cerr << ed - bg << " ms and return " << re << '\n';    
    return re;
}