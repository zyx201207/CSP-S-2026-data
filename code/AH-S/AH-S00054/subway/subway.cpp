#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define _pair array<int, 2>
#define For(i, l, r) for (auto i = (l); i <= (r); ++i)
#define Rep(i, r, l) for (auto i = (r); i >= (l); --i)
#define pb push_back
#define forT() int _; for (cin >> _; _--; solve())
template<typename T> void cmax(T& x, T y) { x = max(x, y); }
template<typename T> void cmin(T& x, T y) { x = min(x, y); }
#define N 550
#define M 500500
int n, m, d, q;
ll g[N][N], W[M];
vector<_pair> sta[M];
void solve() {
    cin >> n >> m >> d >> q;
    For (i, 1, m) cin >> W[i];
    For (i, 1, n) {
        int k; cin >> k;
        while (k--) {
            int x, y; cin >> x >> y;
            sta[x].pb({i, y});
        }
    }
    memset(g, 0x3f, sizeof g);
    For (i, 1, n) g[i][i] = 0;
    For (i, 1, m) {
        for (auto&[i1, d1] : sta[i])
            for (auto&[i2, d2] : sta[i]) {
                cmin(g[i1][i2], (ll)d1 + d2);
            }
    }
    For (k, 1, n) For (i, 1, n) For (j, 1, n) 
        cmin(g[i][j], g[i][k] + g[k][j]);
    while (q--) {
        int x, y; cin >> x >> y;
        ll ans = 1e18;
        for (auto&[i1, d1] : sta[x])
            for (auto&[i2, d2] : sta[y]) cmin(ans, d1 + g[i1][i2] + d2);
        cout << W[x] + W[y] + ans << '\n';
    }
} 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c; cin >> c;
    solve();
    return 0;
}