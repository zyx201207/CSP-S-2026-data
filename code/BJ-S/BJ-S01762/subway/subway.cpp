#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mxM = 5e5 + 5;
ll mp[505][505];
ll wi[mxM];
int tij[505][mxM];
vector<pair<int, ll>> lnfst[mxM];
int c, n, d, m, q;
#define For(i) for (int i = 1; i <= n; ++i)
void floyd() {
    For(k) For(i) For(j)
        mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
}

#define upd(a, b, v) mp[a][b] = mp[b][a] = min(mp[a][b], v)

int main() {
    cin.tie(0)->sync_with_stdio(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; ++i)
        cin >> wi[i];
    for (int i = 1; i <= n; ++i) {
        ll k, a, t;
        cin >> k;
        while (k--) {
            cin >> a >> t;
            tij[i][a] = t;
            lnfst[a].push_back({i, t});
        }
    }
    memset(mp, 0x3f, sizeof(mp));
    for (int i = 1; i <= n; ++i)
        mp[i][i] = 0;
    for (int i = 1; i <= m; ++i) {
        for (auto &a : lnfst[i])
            for (auto &b : lnfst[i])
                if (a == b)
                    continue;
                else
                    upd(a.first, b.first, a.second + b.second);
    }
    floyd();
    while (q--) {
        int x, y;
        cin >> x >> y;
        ll pa = 0x3f3f3f3f3f3f3f3f;
        for (auto &sa : lnfst[x]) {
            for (auto &eb : lnfst[y]) {
                pa = min(pa, sa.second + eb.second + mp[sa.first][eb.first]);
            }
        }
        cout << pa + wi[x] + wi[y] << '\n';
    }
}
