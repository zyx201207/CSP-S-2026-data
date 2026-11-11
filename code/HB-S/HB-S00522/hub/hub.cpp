#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll t, n, c, k, fa[1000010], to[1000010][23], dep[1000010], ans;

vector<ll> E[1000010];

void dfs1(ll x, ll f) {
    fa[x] = f, to[x][0] = f, dep[x] = dep[f] + 1;
    for (ll k = 1; k <= 21; k++) to[x][k] = to[to[x][k - 1]][k - 1];
    for (ll y : E[x]) {
        if (y == f) continue;
        dfs1(y, x);
    }
}

ll lca(ll u, ll v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (ll i = 21; i >= 0; i--)
        if (dep[u] - (1ll << i) >= dep[v]) u = to[u][i];
    if (u == v) return u;
    for (ll i = 21; i >= 0; i--)
        if (to[u][i] != to[v][i]) u = to[u][i], v = to[v][i];
    return fa[u];
}

ll dis(ll u, ll v) {
    ll lc = lca(u, v);
    return dep[u] + dep[v] - 2 * dep[lc];
}

bool check(vector<ll> p) {
    ll cnt = 0;
    for (ll i = 0; i < p.size(); i++) {
        bool flag = false;
        for (ll j = 0; j < i; j++) {
            if (fa[p[i]] == p[j] || fa[p[j]] == p[i]) {
                flag = true;
                break;
            }
        }
        if (!flag) cnt++;
    }
    return cnt <= 2;
}

void dfs2(ll x, vector<ll> p, ll lst) {
    if (x == k) {
        if (!check(p)) return;
        ll nans = 0;
        for (ll i = 1; i <= n; i++) {
            ll minp = LLONG_MAX;
            for (ll j : p) minp = min(minp, dis(j, i));
            nans = max(nans, minp);
        }
        ans = min(ans, nans);
        return;
    }
    for (ll i = lst + 1; i <= n; i++) {
        p.push_back(i);
        dfs2(x + 1, p, i);
        p.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    cin >> c >> t;

    while (t--) {
        cin >> n >> k;
        for (ll i = 1; i <= n; i++) E[i].clear(), dep[i] = 0;
        for (ll i = 1; i < n; i++) {
            ll x, y; cin >> x >> y;
            E[x].push_back(y), E[y].push_back(x);
        }
        dfs1(1, 0);
        ans = LLONG_MAX;
        dfs2(0, vector<ll>(), 0);
        cout << ans << '\n';
    }

    return 0;
}
