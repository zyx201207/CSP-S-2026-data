#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define LL __int128
#define pii pair < int , int >
#define mp(i, j) make_pair(i, j)

const int N = 5e5 + 5;
ll ccc, n, m, ddd, q, value[N], f[505][505];
struct node {
    ll x, y;
};
vector < node > a[N];

void solvetask() {
    cin >> ccc >> n >> m >> ddd >> q;
    for(int i = 1; i <= m; i++) cin >> value[i];
    for(int i = 1; i <= n; i++) {
        int cnt;
        cin >> cnt;
        while(cnt --) {
            int u, d;
            cin >> u >> d;
            a[u].push_back((node) {i, d});
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) f[i][j] = 1e18;
        f[i][i] = 0;
    }
    for(int u = 1; u <= m; u++) {
        int cnt = a[u].size();
        for(int i = 0; i < cnt; i++) {
            for(int j = i + 1; j < cnt; j++) {
                f[a[u][i].x][a[u][j].x] = min(f[a[u][i].x][a[u][j].x], a[u][i].y + a[u][j].y);
                f[a[u][j].x][a[u][i].x] = f[a[u][i].x][a[u][j].x];
            }
        }
    }
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    while(q --) {
        int u, v;
        cin >> u >> v;
        int cnt1 = a[u].size(), cnt2 = a[v].size();
        ll ans = 2e18;
        for(int i = 0; i < cnt1; i++) {
            for(int j = 0; j < cnt2; j++) {
                ans = min(ans, a[u][i].y + a[v][j].y + f[a[u][i].x][a[v][j].x] + value[u] + value[v]);
            }
        }
        cout << ans << "\n";
    }
    return;
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    int T = 1;
    while(T --) solvetask();
    return 0;
}
