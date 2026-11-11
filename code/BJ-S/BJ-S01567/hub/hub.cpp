#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int n, k;
vector<int> g[N];
int d[N], f[N][20], dep[N];
bool flag[N], vis[N];

void dfs(int u, int pa) {
    d[u] = d[pa] + 1;
    f[u][0] = pa;
    for (int i = 1; i <= 15; i++) {
        f[u][i] = f[f[u][i - 1]][i - 1];
    }
    for (int v : g[u]) {
        if (v == pa) {
            continue;
        }
        dfs(v, u);
    }
}

int lca(int u, int v) {
    if (d[u] < d[v]) {
        swap(u, v);
    }
    for (int i = 15; i >= 0; i--) {
        if (d[f[u][i]] >= d[v]) {
            u = f[u][i];
        }
    }
    if (u == v) {
        return u;
    }
    for (int i = 15; i >= 0; i--) {
        if (f[u][i] != f[v][i]) {
            u = f[u][i], v = f[v][i];
        }
    }
    return f[u][0];
}

int dist(int u, int v) {
    return d[u] + d[v] - 2 * d[lca(u, v)];
}

void flood_fill(int u) {
    vis[u] = true;
    for (int v : g[u]) {
        if (!vis[v] && flag[v]) {
            flood_fill(v);
        }
    }
}

int cal(int s) {
    for (int i = 1; i <= n; i++) {
        flag[i] = (s >> (i - 1)) & 1;
        // cout << flag[i];
        vis[i] = false;
    }
    // cout << endl;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (flag[i] && !vis[i]) {
            cnt++;
            flood_fill(i);
        }
    }
    if (cnt > 2) {
        return 2e9;
    }
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        if (flag[i]) {
            continue ;
        }
        int mn = 1e9;
        for (int j = 1; j <= n; j++) {
            if (flag[j]) {
                mn = min(mn, dist(i, j));
            }
        }
        mx = max(mx, mn);
    }
    return mx;
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
    }
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    int ans = 2e9;
    for (int s = 0; s < (1 << n); s++) {
        if (__builtin_popcount(s) != k) {
            continue ;
        }
        ans = min(ans, cal(s));
    }
    cout << ans << endl;
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, T;
    cin >> c >> T;
    while (T--) {
        solve();
    }
    return 0;
}

/*
一年又一年
距离结束还有17分钟，估分100+92+32+15=239，应该不会再挂了，大样例测完了，都过了，可是我还是好慌
总是想要去在这里留下点什么，写点什么，但我确实不知道写什么了
第一题应该是个黄吧，很标准的黄，我觉得不会降橙的，但是感觉还是比去年简单了不少，可惜我一开始写了个单调栈耽误了挺长时间，然后还读错题了以为是一个连续的区间，不过问题不加个排序就过了，还是比去年过t1轻松不少
后面三题都偏图论，赚了，第二题是一个绿吧，我觉得到不了青，我做得这么快一定是个绿
第三题好像很可做的样子，正解应该是个DP，不过我不会我只会N^2的做法，特殊性质B看起来很好做，但是头很疼想不出来了，应该是个青或者蓝
第四题应该是个紫吧，总感觉是个贪心+树形DP，但是我也不会，2^n的15分拿走就跑路了
第二题应该不会被卡吧 毕竟这个机器好慢，可惜没给最大的大样例，我确实不会卡常了，不过就算被卡也只有8分吧
第三题没给n^2的大样例，最终幻想一下n^2对了就是48分，万一呢，不过没有什么奇迹把
万一呢。
还有8分钟，怎么还是有人在写代码，他们好强
sk说他J估分到了200+，那有2=了吧
我今年能有7钩吗
难度好像有点像S2024，那年的7钩好像是225吧，哦对洛谷的7钩分数更高了，吓人。
可是我好菜。
rp++，期中也是rp++
在这里坐了四个小时，好像一场梦，梦醒之后又要面对whk了
好累。
还有5分钟，结束吧，
一切都会越来越好的。
*/
