#include <bits/stdc++.h>

#define FI
#define FO

int main() {
#define int long long
    constexpr int inf = 0x3f3f3f3f3f3f3f3f;
#ifdef FI
    std::ifstream fin("card.in");
#else
#define fin std::cin
#endif
#ifdef FO
    std::ofstream fout("card.out");
#else
#define fout std::cout
#endif
    int n, m;
    fin >> n >> m;
    std::vector<int> a(n + 1);
    bool flag = true;
    int flag2 = 0;
    for (int i = 1; i <= n; ++i) {
        fin >> a.at(i);
        if (a.at(i) < a.at(i - 1)) {
            flag = false;
        }
        if (a.at(i) != a.at(i - 1)) {
            ++flag2;
        }
    }
    if (n <= 5000) {
        auto game = [&](int i) {
            std::vector<int> res;
            std::vector<int> cnt(m + 1);
            for (int j = i; j <= n; ++j) {
                if (cnt.at(a.at(j)) > 0) {
                    while (res.back() != a.at(j)) {
                        --cnt.at(res.back());
                        res.pop_back();
                    }
                } else {
                    res.push_back(a.at(j));
                    ++cnt.at(a.at(j));
                }
            }
            return res;
        };
        std::vector<int> ans(m + 1);
        for (int i = 1; i <= n; ++i) {
            auto tmp = game(i);
            for (auto &&item: tmp) {
                ++ans.at(item);
            }
        }
        for (int i = 1; i <= m; ++i) {
            fout << ans.at(i) << " ";
        }
        fout << "\n";
        return 0;
    }
    if (flag) {
        std::vector<int> ans(m + 1);
        for (int i = 1; i <= n; ++i) {
            ans.at(a.at(i)) = i;
        }
        for (int i = 1; i <= m; ++i) {
            fout << ans.at(i) << " ";
        }
        fout << "\n";
        return 0;
    }
    if (m == 2) {
        std::array<int, 3> ans{0, 0, 0};
        for (int i = n; i >= 1; --i) {
            if (a.at(i) == a.at(n)) {
                ++ans.at(a.at(i));
            } else {
                ++ans.at(1);
                ++ans.at(2);
            }
        }
        fout << ans.at(1) << " " << ans.at(2) << "\n";
        return 0;
    }
    //std::cout << 114514 << "\n";
    auto game = [&m](std::vector<int> &a, int n) {
        std::vector<int> res;
        std::vector<int> cnt(m + 1);
        for (int j = n; j >= 1; --j) {
            if (cnt.at(a.at(j)) > 0) {
                while (res.back() != a.at(j)) {
                    --cnt.at(res.back());
                    res.pop_back();
                }
            } else {
                res.push_back(a.at(j));
                ++cnt.at(a.at(j));
            }
        }
        return res;
    };
    std::vector<int> b(n + 1);
    std::vector<int> ans(m + 1);
    int now = 0;
    int lst = a.at(n);
    int tail = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (a.at(i) == a.at(i + 1)) {
            ++now;
            continue;
        }
        b.at(++tail) = lst;
        lst = a.at(i);
        auto tmp = game(b, tail);
        for (auto &&item: tmp) {
            ans.at(item) += now + 1;
        }
        now = 0;
    }
    for (int i = 1; i <= m; ++i) {
        fout << ans.at(i) << " ";
    }
    fout << "\n";
    return 0;
}
