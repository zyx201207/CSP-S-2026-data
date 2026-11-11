#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define _pair array<int, 2>
#define For(i, l, r) for (auto i = (l); i <= (r); ++i)
#define Rep(i, r, l) for (auto i = (r); i >= (l); --i)
#define pb push_back
#define forT() {int _; for (cin >> _; _--; solve1());}
#define forTA() {int _; for (cin >> _; _--; solveA());}
template<typename T> void cmax(T& x, T y) { x = max(x, y); }
template<typename T> void cmin(T& x, T y) { x = min(x, y); }
#define N 5050
int n, f[N], dep[N], ans[N]; ll d, a[N];
vector<int> g[N];
int rt;
void dfs(int u, int fa, int w) {
    if (u >= w) dep[u] = 0;
    else dep[u] = dep[fa] + 1;
    for (auto&v : g[u]) dfs(v, u, w);
}
void solve1() {
    cin >> n >> d;
    For (i, 1, n) cin >> a[i];
    For (i, 1, n) g[i].clear();
    int R = n;
    Rep (i, n, 1) {
        while (a[R] - a[i] > d) --R;
        f[i] = R;
        if (f[i] != i) g[f[i]].pb(i);
    }
    // forest
    int res = 0;
    Rep (i, n, 1) {
        if (f[i] == i) rt = i;
        dfs(rt, 0, i);
        int L = i, R = i, sum = 0; // ??
        For (j, 1, n) ans[j] = 0;
        Rep (j, i - 1, 1) {
            if (f[j] == j) break;
            if (a[i] - a[j] <= d) continue;
            while ((dep[R] + 1 < dep[j] || a[j] + d < a[R] || R == f[j]) && R > j) sum -= ans[R--];
            while (dep[L] + 1 <= dep[j] && a[L] > a[j]) sum += ans[L--];
            // For (k, 1, n) cout << ans[k] << ' ';
            // cout << '\n';
            // cout << "debug : " << i << ' ' << rt << ' ' << j << ' ' << L << ' ' << R << ' ' << sum << '\n';
            if (sum + R - L + ans[f[j]] == 1) ans[j] = 1, ++res;
            else if (sum + R - L + ans[f[j]] > 1) ans[j] = 2;
        }
    }
    cout << res << '\n';
}
#define M 2000500
ll b[M];
void solveA() {
    cin >> n >> d;
    For (i, 1, n) cin >> b[i];
    if (n == 1) {
        cout << "0\n"; return;
    }
    ll D = b[2] - b[1];
    if (d < 2 * D) {
        cout << "0\n"; return;
    }
    cout << max(0ll, n - 2 * d / D + 1) << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c; cin >> c;
    if (c == 11 || c == 12) forTA()
    else forT();
    return 0;
}
/*
 * 0 1
5 2
1 2 3 4 5
* */
