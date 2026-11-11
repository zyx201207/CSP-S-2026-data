#include <bits/stdc++.h>
using namespace std;
int main () {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> x(n+1);
        for (int i = 1; i <= n; i++) cin >> x[i];
        int ans = 0;
        for (int i = 1; i <= n; i++) {
        //    for (int j = i+1; j <= n; j++) {
        //        if (x[j]-x[i] <= d) {
        //            dist[i][j] = 1;
        //            continue;
        //        }
        //        int mind = 0x3f3f3f3f, cnt = 0;
        //        for (int k = j; k > i; k++) {
        //            if (dist[i][k]+dist[k][j] < mind) {
        //                mind = dist[i][k]+dist[k][j];
        //                cnt = 1;
        //            } else if (dist[i][k]+dist[k][j] == mind) cnt++;
        //        }
        //        ans += cnt;
        //    }
            vector<int> dist(n+1, 0x3f3f3f3f);
            queue<pair<int, int>> q;
            q.push({i, 0});
            while (!q.empty()) {
                pair<int, int> u = q.front();
                q.pop();
                if (dist[u.first] < u.second) continue;
                else if (dist[u.first] == u.second) ans++;
                else dist[u.first] = u.second;
                for (int i = u.first; i <= n; i++) {
                    if (x[i] - x[u.first] > d) break;
                    q.push({i, u.second+1});
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}