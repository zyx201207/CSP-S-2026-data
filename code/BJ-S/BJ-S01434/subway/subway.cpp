#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e3 + 5;
ll m, w[N], dis[N][N], js[N], jss = 0, a[N], t[N];
vector <ll> g[N];
void cun(ll n) {
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        js[a[i]]++;
        ll yai = 0;
        if (js[a[i]] > 1) {
            jss++;
            yai = a[i];
            g[a[i]].push_back(m + jss);
            a[i] = m + jss;
        }
        cin >> t[a[i]];
        //cout << a[i] << ' ' << t[a[i]] << ' ' << '\n';
        if (js[yai] > 1) {
            dis[yai][a[i]] = t[a[i]];
            dis[a[i]][yai] = t[yai];
            for (auto j : g[yai]) {
                if (j == a[i]) {
                    continue;
                }
                dis[j][a[i]] = t[a[i]];
                dis[a[i]][j] = t[j];
            }
        }
    }
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            if (i == j) {
                continue;
            }
            dis[a[i]][a[j]] = t[a[j]];
            //cout << a[i] << ' ' << a[j] << ' ' << j << ' ' << t[j] << ' ' << dis[a[i]][a[j]] << '\n';
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ll c, n, d, q;
    cin >> c >> n >> m >> d >> q;
    for (ll i = 1; i <= 2 * m; i++) {
        for (ll j = 1; j <= 2 * m; j++) {
            dis[i][j] = 1e18;
        }
    }
    for (ll i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for (ll i = 1; i <= n; i++) {
        ll k;
        cin >> k;
        cun(k);
    }
    for (ll k = 1; k <= m + jss; k++) {
        for (ll i = 1; i <= m + jss; i++) {
            for (ll j = 1; j <= m + jss; j++) {
                if (i == j) {
                    continue;
                }
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    /*
    for (ll i = 1; i <= m + jss; i++) {
        for (ll j = 1; j <= m + jss; j++) {
            cout << dis[i][j] << ' ';
        }
        cout << '\n';
    }
    for (ll i = 1; i <= m + jss; i++) {
        cout << t[i] << ' ';
    }
    cout << '\n';
    */
    while (q--) {
        ll x, y;
        cin >> x >> y;
        ll minn = dis[x][y], minx = x;
        for (auto i : g[x]) {
            for (auto j : g[y]) {
                if (dis[i][j] < minn) {
                    minn = dis[i][j];
                    minx = i;
                }
            }
        }
        cout << minn + w[x] + w[y] + t[minx] << '\n';
    }
    return 0;
}
