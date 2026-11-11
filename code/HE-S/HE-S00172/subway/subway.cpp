#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int w[50005];
int k[505];
int a[505][50005];
int t[505][50005];
int z[505][50005];
int vis[505][50005];
int c, n, m, d, q;
int x, y;
int ans;

void dfs(int now, int way, int time) {
    if (now == y) {
        ans = min(ans, time + t[way][now] + w[now]);
        return;
    }

    for (int i = 1;i <= n;i++) {
        if (z[i][now] && !vis[i][now]) {
            vis[i][now] = 1;
            dfs(now, i, time + t[way][now] + t[i][now]);
            vis[i][now] = 0;
        }
    }
    for (int i = 1;i <= k[way];i++) {
        if (!vis[way][a[way][i]]) {
            vis[way][a[way][i]] = 1;
            dfs(a[way][i], way, time);
            vis[way][a[way][i]] = 0;
        }
    }
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> c >> n >> m >> d >> q;
    for (int i = 1;i <= m;i++) {
        cin >> w[i];
    }
    for (int i = 1;i <= n;i++) {
        cin >> k[i];
        for (int j = 1;j <= k[i];j++) {
            cin >> a[i][j];
            cin >> t[i][a[i][j]];
            z[i][a[i][j]] = 1;
        }
    }

    while (q--) {
        memset(vis, 0, sizeof(vis));
        ans = INT_MAX;
        cin >> x >> y;
        for (int i = 1;i <= n;i++) {
            if (z[i][x]) {
                dfs(x, i, w[x] + t[i][x]);
            }
        }
        cout << ans << endl;
    }

    return 0;
}

