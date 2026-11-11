#include <bits/stdc++.h>

#define FI
#define FO

int main() {
#define int long long
    constexpr int inf = 0x3f3f3f3f3f3f3f3f;
#ifdef FI
    std::ifstream fin("and.in");
#else
#define fin std::cin
#endif
#ifdef FO
    std::ofstream fout("and.out");
#else
#define fout std::cout
#endif
    int n, m;
    fin >> n >> m;
    std::vector<int> a(n + 1);
    std::vector<int> cnt(31);
    for (int i = 1; i <= n; ++i) {
        fin >> a.at(i);
        for (int j = 30; j >= 0; --j) {
            if (a.at(i) & (1 << j)) {
                ++cnt.at(j);
            }
        }
    }
    int pos = 0;
    int ans = 0;
    auto b = a;
    while (pos != -1) {
        pos = -1;
        for (int i = 30; i >= 0; --i) {
            if (cnt.at(i) >= m) {
                pos = i;
                break;
            }
        }
        if (pos == -1) {
            break;
        }
        ans += (1 << pos);
        cnt.resize(0);
        cnt.resize(31);
        int S = (1 << pos) - 1;
        for (int i = 1; i <= n; ++i) {
            if ((a.at(i) & (1 << pos)) == 0) {
                a.at(i) = 0;
            }
            a.at(i) &= S;
            for (int j = 30; j >= 0; --j) {
                if (a.at(i) & (1 << j)) {
                    ++cnt.at(j);
                }
            }
        }
    }
    fout << ans << "\n";
    return 0;
}
