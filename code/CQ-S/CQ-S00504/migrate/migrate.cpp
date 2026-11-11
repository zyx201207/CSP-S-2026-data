#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
#define endl '\n'
#define eb emplace_back
#define pb push_back
#define all(x) x.begin(), x.end()
/*
直接算 g(u, v) = 2 的点感觉太困难了啊

g(u, x) = g(x, v) = g(u, y) = g(y, v) = 1

且 x, y 只能存在一对

x 为 u -> v 最短路上的点

想想能不能换个信息去求解？

每段的方案数应该是一个递减的东西

等价于 to[i][len - 1] - to[i][len - 2] 这一段是 g 恰好为 2 的部分
然后接着用 to[i][len - 1] + 1 ~ a[i + 1][len - 1] 去更新新的一段
若 某个端点 calc > 2 了：

先将 i + 1 段的全部设为 2，然后看 to[i][len - 1] + 1 ~ a[i + 1][len] 这一些

有一个 n ^ 2 做法
对每个 st 这样扫一遍
能不能倒过来做这样的话，同一个链上信息可以复用
有点困难啊
因为你这里是向后推的
还有两个半小时
*/
const int N = 2e6 + 10;
int n, test_id;
ll a[N], d;
int to[N], v1[N], v2[N];
bool mark[N], mark2[N];
vector<int> g[N];
int fa[N][23];
bool hav[N][23], hav2[N][23];
int sv1[N], sv2[N];
void dfs (int u, int from) {
    for (int v : g[u]) dfs(v, u);
}
int dep[N];

void sol() {
    cin >> n >> d;
    for (int i = 1; i <= n; i ++) cin >> a[i], g[i].clear();
    for (int i = 1; i <= n; i ++) {
        to[i] = upper_bound(a + 1, a + 1 + n, a[i] + d) - a - 1;
        if (a[n] <= a[i] + 1) to[i] = n;
        // cout << to[i] << ' ';
    }
    // cout << endl;
    for (int i = n; i >= 1; i --) {
        int r = to[i];
        dep[i] = dep[r] + 1;
        mark[i] = (to[i - 1] == r);
        mark2[i] = (r - 1 > i && to[r - 1] == to[r] - 1);
        hav[i][0] = (mark[i] | mark[r]);
        hav2[i][0] = (mark2[i] | mark2[r]);
        if (r > i + 1) {
            v1[i] = to[r - 1] - to[r - 2];
        } else v1[i] = 0;
        v2[i] = to[r] - to[r - 1];
        fa[i][0] = r;
        sv1[i] = sv1[r] + v1[i];
        sv2[i] = sv2[r] + v2[i];
        for (int k = 1; k <= 21; k ++)
            fa[i][k] = fa[fa[i][k - 1]][k - 1], 
            hav[i][k] = (hav[i][k - 1] | hav[fa[i][k - 1]][k - 1]),
            hav2[i][k] = (hav2[i][k - 1] | hav2[fa[i][k - 1]][k - 1]);
    }
    if (n <= 5000) {
        ll ans = 0;
        for (int i = 1; i <= n; i ++) {
            bool flag = 0;
            // cerr << i << endl;
            for (int u = i; u != to[u]; u = to[u]) {
                int r = to[u];
                if (!flag) {
                    if (r - 1 > u) {
                        ans +=  to[r - 1] - to[r - 2];
                        if (!flag && to[r - 1] == to[r] - 1) {
                            // cout << "v1! " << i << ' ' << u << endl;
                            break;
                        }
                        if (to[r - 1] == to[r]) {
                            flag = 1;
                            // cout << "v1 " << i << ' ' << r << endl;
                            if (to[r - 2] == to[r]) break;
                            // calc[r] = 3 了
                        }
                    }
                } else {
                    // calc[r] = 2 了
                    ans += to[r] - to[r - 1];
                    if (to[r - 1] == to[r]) {
                        // cout << "v2 " << i << ' ' << r << endl;
                        break;
                    }
                }
            }
            // cout << ans << endl;
        }
        cout << ans << endl;
    } else {
        ll ans = 0;
        for (int i = 1; i <= n; i ++) {
            int u = to[i], w = i;
            if (!mark[u]) {
                for (int k = 21; k >= 0; k --) if (!hav[u][k]) u = fa[u][k];
                u = to[u];
            }
            if (!mark2[w]) {
                for (int k = 21; k >= 0; k --) if (!hav2[w][k]) w = fa[w][k];
                w = to[w];
            } 
            if (dep[w] > dep[u]) {            
                // cout << "v1! " << i << ' ' << w << endl;
                ans += sv1[i] - sv1[w] + v1[w];
                // cout << ans << endl;
                continue;
            }
            ans += sv1[i] - sv1[u];
            // cout << "v1 " << i << ' ' << u << endl;
            if (to[u - 2] == to[u]) {
                // cout << ans << endl;
                continue;
            }
            int v = to[u];
            if (!mark[v]) {
                for (int k = 21; k >= 0; k --) if (!hav[v][k]) v = fa[v][k];
                v = to[v];
            }
            // cout << "v2 " << i << ' ' << v << endl;
            ans += sv2[u] - sv2[v];
            // cout << ans << endl;
        }
        cout << ans << endl;
    }
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> test_id >> t;
    while (t --) sol();
    cerr << "----TIMES: " << clock();
    return 0;
}
// 谨记：空间一定要算一遍大小；大样例过了一定要回测小样例；造corner case测边界；不要死磕！！
// 注意时间安排
// trust your self
// 他妈的我破防了，为啥啊，T3 做了 2小时觉得很对的正解结果 migrate5 migrate6 答案小得多？？？
// 小样例又tm测不出来