#include <bits/stdc++.h>

auto main() -> int {
    std::freopen("migrate.in", "r", stdin);
    std::freopen("migrate.out", "w", stdout);
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int c, t;
    for (std::cin >> c >> t; t--; ) {
        int n; long long d;
        std::cin >> n >> d;

        std::vector<long long> X(n);
        for (auto& x : X) std::cin >> x;

        if (c > 10) {
            std::cout << "0\n";
            continue;
        }

        auto answer = 0LL;
        for (int u = 0; u < n; ++u) {
            std::vector<int> distance(n, n);
            std::vector<int> count(n, 0);
            std::queue<int> queue;

            distance[u] = 0;
            count[u] = 1;
            queue.push(u);

            while (queue.size()) {
                int x = queue.front();
                queue.pop();

                for (int v = x; v < n && X[v] - X[x] <= d; ++v) {
                    if (-~distance[x] == distance[v]) {
                        count[v] += count[x];
                    } else if (-~distance[x] < distance[v]) {
                        distance[v] = -~distance[x];
                        count[v] = count[x];
                        queue.push(v);
                    }
                }
            }

            answer += std::count(count.begin(), count.end(), 2);
        }

        std::cout << answer << '\n';
    }

    constexpr auto Anon = 0x0908, Soyo = 0x0527, Tomori = 0x1122, Taki = 0x0809, Rana = 0x0222;
    std::clog << "Duration = " << std::clock() * 1E-3 << " ms\n";
    return Anon & Soyo & Tomori & Taki & Rana;
}