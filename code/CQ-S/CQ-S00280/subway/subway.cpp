#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
const int E = 1e6 + 5;

struct node{ll x, y, z, p;};

int main() {
    freopen("subway.in", "r", stdin); freopen("subway.out", "w", stdout);
    ll c, n, m, d, q; cin >> c >> n >> m >> d >> q;

    vector<ll> w(m + 1);
    for (int i = 1; i <= m; i++) cin >> w[i];
    vector<vector<ll>> a(n + 1), t(n + 1); vector<ll> siz(n + 1); map<pair<ll, ll>, ll> mp1;
    for (int i = 1; i <= n; i++) {
        ll k; cin >> k; a[i].resize(k + 1); t[i].resize(k + 1); siz[i] = k;
        for (int j = 1; j <= 2 * k; j++) if (j & 1) cin >> a[i][j / 2 + 1], mp1[{i, a[i][j / 2 + 1]}] = j / 2; else cin >> t[i][j / 2];
        // for (int j = 1; j <= k; j++) cerr << a[i][j] << ' ';
        // cerr << endl;
        // for (int j = 1; j <= k; j++) cerr << t[i][j] << ' ';
        // cerr << endl;
    }


    vector<vector<pair<ll, ll>>> edge(m + 1);
    for (int i = 1; i <= n; i++) for (int l = 1; l <= siz[i]; l++) for (int r = 1; r <= siz[i]; r++) if (l != r) edge[a[i][l]].push_back({a[i][r], i});

    while (q--) {
        ll l, r; cin >> l >> r;
        ll ans = 1e18;
        map<pair<ll, pair<ll, pair<ll, ll>>>, bool> mp;
        auto dfs = [&](auto &&self, ll u, ll u_id, ll fa, ll fa_id, ll sum) -> void {
            if (u == r) {ans = min(ans, sum + t[u_id][mp1[{u_id, u}]]); return;}
            if (mp[{u, {u_id, {fa, fa_id}}}]) return;
            mp[{u, {u_id, {fa, fa_id}}}] = 1;

            for (auto tmp : edge[u]) {
                ll v = tmp.first, id = tmp.second;
                if (v == fa) continue;
                if (id != u_id && u_id != 0) self(self, v, id, u, u_id, sum + t[id][mp1[{id, v}]] + t[u_id][mp1[{u_id, v}]]);
                else self(self, v, id, u, u_id, sum);
            }
        };

        for (int i = 1; i <= n; i++) for (int j = 1; j <= siz[i]; j++) if (a[i][j] == l) dfs(dfs, l, i, 0, 0, 0);

        // cerr << w[l] << ' ' << w[r] << endl;
        cout << ans + w[l] + w[r] << endl;
    }
    return 0;
}