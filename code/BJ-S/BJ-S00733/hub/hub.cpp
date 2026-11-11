#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 100;

int n, k;
bool e[N + 5][N + 5];
int d[N + 5][N + 5];
int a[N + 5], lg[100005];
bool vis[N + 5];

int ppcnt(int x) {
    int res = 0;
    while (x) {
        res++;
        x -= x & -x;
    }
    return res;
}

void dfs(int x, int fr, int ds) {
    vis[x] = true;
    d[fr][x] = ds;
    for (int i = 1; i <= n; i++) {
        if (!e[x][i] || vis[i]) continue;
        dfs(i, fr, ds + 1);
    }
    return;
}
int work() {
    scanf("%d%d", &n, &k);
    memset(e, 0, sizeof e);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        e[u][v] = e[v][u] = true;
    }
    memset(d, 0x3f, sizeof d);
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof vis);
        dfs(i, i, 0);
    }
    int ans = 0x3f3f3f3f;
    for (int i = 1; i < (1 << n); i++) {
        if (ppcnt(i) != k) continue;
        int t = i, cr = 0;
        while (t) {
            a[++cr] = lg[t & -t] + 1;
            t -= (t & -t);
        }
        int cnt = 0;
        for (int j = 1; j <= k; j++) {
            for (int l = j + 1; l <= k; l++) {
                if (e[a[j]][a[l]]) cnt++;
            }
        }
        //printf("working on hubs[]: ");
        //for (int j = 1; j <= k; j++) {
        //    printf("%d, ", a[j]);
        //}
        //printf("\n");
        if (cnt < k - 2) continue;
        int now = 0;
        for (int j = 1; j <= n; j++) {
            int minn = 0x3f3f3f3f;
            for (int l = 1; l <= k; l++) {
                minn = min(minn, d[j][a[l]]);
            }
            now = max(now, minn);
        }
        ans = min(ans, now);
        //printf("ans=%d\n", now);
    }
    printf("%d\n", ans);
    return 0;
}

int main() {
    //if (false) {
        freopen("hub.in", "r", stdin);
        freopen("hub.out", "w", stdout);
    //}
    int c, t;
    scanf("%d%d", &c, &t);
    for (int i = 2; i <= 100000; i++) {
        lg[i] = lg[i - 1] + (i == (i & -i));
    }
    while (t--) {
        work();
    }
    return 0;
}
