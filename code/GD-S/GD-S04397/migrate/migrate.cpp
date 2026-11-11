#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 2000010;
int n;
ll d, x[N], ans;
int nxt[N], f[N];
int num0[N], num1[N];
vector<int> g[N];
void dfs(int u, int fa) {
    f[u] = fa;
    for (int v : g[u]) {
        dfs(v, u);
    }
    if (!fa) return ;
    // 计算终点在 (u, fa] 这段区间的答案
    num0[u]++;
    for (int v1 : g[u]) {
        for (int v2 : g[v1]) {
            // 早就处理好了到 u 的贡献
            // 先计算 v2 - v1 - u 是否爆炸
            int num = 0;
            if (x[u] - x[v1 - 1] <= d) num++;
            if (v1 - 2 > v2 && x[u] - x[v1 - 2] <= d) num++;

            int c0 = 0, c1 = 0;
            if (num == 0) {
                c0 = num0[v2], c1 = num1[v2];
            } else if (num == 1) {
                c1 = num0[v2];
            }

            if (x[u - 1] - x[v1 - 1] > d && c0) {
                if (u - 2 > v1) {
                    int p = upper_bound(x + u + 1, x + 1 + fa, d + x[u - 1]) - x - 1;
                    int q = upper_bound(x + u + 1, x + 1 + fa, d + x[u - 2]) - x;
                    ans += 1ll * c0 * (p - q + 1);
                } else {
                    int p = upper_bound(x + u + 1, x + 1 + fa, d + x[u - 1]) - x - 1;
                    ans += 1ll * c0 * (p - u);
                }
            }

            if (c1) {
                int p = upper_bound(x + u + 1, x + 1 + fa, d + x[u - 1]) - x;
                ans += 1ll * c1 * (fa - p + 1);
            }

            // 添加 v2 ~ fa 的贡献，加到 v1 上
            if (x[fa] - x[u - 1] <= d && x[u - 1] - x[v1 - 1] <= d) {
                // v2 废了
            } else {
                if (num == 0) {
                    // 继续继承
                    num0[v1] += num0[v2];
                    num1[v1] += num1[v2];
                } else if (num == 1) {
                    num1[v1] += num0[v2];
                }
            }
        }

        if (u - 2 > v1) {
            int p = upper_bound(x + u + 1, x + 1 + fa, d + x[u - 1]) - x - 1;
            int q = upper_bound(x + u + 1, x + 1 + fa, d + x[u - 2]) - x;
            ans += 1ll * (p - q + 1);
        } else {
            int p = upper_bound(x + u + 1, x + 1 + fa, d + x[u - 1]) - x - 1;
            ans += 1ll * (p - u);
        }
    }
}
void solve() {
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        g[i].clear();
        num0[i] = num1[i] = 0;
    }
    ans = 0;
    int pos = 1;
    for (int i = 1; i <= n; i++) {
        while (pos < n && x[pos + 1] - x[i] <= d) pos++;
        if (pos == i) nxt[i] = -1;
        else {
            nxt[i] = pos;
            g[pos].push_back(i);
        }
    }
    for (int i = 1; i <= n; i++) if (nxt[i] == -1) {
        dfs(i, 0);
    }
    cout << ans << "\n";
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, T;
    cin >> c >> T;
    while (T--) solve();
}