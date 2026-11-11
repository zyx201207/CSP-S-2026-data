#include <algorithm>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

#define PB_DS 1
#if PB_DS
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#endif

namespace MyFILE {
const std::string FILE_NAME = "subway";
const std::string TEST_CASE = "6";

#define FILE_IO 1
#define LOCAL_TEST 0
#define ONLINE_TEST 1
}  // namespace MyFILE

using int64 = long long;
using namespace MyFILE;
typedef std::pair<int64, int> PII;
typedef __gnu_pbds::gp_hash_table<int64, int64> gp_hash;

const int64 INF = 1e18;

bool MEMORY_START;

struct Subway {
    int to, t;
};

void MAIN() {
    int c, n, m, d, q;
    std::cin >> c >> n >> m >> d >> q;
    std::vector<int64> w(m + 1);
    for (int i = 1; i <= m; i++) {
        std::cin >> w[i];
    }

    std::vector<std::vector<Subway>> a(n + 1);  // a[i][j] 表示i号点第j个链接情况,to为链接点的编号,t为花费
    std::vector<std::vector<std::pair<int, int64>>> to(m + 1);
    std::vector<std::vector<std::pair<int, int64>>> graph(n + m + 1);
    for (int i = 1; i <= n; i++) {
        int k;
        std::cin >> k;
        a[i].resize(k);
        for (int j = 0; j < k; j++) {
            std::cin >> a[i][j].to >> a[i][j].t;
            to[a[i][j].to].push_back({i, a[i][j].t});
            graph[n + a[i][j].to].push_back({i, a[i][j].t});
            graph[i].push_back({n + a[i][j].to, a[i][j].t});
        }
    }

    auto Hash = [&](int u, int v) -> int64 { return 1LL * (u - 1) * m + 1LL * v; };

    gp_hash F;  // F[(u,v)]=dis

    auto BFS = [&](int st) -> void {
        std::queue<int> q;
        std::vector<int64> dis(n + m + 1, INF);
        std::vector<bool> vis(n + m + 1);

        q.push(st);
        dis[st] = 0;
        vis[st] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (vis[u]) {
                vis[u] = false;
            }

            for (auto& nxt : graph[u]) {
                int v = nxt.first;
                int64 w = nxt.second;
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    if (!vis[v]) {
                        q.push(v);
                        vis[v] = true;
                    }
                }
            }
        }

        for (int i = 1; i <= m; i++) {
            // std::cerr << "Dis: " << st << " to " << i << " : " << dis[n + i] << "\n";
            F[Hash(st, n + i)] = dis[n + i];
        }
    };

    for (int i = 1; i <= n; i++) {
        BFS(i);
    }

    while (q--) {
        int x, y;
        std::cin >> x >> y;
        int64 ans = w[x] + w[y];

        int64 add = INF;
        for (std::size_t i = 0; i < to[x].size(); i++) {
            int64 pos = Hash(to[x][i].first, n + y);
            add = std::min(add, F[pos] + to[x][i].second);
            // std::cerr << "Station: " << x << " Line: " << to[x][i].first << " Cost: " << F[pos] + to[x][i].second << "\n";
        }
        for (std::size_t i = 0; i < to[y].size(); i++) {
            int64 pos = Hash(to[y][i].first, n + x);
            add = std::min(add, F[pos] + to[y][i].second);
        }

        std::cout << ans + add << "\n";
    }
}

bool MEMORY_END;

int main() {
#if FILE_IO
#if LOCAL_TEST
    if (freopen(("test/" + FILE_NAME + TEST_CASE + ".in").c_str(), "r", stdin) == nullptr) {
        std::cerr << "ERROR: Can not open the file!\n";
        exit(1);
    }
    if (freopen(("out/" + FILE_NAME + TEST_CASE + ".out").c_str(), "w", stdout) == nullptr) {
        std::cerr << "ERROR: Can not write the file!\n";
        exit(1);
    }
#endif

#if ONLINE_TEST
    freopen((FILE_NAME + ".in").c_str(), "r", stdin);
    freopen((FILE_NAME + ".out").c_str(), "w", stdout);
#endif
#endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cerr << "> MEMORY: " << std::fixed << std::setprecision(6) << (&MEMORY_END - &MEMORY_START) / 1024.0 / 1024.0 << "MB\n";
    double TIME_START = clock();

    MAIN();

    std::cerr << "> TIME: " << std::fixed << std::setprecision(6) << (clock() - TIME_START) / CLOCKS_PER_SEC * 1000.0 << "ms\n";

    return 0;
}