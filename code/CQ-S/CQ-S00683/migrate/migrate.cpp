#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e6 + 10;
// const ll MOD = 998244353;

int caseid, tt, n;

ll d, pos[MAXN], dis[MAXN], ans = 0;

// void init() {

// }

vector<int> miku;

int fa[MAXN], typ[MAXN], siz[MAXN];
ll f[MAXN], g[MAXN];

void solve(int L, int R) {
    if (R - L <= 2) return;
    miku.clear();
    // ans = 0;
    for (int i = L; i <= R; i++) fa[i] = typ[i] = siz[i] = 0, f[i] = g[i] = 0;
    fa[R] = R;
    int j = L;
    for (int i = L; i < R; i++) {
        while (j <= R && pos[j] - pos[i] <= d) j++;
        fa[i] = j - 1;
        f[fa[i]]++;
        if (siz[fa[i]] == 0) {
            // the deepest
            typ[i] = 1;
            f[fa[i]] += f[i];
            g[fa[i]] += g[i];
        } else if (siz[fa[i]] == 1) {
            typ[i] = 2;
            // the second deepest
            g[fa[i]] += f[i];
        }
        siz[fa[i]]++;
    }
    j = L;
    // for (int i = L; i <= R; i++) {
    //     cerr << i << " " << fa[i] << " " << typ[i] << " " << f[i] << ' ' << g[i] << "\n";
    // }
    for (int i = L; i <= R; i++) {
        while (j < i && pos[i] - pos[j] > d) j++;
        // cout << i << " " << typ[i] << " " << g[i] << "\n";
        if (typ[i] == 1) {
            ans += g[i];
            continue;
        }
        else {
            if (j < i && typ[j] == 1) ans += g[j];
        }
        if (j + 1 < i) {
            ans += f[j + 1];
        }
        // cerr << i << " " << ans << "\n";
    }
}

void solve() {
    ans = 0;
    cin >> n >> d;
    for (int i = 1; i <= n; i++) cin >> pos[i], dis[i] = pos[i] - pos[i - 1];
    for (int i = 1; i <= n; i++) {
        int j = i;
        while (j < n && dis[j + 1] <= d) j++;
        solve(i, j);
        i = j;
    }
    cout << ans << "\n";
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> caseid >> tt;
    while (tt--) solve();
    return 0;
}