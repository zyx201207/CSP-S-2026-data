#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <unordered_map>
#include <vector>

#define PB_DS 0
#if PB_DS
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#endif

namespace MyFILE {
const std::string FILE_NAME = "crystal";
const std::string TEST_CASE = "4";

#define FILE_IO 1
#define LOCAL_TEST 0
#define ONLINE_TEST 1
}  // namespace MyFILE

using int64 = long long;
using namespace MyFILE;

bool MEMORY_START;

void MAIN() {
    int64 n, m;
    std::cin >> n >> m;
    std::vector<int64> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    std::sort(a.begin() + 1, a.end());
    std::vector<int64> sum(n + 1);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
    }

    int ans = 0;
    for (int r = 2, l = 1; r <= n; r++) {  // 假设全都补成a[r],二分找最远的边界l
        while (l < r && (r - l + 1) * a[r] - (sum[r] - sum[l - 1]) > m) {
            l++;
        }
        ans = std::max(ans, r - l + 1);
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

    MAIN();

    std::cerr << "> TIME: " << std::fixed << std::setprecision(6) << (clock() - TIME_START) / CLOCKS_PER_SEC * 1000.0 << "ms\n";

    return 0;
}