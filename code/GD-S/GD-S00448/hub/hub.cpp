#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <array>

namespace {
    typedef long long lnt;

    const int inf = 0x3f3f3f3f;

    const int max_n = 1000, max_k = 1000;
    

} // 已红温

std::vector<int> G[max_n];

int n, k, sums[max_n], sumd[max_n], ans;
int sttp[max_n * 2], _tsiz[max_n][max_k]; // 取前 k 大子树 siz

// int merge(int *a, int sza, int *b, int szb) { // b -> a 这个以后
//     std::merge(a, a + sza, b, b + szb, sttp, [](int a, int b) -> bool {
//         return a > b;
//     });
//     int sz = std::min(k, sza + szb);
//     std::copy(sttp, sttp + sz, a);
//     return sz;
// } 

int dp[max_n][max_k]; // 

void _dfs(int u, int fa) {
    siz[u] = 1;
    for (const int to : G[u]) {
        if (to == fa) continue;
        _dfs(to, u)
        siz[u] += siz[to], sums[u] += sums[to];
    }    
    sums[u] += siz[u];
}

// int tpg[max_n], tpged; 

void dfs_get(int u, int fa, int tp*, int &cnt) { // 制取 k 大子树
    tp[++cnt] = siz[u];    
    for (const int to : G[u]) {
        if (to == fa) continue;
        dfs_get(to, u, tp, cnt);
    }      
}

void get(int u, int fa, int tp*, int &cnt) { // 制取 k 大子树
    cnt = 0, dfs_get(u, fa, tp, cnt);
    cnt = std::min(k, siz[u]);
    std::nth_element(tp, tp + cnt, tp + siz[u], [](int a, int b) -> bool {
        return a > b;
    });
}

int tpn[max_n], cntn;
int tpf[max_n], cntf, nowf;

void dfs(int u, int fa, int dep, int nsum) {
    int all = 0;
    for (const int to : G[u]) {
        if (to == fa) continue;
        all += sums[to];
    }
    for (const int to : G[u]) {
        if (to == fa) continue;
        sumd[dep] = all - sums[to];
        int nxsum = nsum;
        if (dep % 2 == 0) {
            
        }
        dfs(to, u, dep + 1, nxsum); 
    }

    get(u, fa, tpn, cntn);

    for (int i = 1; i <= cntn; ++i) { 
        tpn[i] += tpn[i - 1];
    }

    int _sum = 0;
    for (int i = 0; i <= cntn; ++i) { // 
        int e = k - i; if (e > cntf) break;
        _sum = std::max(_sum, tpn[i] + tpf[e]);
    }

    int res = sums[nowf] + sums[u] - _sum;
    
    int h = dep / 2;

    res += 

}

struct edge { int x, y; } es[max_n];

void solve() {
    std::cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        int x, y; std::cin >> x >> y;
        G[x].push_back(y), G[y].push_back(x);
        es[i] = {x, y};
    }

    int ansf = inf;
    for (int i = 1; i < n; ++i) {
        int x = es[i].x, y = es[i].y;
        std::memset(siz, 0, sizeof(siz));
        std::memset(sums, 0, sizeof(sums));
        std::memset(sumd, 0, sizeof(sumsd));
        ans = 0;
        _dfs(x, y, 1);
        _dfs(y, x, 1);
        get(y, x, tpf, cntf);
        nowf = y;
        for (int i = 1; i <= cntf; ++i) { 
            tpf[i] += tpf[i - 1];
        }

        dfs(x, y, 1);
        ansf = std::min(ans, ansf);
    }
    std::printf("%d\n", ansf);
}

int main() {
    std::freopen("hub.in", "r", stdin);
    std::freopen("hub.out", "w", stdout);

    std::cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1, c; std::cin >> c >> T;
    for (int i = 0; i < T; ++i) {
        solve();
    }

    return 0;
}
