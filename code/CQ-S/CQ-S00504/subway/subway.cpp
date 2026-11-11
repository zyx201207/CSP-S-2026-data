#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
#define endl '\n'
#define eb emplace_back
#define pb push_back
#define all(x) x.begin(), x.end()
/*
这里，d = 20

换乘需要时间

a[0] -t[i]-> a[i]
类似于换线时长为 t[x][i] + t[y][i]，入站出站可以理解为 0 号线和 n + 1 号线？不太行

n 只有 500

我们可以算出两两线路之间换乘的最小时间是不是？

min(t[x][i] + t[y][i])

但是要多次查询的话，又需要 floyd，这不能跑过吧

ans = min(w[st] + t[x][st] + dis[x][y] + t[y][ed] + w[ed])

d^2 枚举可以过

现在要点就是怎么求 dis[x][y]，欸不对 n = 500 floyd 不是随便过

*/
int c, n, m, d, q;
ll dis[550][550];
int w[500010];
int len[550];
vector<pi> to[500010];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i ++) cin >> w[i];
    for (int i = 1; i <= n; i ++) {
        int siz;
        cin >> siz;
        while (siz --) {
            int x, y;
            cin >> x >> y;
            to[x].eb(i, y);
        }
    }
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++)
    if (i != j) dis[i][j] = 1e18;
    for (int i = 1; i <= m; i ++) {
        int siz = to[i].size();
        sort(to[i].begin(), to[i].end());
        for (int x = 0; x < siz; x ++) {
            for (int y = x + 1; y < siz; y ++) {
                pi u = to[i][x], v = to[i][y];
                // cout << i << ' ' << u.first << ' ' << v.first << endl;
                dis[u.first][v.first] = min(dis[u.first][v.first], (ll)u.second + v.second);
            }
        }
    }
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j < i; j ++)
            dis[i][j] = dis[j][i];
    for (int k = 1; k <= n; k ++)
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++) 
                dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
    while (q --) {
        int st, ed;
        cin >> st >> ed;
        ll ans = 1e18;
        for (pi x : to[st])
            for (pi y : to[ed])
                ans = min(ans, w[st] + x.second + dis[x.first][y.first] + y.second + w[ed]);
        cout << ans << endl;
    }
    cerr << "----TIMES: " << clock();
    return 0;
}
// 谨记：空间一定要算一遍大小；大样例过了一定要回测小样例；造corner case测边界；不要死磕！！
// 注意时间安排
// trust your self




















/*
我成功设计出来了 2147483647 只蚂蚁！
*/