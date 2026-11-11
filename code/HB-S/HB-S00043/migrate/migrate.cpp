#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
using ll = long long;
const ll N = 2e6 + 10, smN = 5010;
ll c, t, n, d, x[N], ans;
ll f[smN];
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t--) {
        cin >> n >> d;
        ans = 0;
        for(int i = 1; i <= n; i++) cin >> x[i];
        if(c <= 10) {
            for(int u = 1, smin, cnt; u <= n; u++) {
                memset(f, 0, sizeof(f));
                for(int i = u + 1; i <= n; i++) {
                    if(x[i] - x[u] <= d) {
                        f[i] = 1;
                        continue;
                    }
                    smin = N, cnt = 0;
                    for(int j = u; j < i; j++)
                        if(x[i] - x[j] <= d) {
                            if(smin > f[j]) smin = f[j], cnt = 1;
                            else if(smin == f[j]) cnt++;
                        }
                    if(cnt == 2) ans++;
                    f[i] = smin + 1;
                }
            }
            cout << ans << endl;
        } else cout << 0 << endl;
    }
    return 0;
}