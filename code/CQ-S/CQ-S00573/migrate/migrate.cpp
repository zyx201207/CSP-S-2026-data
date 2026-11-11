#include <bits/stdc++.h>
#define all(x) x.begin (), x.end ()
#define x first
using namespace std;
using ll = long long;
using db = double;
const ll INF = ll (1e18) + 7;

template <typename T>
inline void cmax (T &a, const T &b) {if (a < b) a = b;}
template <typename T>
inline void cmin (T &a, const T &b) {if (a > b) a = b;}

void init () {

}

void solve () {
    int n; ll d; cin >> n >> d;
    vector <ll> a (n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector <int> lst (n + 1, 0);
    for (int p1 = n, p2 = n; p2 >= 1; p2--) {
        while (p1 >= 1 && a[p2] - a[p1] <= d) p1--;
        lst[p2] = p1 + 1;
    }

    // for (int i = 1; i <= n; i++) cout << lst[i] << ' ';
    // cout << '\n';

    vector <vector <int>> e (n + 1, vector <int> (0, 0));
    for (int i = n; i >= 1; i--) if (lst[i] != i)
        e[lst[i]].push_back (i);

    // for (int i = 1; i <= n; i++) {
    //     cout << i << " : ";
    //     for (auto v : e[i]) cout << v << ' ';
    //     cout << '\n';
    // }
    // cout << '\n';

    vector <ll> dp (n + 1, 0), ndp (n + 1, 0);
    vector <int> vis (n + 1, 0);
    auto dfs = [&](auto &&self, int u, int fa) -> void {
        vis[u] = 1;
        for (auto v : e[u]) self (self, v, u);
        ndp[u] = (e[u].size () ? ndp[e[u][0]] : 1) + e[u].size ();

        for (int i = e[u].size () - 2; i >= 0; i--) dp[e[u][i]] += dp[e[u][i + 1]];

        if (e[u].size () == 1) dp[u] = dp[e[u][0]];

        if (e[u].size () >= 2) {
            int id = -1;
            for (int i = 1; i < e[u].size (); i++) if (e[e[u][i]].size ()) {
                id = e[u][i];
                break;
            }

            if (id != -1) dp[id] += (e[id].size () == 1 ? ndp[e[u][0]] - 1 : 0);
        }

        if (e[u].size () >= 2) dp[u] += ndp[e[u][1]] - 1;
        if (e[u].size () >= 3) {
            int id = e[u].back ();
            if (e[id].size () == 0 && e[e[u][0]].size () == 0) dp[id] += ndp[e[u][1]] - 1;
            else if (e[id].size () == 0) dp[id] += e[e[u][1]].size ();
        }
    };

    for (int i = 1; i <= n; i++) if (!vis[i])
        dfs (dfs, i, 0);
    
    ll ans = 0;
    for (int i = 1; i <= n; i++) ans += dp[i];
    cout << ans << '\n';

    // for (int i = 1; i <= n; i++) cout << dp[i] << ' ';
    // cout << '\n';
}

int main () {
#ifndef ONLINE_JUDGE
    freopen ("migrate.in", "r", stdin);
    freopen ("migrate.out", "w", stdout);
#endif
    ios :: sync_with_stdio (0);
    cin.tie (0), cout.tie (0);

    init ();

    int t = 1, c;
    cin >> c >> t;
    while (t--) solve ();

    return 0;
}