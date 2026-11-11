#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

const int M = 5e5+5, N = 505;

int c, n, m, d, q, ans, x, y;
int w[M];
int k[N];
vector<int> a[N], t[N];
vector<pair<int, int>> ins[M];
int vis[M];

void dfs(int i, int res) {
    // 现在在车站 i 的站厅
    if (i == y) {
        ans = min(ans, res);
        // cout<<"Answer correct! now is "<<ans<<endl;
        return;
    }
    if (res > vis[i])
        return;
    vis[i] = res;
    // 选哪一条线路？
    // cout << "We're at "<<i<<endl;
    for (auto pai : ins[i]) {
        int line = pai.first, number = pai.second;
        res += t[line][number];
        // cout<<"choose line "<<line<<" add "<<t[line][number]<<endl;
        // 这条线上选哪个站？
        for (int j = 0; j < a[line].size(); ++j) {
            int zhan = a[line][j];
            if (zhan != i) {
                // 到达此站
            // cout<<"choose zhan "<<zhan<<" add "<<t[line][j]<<endl;
                res += t[line][j];
                // 到达zhan站厅
                dfs(zhan, res);
                res -= t[line][j];
            // cout<<"unchoose zhan "<<zhan<<" del "<<t[line][j]<<endl;
            }
        }
        // cout<<"unchoose line "<<line<<" del "<<t[line][number]<<endl;
        res -= t[line][number];
    }
    // cout<<"exit the station "<<i<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; ++i)
        cin >> w[i];
    for (int i = 1; i <= n; ++i) {
        cin >> k[i];
        for (int j = 1; j <= k[i]; ++j) {
            int A, T;
            cin >> A >> T;
            a[i].push_back(A);
            t[i].push_back(T);
            ins[A].push_back({i, j - 1});
        }
    }
    for (int i = 1; i <= q; ++i) {
        cin >> x >> y;
        ans = 1e18;
        fill(vis + 1, vis + 1 + m, 1e18);
        dfs(x, 0);
        cout << w[x] + ans + w[y] << endl;
    }
    return 0;
}