/*
Floyd...baoliqidong!!!
*/
#include <bits/stdc++.h>
#define st first
#define nd second
using namespace std;
using ll = long long;
using P = pair<int, int>;

int c, T;
int n, ans;
ll d;

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> c >> T;
    for ( ; T--; ) {
        ans = 0;
        cin >> n >> d;
        vector<int> a(n + 5, 0);
        vector<vector<int> > dis(n + 5, vector<int>(n + 5, (int)1e9));
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int u = 1, cnt; u <= n; u++) {
            for (int v = 1; v < u; v++)
                dis[u][v] = dis[v][u] = ((abs(a[u] - a[v]) <= d) ? 1 : dis[v][u]);
        }
        for (int u = 1, cnt; u <= n; u++) {
            for (int v = 1; v < u; v++) {
                for (int k = 1; k <= n; k++) {
                    dis[u][v] = min(dis[u][v], dis[u][k] + dis[k][v]);
                }
                cnt = 0;
                for (int k = 1; k <= n; k++)
                    cnt += (dis[u][k] + dis[k][v] == dis[u][v]);
                ans += (cnt == 2);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
