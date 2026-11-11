#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int x[2000005];
int dis[2000005];
int cnt[2000005];
int n, d;

void dfs(int now, int dist) {
    if (dist < dis[now]) {
        dis[now] = dist;
        cnt[now] = 1;
    }
    else if (dist == dis[now]) {
        cnt[now]++;
    }
    else {
        return;
    }
    if (now == n) {
        return;
    }

    int i = now + 1;
    while (i <= n && x[i] - x[now] <= d) {
        dfs(i, dist + 1);
        i++;
    }
}

signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c, t;
    cin >> c >> t;

    while (t--) {
        cin >> n >> d;
        for (int i = 1;i <= n;i++) {
            cin >> x[i];
        }

        int ans = 0;
        for (int u = 1;u < n;u++) {
            memset(dis, 0x7f, sizeof(dis));
            memset(cnt, 0, sizeof(cnt));
            dfs(u, 0);
            for (int i = u + 1;i <= n;i++) {
                if (cnt[i] == 2) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
