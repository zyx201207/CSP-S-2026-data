#include <bits/stdc++.h>
using namespace std;
#define int long long

const int sN = 5010, N = 2e6 + 10;
int c, T;
int n, D, X[N];

namespace case1to10 {
vector<int> g[sN];
int d[sN], f[sN][sN];
struct node {
    int u, w;
    node() { }
    node(int u, int w) : u(u), w(w) { }
} ;
void bfs(int k) {
    for (int i = 1; i <= n; i++) {
        d[i] = 9e18;
    }
    queue<node> q;
    q.push(node(k, 0));
    f[k][k] = 1;
    while (!q.empty()) {
        int u = q.front().u, w = q.front().w; q.pop();
        for (int v : g[u]) {
            if (d[v] > w + 1) {
                d[v] = w + 1;
                f[k][v] = f[k][u];
                q.push(node(v, w + 1));
            } else if (d[v] == w + 1) {
                f[k][v] += f[k][u];
            }
        }
    }
}
void solve() {
    cin >> n >> D;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
    }
    for (int i = 1; i <= n; i++) {
        cin >> X[i];
        for (int j = i - 1; j; j--) {
            if (X[i] - X[j] > D) {
                break ;
            }
            g[i].push_back(j);
            g[j].push_back(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        bfs(i);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (f[i][j] == 2) {
                ans++;
            }
            f[i][j] = f[j][i] = 0;
        }
    }
    cout << ans << endl;
}
}

namespace case11to12 {
void solve() {
    cin >> n >> D;
    for (int i = 1; i <= n; i++) {
        cin >> X[i];
    }
    int d = X[2] - X[1], a = D / d, ans = 0;
    if (a < 2 || 2 * a > n) {
        cout << 0 << endl;
        return ;
    }
    ans = n - 2 * a + 1;
    cout << ans << endl;
}
}

signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> c >> T;
    if (c <= 10) {
        while (T--) {
            case1to10::solve();
        }
    } else {
        while (T--) {
            case11to12::solve();
        }
    }
    return 0;
}
