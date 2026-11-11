#include <iostream>
#include <vector>
using namespace std;
using numtype = long long;
const numtype INF = 0x7fffffffffffffff;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    //cerr << INF << "\n";

    numtype c, T;
    cin >> c >> T;

    for (numtype t = 0; t < T; ++t){
        numtype n, d;
        cin >> n >> d;

        vector<numtype> xs(n, 0);
        for (numtype i = 0; i < n; ++i) cin >> xs[i];

        if (n == 1){
            cout << "0\n";
            continue;
        }

        if (c == 11 || c == 12){
            numtype D = xs[1] - xs[0];
            if (D >= d){
                cout << "0\n";
                continue;
            }

            d = d / D;
            numtype len = (d << 1) - 1;

            if (len > n) cout << "0\n";
            else cout << (n - len) << "\n";

            continue;
        }

        //returnn

        vector<vector<numtype>> cnt(n, vector<numtype>(n, 0));
        vector<vector<numtype>> dp(n, vector<numtype>(n, INF));

        for (numtype i = 0; i < n; ++i){
            cnt[i][i] = 1;
            dp[i][i] = 0;
        }

        for (numtype i = 1; i < n; ++i){
            if (xs[i] - xs[i - 1] <= d){
                cnt[i - 1][i] = 1;
                dp[i - 1][i] = 1;
            }
            else cnt[i - 1][i] = 0;
        }

        for (numtype len = 3; len <= n; ++len){
            for (numtype i = 0, j = len - 1; j < n; ++i, ++j){
                for (numtype k = i + 1; k <= j && xs[k] - xs[i] <= d; ++k){
                    if (cnt[k][j] > 2 || cnt[k][j] == 0) continue;

                    numtype v = dp[k][j] + 1;
                    if (v < dp[i][j]){
                        dp[i][j] = v;
                        cnt[i][j] = cnt[k][j];
                    }
                    else if (v == dp[i][j]) cnt[i][j] += cnt[k][j];
                }
            }
        }

        numtype total = 0;
        for (numtype i = 0; i < n; ++i){
            for (numtype j = 0; j < n; ++j){
                //if (t == 13) cerr << cnt[i][j] << " ";
                if (cnt[i][j] == 2) ++total;
            }
            //if (t == 13) cerr << "\n";
        }

        cout << total << "\n";
    }

    return 0;
}
