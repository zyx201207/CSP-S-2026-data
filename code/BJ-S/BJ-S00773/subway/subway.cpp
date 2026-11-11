#include <bits/stdc++.h>
#define int long long

using namespace std;

struct edge{
    int first, second;
};

int c, n, m, d, q;
int flyd[514][514];
int wi[514514];
vector<edge> vec[514514];

signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    memset(flyd, 0x3f3f, sizeof(flyd));
    for (int i = 1; i <= n; i++)flyd[i][i] = 0;
    for (int i = 1; i <= m; i++)cin >> wi[i];
    for (int i = 1; i <= n; i++){
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++){
            int aij, tij;
            cin >> aij >>tij;
            vec[aij].push_back({i, tij});
            for (auto it : vec[aij]){
                flyd[it.first][i] = flyd[i][it.first] = min(flyd[i][it.first], it.second + tij);
            }
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            for (int k = 1; k <= n; k++){
                flyd[i][j] = min(flyd[i][j], flyd[i][k] + flyd[k][j]);
            }
        }
    }
    for (int i = 1; i <= q; i++){
        int wx, wy, minn = LLONG_MAX;
        cin >> wx >> wy;
        for (auto it : vec[wx]){
            for (auto it1 : vec[wy]){
                minn = min(minn, wi[wx] + wi[wy] + it.second + it1.second + flyd[it1.first][it.first]);
            }
        }
        cout << minn << endl;
    }
    return 0;
}
