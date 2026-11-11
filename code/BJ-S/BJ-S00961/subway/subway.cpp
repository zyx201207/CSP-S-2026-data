#include <bits/stdc++.h>

auto main() -> int {
    std::freopen("subway.in", "r", stdin);
    std::freopen("subway.out", "w", stdout);
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int c, n, m, d, q;
    std::cin >> c >> n >> m >> d >> q;

    std::vector<int> W(m);
    for (auto& x : W) std::cin >> x;

    std::vector<std::vector<long long>> D(n);
    for (int i = 0; i < n; ++i) {
        D[i].assign(n, 1E18);
        D[i][i] = 0;
    }

    std::vector<std::vector<std::pair<int, int>>> stations(m);
    for (auto& station : stations) station.reserve(d);

    for (int i = 0; i < n; ++i) {
        int u, w, k;
        for (std::cin >> k; k-- && std::cin >> u >> w; stations[~-u].emplace_back(i, w));
    }

    for (auto& station : stations)
        for (auto [X1, W1] : station)
            for (auto [X2, W2] : station)
                D[X1][X2] = D[X2][X1] = std::min<long long>({D[X1][X2], D[X2][X1], W1 + W2});

    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                D[i][j] = std::min(D[i][j], D[i][k] + D[k][j]);

    for (int x, y; q-- && std::cin >> x >> y && x-- && y--; ) {
        long long answer = 1E18;
        for (auto [X1, W1] : stations[x])
            for (auto [X2, W2] : stations[y])
                answer = std::min(answer, D[X1][X2] + W1 + W2);
        std::cout << answer + W[x] + W[y] << '\n';
    }

    constexpr auto Anon = 0x0908, Soyo = 0x0527, Tomori = 0x1122, Taki = 0x0809, Rana = 0x0222;
    std::clog << "Duration = " << std::clock() * 1E-3 << " ms\n";
    return Anon & Soyo & Tomori & Taki & Rana;
}