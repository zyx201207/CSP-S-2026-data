#include <bits/stdc++.h>
#define rep(i,j,k) for (int i = (j); i <= (k); i++)
#define rrep(i,j,k) for (int i = (j); i >= (k); i--)
#define orep(i,j,k) for (int i = (j); i < (k); i++)
#define fi first
#define se second
using namespace std;
using ll = long long;
using pii = pair<int, int>;
template <class T>
using vec = vector<T>;
using veci = vec<int>;

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int C, n, m, D, Q;
    cin >> C >> n >> m >> D >> Q;
    vec<vec<pii>> a(m+1);
    veci w(m+1);
    rep(i, 1, m) {
        cin >> w[i];
    }
    rep(i, 1, n) {
        int K;
        cin >> K;
        rep(_, 1, K) {
            int x, y;
            cin >> x >> y;
            a[x].push_back({i, y});
        }
    }
    vec<vec<ll>> dis(n+1, vec<ll>(n+1, 1e18));
    rep(i, 1, m) {
        for (pii j : a[i]) for (pii k : a[i]) {
            if (j.fi == k.fi) continue;
            dis[j.fi][k.fi] = min(dis[j.fi][k.fi], (ll)j.se + k.se);
        }
    }
    rep(i, 1, n) dis[i][i] = 0;
    rep(k, 1, n) rep(i, 1, n) rep(j, 1, n) {
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    }
    rep(_, 1, Q) {
        int x, y;
        cin >> x >> y;
        ll ans = 1e18;
        for (pii i : a[x]) for (pii j : a[y]) {
            ans = min(ans, dis[i.fi][j.fi] + i.se + j.se);
        }
        cout << ans + w[x] + w[y] << '\n';
    }
}