#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define mkp make_pair
const int N = 505, M = 5e5 + 5;
const LL INF = 1e18;
int n, m, d, q;
inline void read(int& x) {
    x = 0;char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
}
int w[M];
vector<pii>vec[M];
LL dis[N][N];
inline void chmn(LL& x, LL y) { x = x > y ? y : x; }
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    // clock_t start = clock();
    int testcase;read(testcase), read(n), read(m), read(d), read(q);
    for (int i = 1;i <= m;++i) read(w[i]);
    for (int i = 1;i <= n;++i) {
        int k;read(k);
        for (int j = 1;j <= k;++j) {
            int a, t;read(a), read(t);
            vec[a].push_back(mkp(i, t));
        }
    }
    for (int i = 1;i <= n;++i)
        for (int j = 1;j <= n;++j) dis[i][j] = INF;
    for (int i = 1;i <= n;++i) dis[i][i] = 0;
    for (int i = 1;i <= m;++i) {
        const int siz = vec[i].size();
        for (int j = 0;j < siz;++j)
            for (int k = j + 1;k < siz;++k) {
                const int val = vec[i][j].second + vec[i][k].second, u = vec[i][j].first, v = vec[i][k].first;
                chmn(dis[u][v], val), chmn(dis[v][u], val);
            }
    }
    for (int k = 1;k <= n;++k)
        for (int u = 1;u <= n;++u)
            for (int v = 1;v <= n;++v) chmn(dis[u][v], dis[u][k] + dis[k][v]);
    while (q--) {
        int x, y;read(x), read(y);
        LL ans = INF;
        for (pii st : vec[x])
            for (pii ed : vec[y]) chmn(ans, dis[st.first][ed.first] + st.second + ed.second);
        printf("%lld\n", ans + w[x] + w[y]);
    }
    // fprintf(stderr, "%dms\n", int(double(clock() - start) / CLOCKS_PER_SEC * 1000));
    return 0;
}