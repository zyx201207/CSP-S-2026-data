#include <bits/stdc++.h>
using namespace std;

int c, T, n; long long d, x[2000005];
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> T;
    queue<pair<int, int>> q;
    while (T--) {
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> x[i];
        cout << "OK" << endl;
        int ans = 0;
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                while (q.size()) q.pop();
                int ml = 0x3f3f3f3f, mc;
                q.push({i, 0});
                while (q.size()) {
                    int u = q.front().first, l = q.front().second; q.pop();
                    if (u == j && l < ml) ml = l, mc = 1;
                    else if (u == j && l == ml) mc++;
                    else if (u == j && l > ml) break;
                    for (int k = u; x[k] - x[u] <= d && k <= j; k++)
                        q.push({k, l + 1});
                }
                if (ml < 0x3f3f3f3f && mc == 2) ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
