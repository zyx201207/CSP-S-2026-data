#include <bits/stdc++.h>

auto main() -> int {
    std::freopen("hub.in", "r", stdin);
    std::freopen("hub.out", "w", stdout);
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int c, t;
    for (std::cin >> c >> t; t--; ) {
        int n, k;
        std::cin >> n >> k;

        std::vector<std::basic_string<int>> tree(n);
        for (int i = n, u, v; --i && std::cin >> u >> v && u-- && v--; ) {
            tree[u] += v;
            tree[v] += u;
        }

        int answer = n;
        for (int choice = 0; choice < 1 << n; ++choice) {
            if (__builtin_popcount(choice) == k) {
                std::vector<int> color(n);
                int colorcnt = 0;

                for (int i = 0; i < n; ++i) {
                    if ((choice >> i & 1) && color[i] == 0 && ++colorcnt) {
                        std::queue<int> queue;
                        queue.push(i);

                        while (queue.size()) {
                            int u = queue.front();
                            queue.pop();

                            color[u] = colorcnt;
                            for (int v : tree[u])
                                if ((choice >> v & 1) && color[v] == 0)
                                    queue.push(v);
                        }
                    }
                }

                if (colorcnt <= 2) {
                    int diameter = 0;
                    for (int i = 0; i < n; ++i) {
                        int dismin = n;
                        std::vector<int> distance(n, n);
                        std::queue<int> queue;

                        distance[i] = 0;
                        queue.push(i);

                        while (queue.size()) {
                            int u = queue.front();
                            queue.pop();

                            if (choice >> u & 1) dismin = std::min(dismin, distance[u]);
                            for (int v : tree[u])
                                if (distance[v] == n && (distance[v] = -~distance[u]))
                                    queue.push(v);
                        }

                        diameter = std::max(diameter, dismin);
                    }

                    answer = std::min(answer, diameter);
                }
            }
        }

        std::cout << answer << '\n';
    }

    constexpr auto Anon = 0x0908, Soyo = 0x0527, Tomori = 0x1122, Taki = 0x0809, Rana = 0x0222;
    std::clog << "Duration = " << std::clock() * 1E-3 << " ms\n";
    return Anon & Soyo & Tomori & Taki & Rana;
}