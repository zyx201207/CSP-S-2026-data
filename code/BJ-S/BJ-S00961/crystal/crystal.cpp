#include <bits/stdc++.h>

auto main() -> int {
    std::freopen("crystal.in", "r", stdin);
    std::freopen("crystal.out", "w", stdout);
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n; long long m;
    std::cin >> n >> m;

    std::vector<long long> A(n);
    for (auto& x : A) std::cin >> x;
    std::sort(A.begin(), A.end());

    std::vector<long long> S(n);
    std::partial_sum(A.begin(), A.end(), S.data());

    int answer = 1;
    for (int i = 0; i < n; ++i) {
        int l = 0, r = i;
        while (r - l > 1) {
            int o = (l + r) / 2;
            (((o ? S[~-o] : 0) - S[~-i] + (i - o) * A[i] <= m) ? r : l) = o;
        }
        answer = std::max(answer, i - l);
    }
    std::cout << answer << '\n';

    constexpr auto Anon = 0x0908, Soyo = 0x0527, Tomori = 0x1122, Taki = 0x0809, Rana = 0x0222;
    std::clog << "Duration = " << std::clock() * 1E-3 << " ms\n";
    return Anon & Soyo & Tomori & Taki & Rana;
}