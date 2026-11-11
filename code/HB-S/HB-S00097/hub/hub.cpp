// hub
#include <iostream>
#include <vector>
using namespace std;

const int N = 1e6 + 1023;
int c, t, n, k, f[4005], dis;
bool e[4005][4005], mark[4005];
vector<int> tr[N];

bool check(int d) {
    int st = d, ed = (n + 1) / 2 - d;
    if (st >= ed) return 1;
    int cnt = 2;
    while (cnt < k && (ed - st) / 2 + 1 > d) {
        --ed;
        ++cnt;
    }
    return (ed - st) / 2 + 1 <= d;
}

void solveA() {
    int l = 1, r = n, res = n;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << res << '\n';
}

int getf(int u) {
    if (f[u] == u) return u;
    return f[u] = getf(f[u]);
}

void dfs(int u, int fa, int dep) {
    if (mark[u]) {
        dis = min(dis, dep);
        return;
    }
    for (int v : tr[u]) {
        if (v == fa) continue;
        dfs(v, u, dep + 1);
    }
}

void solve_bf() {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            e[i][j] = 0;
    for (int i = 1; i <= n; ++i)
        for (int j : tr[i])
            e[i][j] = 1;
    int ans = n;
    for (int s = 0; s < (1 << n); ++s) {
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            mark[i] = 0;
            f[i] = i;
            if ((1 << (i - 1)) & s) ++cnt;
        }
        if (cnt != k) continue;
        for (int i = 1; i <= n; ++i)
            if ((1 << (i - 1)) & s)
                mark[i] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (mark[i] & mark[j] & e[i][j]) {
                    int x = getf(i), y = getf(j);
                    if (x != y) f[x] = y;
                }
            }
        }
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            dis = n + 1;
            dfs(i, 0, 0);
            res = max(res, dis);
        }
        cnt = 0;
        for (int i = 1; i <= n; ++i) mark[i] = 0;
        for (int i = 1; i <= n; ++i) {
            if ((1 << (i - 1)) & s) {
                if (!mark[getf(i)]) {
                    mark[getf(i)] = 1;
                    ++cnt;
                }
            }
        }
        if (cnt <= 2) ans = min(ans, res);
    }
    cout << ans << '\n';
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) tr[i].clear();
        for (int i = 1, u, v; i < n; ++i) {
            cin >> u >> v;
            tr[u].push_back(v);
            tr[v].push_back(u);
        }
        if (n == k) {
            puts("0");
            continue;
        }
        if (c == 13 || c == 14) solveA();
        else if (n <= 10) solve_bf();
    }
    return 0;
}
