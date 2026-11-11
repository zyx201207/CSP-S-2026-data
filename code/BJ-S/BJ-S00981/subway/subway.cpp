#include <bits/stdc++.h>
using namespace std;

const int N = 505;
const int M = 5e5 + 5;
const long long INF = 0x3f3f3f3f3f3f3f3f;

struct edge {
    int nxt, v;
    long long t;
} e[M];

int c, n, m, d, Q, z, w[M], head[M];
long long dis[N][N], ans;

void add(int u, int v, int t){
    e[++z] = {head[u], v, t};
    head[u] = z;
    return ;
}

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &Q);
    for (int i = 1; i <= m; i++)
        scanf("%d", &w[i]);
    for (int i = 1; i <= n; i++){
        int len; scanf("%d", &len);
        for (int j = 1; j <= len; j++){
            int u, t; scanf("%d%d", &u, &t);
            add(u, i, t);
        }
    }
    memset(dis, 0x3f, sizeof dis);
    for (int i = 1; i <= n; i++)
        dis[i][i] = 0;
    for (int i = 1; i <= m; i++){
        for (int j = head[i]; j; j = e[j].nxt){
            for (int k = e[j].nxt; k; k = e[k].nxt){
                dis[e[j].v][e[k].v] = min(dis[e[j].v][e[k].v], e[j].t + e[k].t);
                dis[e[k].v][e[j].v] = min(dis[e[k].v][e[j].v], e[k].t + e[j].t);
            }
        }
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    while (Q--){
        int x, y; scanf("%d%d", &x, &y); ans = INF;
        for (int i = head[x]; i; i = e[i].nxt)
            for (int j = head[y]; j; j = e[j].nxt)
                ans = min(ans, e[i].t + e[j].t + dis[e[i].v][e[j].v]);
        ans += w[x] + w[y];
        printf("%lld\n", ans);
    }
    return 0;
}