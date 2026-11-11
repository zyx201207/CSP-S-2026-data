#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int N = 500, M = 500000, D = 20;
const long long INF = 0x3f3f3f3f3f3f3f3f;

int n, m, d, cc, glob;
long long w[M + 5];
int cn[N + 5];
long long a[N + 5][M + 5];
int lns[M + 5][D + 5], lnsc[M + 5];
long long e[N + 5][N + 5], e2[N + 5][N + 5];

long long fr() {
    long long x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while ('0' <= c && c <= '9') {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return x * f;
}

void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (e[i][j] == INF || e[i][k] == INF || e[k][j] == INF) continue;
                e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
            }
        }
    }
    return;
}
struct tat {
    int id;
    int l;
};
bool vis[N + 5];
queue <tat> Q;
void bfs(int st) {
    Q.push({st, 0});
    memset(vis, false, sizeof vis);
    while (!Q.empty()) {
        tat p = Q.front();
        Q.pop();
        if (vis[p.id]) continue;
        e2[st][p.id] = p.l;
        vis[p.id] = true;
        for (int i = 1; i <= n; i++) {
            if (e[p.id][i] == INF) continue;
            Q.push({i, p.l + glob});
        }
    }
    return;
}
void bfswork() {
    for (int i = 1; i <= n; i++) bfs(i);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            e[i][j] = e2[i][j];
        }
    }
}

int main() {
    //if (false) {
        freopen("subway.in", "r", stdin);
        freopen("subway.out", "w", stdout);
    //}
    cc = fr();
    n = fr();
    m = fr();
    d = fr();
    int q = fr();
    memset(a, 0x3f, sizeof a);
    memset(e, 0x3f, sizeof e);
    for (int i = 1; i <= n; i++) e[i][i] = 0;
    for (int i = 1; i <= m; i++) w[i] = fr();
    for (int i = 1; i <= n; i++) {
        cn[i] = fr();
        for (int j = 1; j <= cn[i]; j++) {
            int x = fr();
            a[i][x] = fr();
            glob = a[i][x];
            lns[x][++lnsc[x]] = i;
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= lnsc[i]; j++) {
            for (int k = j + 1; k <= lnsc[i]; k++) {
                //printf("update station %d --> %d, len=%lld\n", lns[i][j], lns[i][k], a[lns[i][k]][i] + a[lns[i][j]][i]);
                e[lns[i][j]][lns[i][k]] = min(e[lns[i][j]][lns[i][k]], a[lns[i][k]][i] + a[lns[i][j]][i]);
                e[lns[i][k]][lns[i][j]] = e[lns[i][j]][lns[i][k]];
            }
        }
    }
    if (cc >= 12 && cc <= 19) bfswork();
    else floyd();
    while (q--) {
        int u, v;
        u = fr();
        v = fr();
        long long minn = INF;
        for (int i = 1; i <= lnsc[u]; i++) {
            for (int j = 1; j <= lnsc[v]; j++) {
                //printf("try station %d --> %d, e=%lld\n", lns[u][i], lns[v][j], e[lns[u][i]][lns[v][j]]);
                minn = min(minn, e[lns[u][i]][lns[v][j]] + a[lns[u][i]][u] + a[lns[v][j]][v]);
            }
        }
        long long ans = minn + w[u] + w[v];
        printf("%lld\n", ans);
    }
    /*for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            printf("from %d to %d len=%lld\n", i, j, e[i][j]);
        }
    }*/
    return 0;
}
