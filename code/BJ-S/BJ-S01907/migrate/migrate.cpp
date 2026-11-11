#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 5;
ll a[N], r[N], p[N], g[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, T; cin >> c >> T;
    while (T--) {
        memset(p, 0, sizeof(p));
        int n; ll d; cin >> n >> d;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int right = 1;
        for (int i = 1; i <= n; i++) {
            while (a[right + 1] - a[i] <= d && right < n) right++;
            r[i] = right;
            //cout << r[i] << ' ';
        }
        ll ans = 0;
        queue<pair<ll, ll> > q; q.push({r[1], 1});
        for (ll i = 2; i <= n; i++) {
            if (r[i] == r[i - 1]) continue;
            while (!q.empty()) {
                if (q.front().first - i + 1 > 2) break;
                if (q.front().first - i + 1 == 2) {
                    ans += 1LL * (r[i] - q.front().first) * (i - q.front().second + p[i]);
                    g[r[i]] += i - q.front().second;
                    q.pop();
                } else if (q.front().first - i + 1 == 1) {
                    ans += 1LL * g[i] * (r[i] - q.front().first);
                    auto x = q.front(); q.pop();
                    p[i] += i - x.second;
                    if (!q.empty()) {
                        p[i] -= i - q.front().second;
                    }
                } else q.pop();
            }
            q.push({r[i], i});
        }
        cout << ans << '\n';
    }
    return 0;
}
