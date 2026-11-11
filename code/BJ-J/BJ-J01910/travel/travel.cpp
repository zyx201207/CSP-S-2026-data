#include <bits/stdc++.h>

#define FI
#define FO

int main() {
#define int long long
    constexpr int inf = 0x3f3f3f3f3f3f3f3f;
#ifdef FI
    std::ifstream fin("travel.in");
#else
#define fin std::cin
#endif
#ifdef FO
    std::ofstream fout("travel.out");
#else
#define fout std::cout
#endif
    std::string a, b, c, d;
    fin >> a >> b >> c >> d;
    if (a == c) {
        fout << 1;
    } else {
        fout << "0000\n";
        return 0;
    }
    if (b.at(0) == d.at(0) && b.at(1) == d.at(1)) {
        fout << 1;
    } else {
        fout << "000\n";
        return 0;
    }
    auto left = [](char ch) {
        return ch == 'A' || ch == 'B' || ch == 'C';
    };
    if (left(b.at(2)) ^ left(d.at(2))) {
        fout << "00\n";
        return 0;
    }
    fout << 1;
    if (!left(b.at(2)) && !left(d.at(2))) {
        fout << 1;
    } else if (std::abs(b.at(2) - d.at(2)) == 1) {
        fout << 1;
    } else {
        fout << 0;
    }
    fout << "\n";
    return 0;
}
