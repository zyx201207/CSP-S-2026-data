#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, d;
int a[2000005];
int ways[2000005];
int shortway[2000005];
void bfs(int st) {
    queue<pair<int, int> > q;
    q.push({st, 0});
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        if (p.second < shortway[p.first]) {
            shortway[p.first] = p.second;
            ways[p.first] = 1;
        } else if (p.second == shortway[p.first]) {
            ways[p.first]++;
        }
        if (p.first == n) {
            continue;
        }
        for (int i = p.first + 1; i <= n; i++) {
            if (abs(a[i] - a[p.first]) <= d) {
                q.push({i, p.second + 1});
            } else break;
        }
    }
}
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    int c, t;
    cin >> c >> t;
    while (t--) {
        cin >> n >> d;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i < n; i++) {
            memset(ways, 0, sizeof ways);
            memset(shortway, 0x3f, sizeof shortway);
            bfs(i);
            for (int j = i + 1; j <= n; j++) {
                if (ways[j] == 2) {
                    ans++;
                }
            }

        }
        cout << ans << endl;
    }
    return 0;
}
