#include <bits/stdc++.h>

#define FI
#define FO

int main() {
#define int long long
    constexpr int inf = 0x3f3f3f3f3f3f3f3f;
#ifdef FI
    std::ifstream fin("string.in");
#else
#define fin std::cin
#endif
#ifdef FO
    std::ofstream fout("string.out");
#else
#define fout std::cout
#endif
    int n;
    fin >> n;
    int L = 0;
    std::vector<int> a(n + 1);
    std::vector<char> c(n + 1);
    for (int i = 1; i <= n; ++i) {
        fin >> a.at(i) >> c.at(i);
        L += a.at(i);
    }
    int left = 1, right = n;
    int ans = 0;
    int lst1 = 0, lst2 = 0;
    int sum = 0;
    //std::cout << "\n";
    while (left < right) {
        int ll = a.at(left) - lst1;
        int rr = a.at(right) - lst2;
        //std::cout << ll << " " << c.at(left) << "\n";
        //std::cout << rr << " " << c.at(right) << "\n\n";
        if (ll == rr) {
            ans += (c.at(left) != c.at(right)) * ll;
            lst1 = lst2 = 0;
            ++left;
            --right;
            continue;
        }
        if (ll < rr) {
            lst1 = 0;
            lst2 += ll;
            ans += (c.at(left) != c.at(right)) * ll;
            ++left;
            continue;
        }
        lst1 += rr;
        lst2 = 0;
        ans += (c.at(left) != c.at(right)) * rr;
        --right;
    }
    //int tmp = 0;
    //int pos = -1;
    //for (int i = 1; i <= n; ++i) {
    //    tmp += a.at(i);
    //    if (tmp >= (L + 1) / 2) {
    //        pos = i;
    //        break;
    //    }
    //}
    //std::cout << pos << "\n";
    //std::cout << left << " " << right << "\n";
    //assert(left == pos && right == pos);
    fout << ans << "\n";
    return 0;
}
