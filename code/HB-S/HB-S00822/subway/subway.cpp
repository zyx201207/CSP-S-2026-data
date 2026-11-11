#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 505, MAXM = 50005;
ll c, m, n, d, q, w[MAXM], k[MAXN], a[MAXN][MAXM], t[MAXN][MAXM], x[MAXM], y[MAXM];
bool vis[MAXM];
ll f[MAXM];

vector<pair<ll, ll>> findline(ll id) {
    vector<pair<ll, ll>> ret;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k[i]; ++j) {
            if (a[i][j] == id) ret.push_back(make_pair(i, j));
        }
    }
    return ret;
}

void dfs(ll pos, ll target) {

    if (pos == target) return;
    vector<pair<ll, ll>> lines = findline(pos);
    for (pair<ll, ll> p : lines) {
        if (2 <= p.second && p.second <= k[pos] - 1) {
            ll next = p.second - 1;
            if (!vis[next]) {
                vis[next] = true;
                f[a[p.first][next]] = min(f[a[p.first][next]], f[pos] + t[p.first][pos]);
                dfs(a[p.first][next], target);
                vis[next] = false;
            }
            next = p.second + 1;
            if (!vis[next]) {
                vis[next] = true;
                f[a[p.first][next]] = min(f[a[p.first][next]], f[pos] + t[p.first][pos]);
                dfs(a[p.first][next], target);
                vis[next] = false;
            }
        }
    }
}

int main() {

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> c >> m >> n >> d >> q;
    for (int i = 1; i <= m; ++i) cin >> w[i];
    for (int i = 1; i <= n; ++i) {
        cin >> k[i];
        for (int j = 1; j <= k[i]; ++j) cin >> a[i][j] >> t[i][j];
    }
    for (int i = 1; i <= q; ++i) cin >> x[i] >> y[i];

    for (int i = 1; i <= m; ++i) {
        memset(f, 0x3f3f3f, sizeof(f));
        f[x[i]] = w[x[i]] + w[y[i]];
        dfs(x[i], y[i]);
        cout << f[y[i]];
    }

    return 0;
}
