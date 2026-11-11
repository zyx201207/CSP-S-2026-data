#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5, M = 503;
int c, n, m, d, q, x, y, k;
int w[N], a, t[M][N], ans = 2e9;
void dfs(int s, int dis, int che) {
    if(s == y) {
        ans = min(ans, dis + t[che][y] + w[y]);
        return;
    }
    for(int i = 1; i <= n; i++) if(t[i][x]) dfs(x + 1, dis + t[che][x] + t[i][x], i);
    dfs(x + 1, dis, che);
}
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
    for(int i = 1; i <= m; i++) scanf("%d", &w[i]);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &k);
        for(int j = 1; j <= k; j++) {
            scanf("%d", &a);
            scanf("%d", &t[i][a]);
        }
    }
    while(q--) {
        scanf("%d %d", &x, &y);
        for(int i = 1; i <= n; i++) if(t[i][x]) dfs(x, t[i][x] + w[x], i);
    }
    return 0;
}
