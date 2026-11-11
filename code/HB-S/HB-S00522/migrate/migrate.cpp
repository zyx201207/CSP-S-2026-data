#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f

using namespace std;

int c, t, dis[2000010], cnt[2000010], ind[2000010];
ll pos[2000010], d, dd, n;

vector<ll> E[2000010];

void topu(int x) {
    queue<int> q;
    for (int i = 1; i <= n; ++i) ind[i] = 0, E[i].clear(), dis[i] = INF, cnt[i] = 0;
    for (int i = x; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j) {
            if (pos[j] - pos[i] <= d) E[i].push_back(j), ind[j]++;
            else break;
        }
    
    q.push(x); dis[x] = 0, cnt[x] = 1;

    while (!q.empty()) {
        int nx = q.front(); q.pop();
        for (int y : E[nx]) {
            if (dis[nx] + 1 < dis[y]) dis[y] = dis[nx] + 1, cnt[y] = 0;
            if (dis[nx] + 1 == dis[y]) cnt[y] += cnt[nx];
            if ((--ind[y]) == 0) q.push(y);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    cin >> c >> t;

    while (t--) {
        cin >> n >> d;
        for (int i = 1; i <= n; ++i) cin >> pos[i];
        bool A = true;
        dd = pos[2] - pos[1];
        for (int i = 3; i <= n; ++i) {
            if (pos[i] - pos[i - 1] != dd) {
                A = false;
                break;
            }
        }
        if (A) {
            if (d <= 2 * dd - 1 || n + 1 < 2 * (d / dd)) cout << "0\n";
            else cout << n - 2 * (d / dd) + 1 << '\n';
            continue;
        }
        int ans = 0;
        for (int k = 1; k <= n; ++k) {
            topu(k);
            for (int i = k + 1; i <= n; ++i)
                if (cnt[i] == 2) ans++;
        }
        cout << ans << '\n';
    }

    return 0;
}
