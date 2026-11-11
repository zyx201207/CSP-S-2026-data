#include <bits/stdc++.h>
using namespace std;

const int N = int(1e6) + 10;

vector<int> g[N];
int n, k, p[N], res, val[N];
bool tg[N];

void Color(int x, int fa) {
    if (tg[x]) return;
    tg[x] = true;
    for (int i : g[x]) if (i != fa && p[i])
        Color(i, x);
}
void Calc(int x, int fa, int dis) {
    //cout << x << ' ' << dis << '\n';
    val[x] = min(val[x], dis);
    for (int i : g[x]) if (i != fa)
        Calc(i, x, dis + 1);
}
void Dfs(int x, int c) {
    if (x > n) {
        if (c == k) {
            for (int i = 1; i <= n; i++) {
                tg[i] = false;
                val[i] = 0x3f3f3f3f;
            }
            int tot = 0;
            for (int i = 1; i <= n; i++) {
                if (p[i] && !tg[i]) {
                    Color(i, 0);
                    tot++;
                }
            }
            if (tot <= 2) {
                //for (int i = 1; i <= n; i++) cout << p[i] << " \n"[i == n];
                int tmp = 0;
                for (int i = 1; i <= n; i++)
                    if (p[i]) Calc(i, 0, 0);
                for (int i = 1; i <= n; i++) tmp = max(tmp, val[i]);
                //cout << tmp << '\n';
                res = min(res, tmp);
            }
        }
        return;
    }
    p[x] = 0;
    Dfs(x + 1, c);
    p[x] = 1;
    Dfs(x + 1, c + 1);
}
void Solve() {
    cin >> n >> k;
    for (int i = 2; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    res = 0x3f3f3f3f;
    Dfs(1, 0);
    for (int i = 1; i <= n; i++) g[i].clear();
    cout << res << '\n';
}
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c, t;
    cin >> c >> t;
    while (t--) Solve();

    return 0;
}