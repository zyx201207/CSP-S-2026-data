#include <algorithm>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <utility>
#include <vector>

#define PB_DS 0
#if PB_DS
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#endif

namespace MyFILE {
const std::string FILE_NAME = "migrate";
const std::string TEST_CASE = "3";

#define FILE_IO 1
#define LOCAL_TEST 0
#define ONLINE_TEST 1
}  // namespace MyFILE

using int64 = long long;
using namespace MyFILE;
typedef std::pair<int, int> PII;

const int INF = 1e9;

bool MEMORY_START;

void MAIN() {
    int n;
    int64 d;
    std::cin >> n >> d;
    std::vector<int64> x(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> x[i];
    }

    std::vector<std::vector<int>> graph(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int64 tmp = x[j] - x[i];
            if (tmp <= d) {
                graph[i].push_back(j);
            }
        }
    }

    int64 ans = 0;
    auto BFS = [&](int start) -> void {
        std::queue<int> q;
        std::vector<int> dis(n + 1, INF);
        std::vector<int> cnt(n + 1, 0);

        q.push(start);
        dis[start] = 0;
        cnt[start] = 1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto& v : graph[u]) {
                if (dis[v] > dis[u] + 1) {
                    dis[v] = dis[u] + 1;
                    cnt[v] = cnt[u];
                    q.push(v);
                } else if (dis[v] == dis[u] + 1) {
                    cnt[v]++;
                }
            }
        }

        for (int i = start + 1; i <= n; i++) {
            if (cnt[i] == 2) {
                ans++;
            }
        }
    };

    for (int i = 1; i <= n; i++) {
        BFS(i);
    }
    std::cout << ans << "\n";
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

    int c, T;
    std::cin >> c >> T;
    while (T--) {
        MAIN();
    }

    std::cerr << "> TIME: " << std::fixed << std::setprecision(6) << (clock() - TIME_START) / CLOCKS_PER_SEC * 1000.0 << "ms\n";

    return 0;
}