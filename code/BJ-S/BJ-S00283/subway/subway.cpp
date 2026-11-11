#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
#define int long long
int n, m, d, q;

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' or ch > '9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' and ch <= '9') { x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar(); }
    return x * f;
}
inline void write(int x) {
    char stk[20]; short top = 0;
    if (x < 0) putchar('-'), x = -x;
    do { stk[++top] = x % 10 + '0'; x /= 10; } while (x);
    while (top) putchar(stk[top--]);
}

const int maxn = 505;
const int maxm = 5e5 + 10;
int w[maxm];
int k[maxn];

struct node {
    int v, t;
};
vector <int> tr[maxm];
vector <node> g[maxn];
vector <node> gr[maxm];

int dis[maxn][maxn];
int __t[maxn][maxn];

void init() {
    for (int i = 1; i <= n; i++) {
        for (auto [_a, _t] : g[i]) {
            for (int v : tr[_a]) {
                for (auto _ : g[v]) {
                    if (_.v == _a) {
                        gr[i].push_back({v, _t + _.t});
                    }
                }
            }
        }
    }
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= n; i++) {
        for (auto [_a, _t] : gr[i]) {
            dis[i][_a] = min(dis[i][_a], _t);
        }
        dis[i][i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (dis[j][i] + dis[i][k] < dis[j][k]) {
                    dis[j][k] = dis[j][i] + dis[i][k];
                }
            }
        }
    }
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
*/
int calc(int x, int y) {
    int ans = 0x3f3f3f3f;
    for (int t1 : tr[x]) {
        for (int t2 : tr[y]) {

            ans = min(ans, dis[t1][t2] + __t[t1][x] + __t[t2][y]);
        }
    }
    return ans;
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int _ = read();
    n = read(); m = read(); d = read(); q = read();
    for (int i = 1; i <= m; i++) w[i] = read();
    for (int i = 1, a, _t; i <= n; i++) {
        k[i] = read();
        for (int j = 1; j <= k[i]; j++) {
            a = read(); _t = read();
            g[i].push_back({a, _t});
            tr[a].push_back(i);
            __t[i][a] = _t;
        }
    }
    init();
    for (int i = 1; i <= q; i++) {
        int x = read(), y = read();
        write(w[x] + w[y] + calc(x, y));
        putchar('\n');
    }

    return 0;
}
