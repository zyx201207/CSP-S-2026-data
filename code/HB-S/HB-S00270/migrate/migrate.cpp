#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll c, t, n, d, x[2000005];
queue<pair<ll, ll>> q;

bool check(int a, int b) {
    ll ans = 0;
    while (!q.empty())
        q.pop();
    q.push({a, 0});
    while (!q.empty()) {
        ll u = q.front().first, t = q.front().second;
        if (u == b) {
            while (!q.empty() && q.front().second == t)
                ans++;
            break;
        }
        for (int i = u + 1; i < n && x[i] - x[u] <= d; i++)
            q.push({i, t + 1});
    }
    return ans == 2;
}

int main() {
    // freopen("migrate.in", "r", stdin);
    // freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t--) {
        ll ans;
        cin >> n >> d;
        for (int i = 0; i < n; i++)
            cin >> x[i];
        cout << ans << "\n";
    }
    return 0;
}
