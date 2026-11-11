#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int NR = 1e6 + 5;

int n, k, ans = 0x3f3f3f3f;
vector<int> mp[NR];
bool vis[15], vis2[15];
int dis[15][15];

void dfs(int u, int fa) {
    vis2[u] = true;
    for (int v : mp[u]) {
        if (v == fa || !vis[v]) continue;
        dfs(v, u);
    }
}

void calc() {
    memset(vis2, 0, sizeof(vis2));

    int cnt_b = 0;
    for (int i = 1; i <= n; i++) {
        // if (vis[2] && vis[7] && vis[9])
        //     printf("279: %d", cnt_b);
        if (vis[i] && !vis2[i]) {
            cnt_b++;
            if (cnt_b > 2) return;
            dfs(i, i);
        }
    }

    //printf("YES %d\n", n);

    int tmp, tmp2 = 0;
    for (int i = 1; i <= n; i++) {
        tmp = 0x3f3f3f3f;
        for (int j = 1; j <= n; j++) {
            if (!vis[j]) continue;
            tmp = min(tmp, dis[i][j]);
        }
        if (tmp != 0x3f3f3f3f) tmp2 = max(tmp2, tmp);
    }
    ans = min(ans, tmp2);
}

void dfs_m(int x, int cho) {
    if (cho == k) {
        calc();
        return;
    }

    if (x > n || cho > k) return;

    dfs_m(x + 1, cho);
    vis[x] = true;
    dfs_m(x + 1, cho + 1);
    vis[x] = false;
}

void dfs_d(int st, int u, int fa, int d) {
    dis[st][u] = d;

    for (int v : mp[u]) {
        if (v == fa) continue;
        dfs_d(st, v, u, d + 1);
    }
}

void solve() {
    int u, v;

    cin >> n >> k;
    //printf("%d %d\n", n, k);

    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        mp[u].emplace_back(v);
        mp[v].emplace_back(u);
    }

    for (int i = 1; i <= n; i++)
        dfs_d(i, i, 0, 0);

    dfs_m(1, 0);
    printf("%d\n", ans);

    ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++)
        mp[i].clear();
    memset(dis, 0, sizeof(dis));
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c, t;

    cin >> c >> t;
    while (t--) {
        if (c <= 3)
            solve();
    }
    return 0;
}