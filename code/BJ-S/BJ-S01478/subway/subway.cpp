#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 3010;
int n, m, c, d, q, dp[N][N], w[N], a[510][N], t[510][N];
bool vis[N];
int ste[N];
int k, x, y;
vector <int> g[N];
void bfs(ll x) {
    queue <ll> que;
    vis[x] = 1;
    que.push(x);
    while(!que.empty()) {
        ll u = que.front();
        que.pop();
        for(auto v:g[u]) {
            if(!vis[v]) {
                vis[v] = 1;
                ll tmp = ste[u] + 1;
                ste[v] = ste[u] + 1;
                que.push(v);
            }
        }
    }
    memset(ste, 0, sizeof(ste));
    memset(vis, 0, sizeof(vis));
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    memset(dp, 0x3f, sizeof(dp));
    for(int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    int tmp = 0;
    bool flag = 0;
    for(int i = 1; i <= n; i++) {
        cin >> k;
        for(int j = 1; j <= k; j++) {
            cin >> a[i][j] >> t[i][j];
            tmp = t[1][1];
            if(t[i][j] != tmp) {
                flag = 1;
            }
        }
        for(int j = 1; j <= k - 1; j++) {
            for(int l = j + 1; l <= k; l++) {
                g[a[i][j]].push_back(a[i][l]);
                g[a[i][l]].push_back(a[i][j]);
                dp[a[i][j]][a[i][l]] = t[i][j] + t[i][l];
                dp[a[i][l]][a[i][j]] = t[i][j] + t[i][l];
            }
        }
    }
    if(!flag) {
        for(int i = 1; i <= q; i++) {
            cin >> x >> y;
            bfs(x);
            cout << ste[y] * tmp + w[x] + w[y] << endl;
        }
    }
    for(int i = 1; i <= m; i++) {
        dp[i][i] = 0;
    }
    for(int k = 1; k <= m; k++) {
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= m; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    for(int i = 1; i <= q; i++) {
        cin >> x >> y;
        cout << dp[x][y] + w[x] + w[y] << endl;
    }
    return 0;
}
