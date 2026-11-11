#include <bits/stdc++.h>
#define fi first
#define se second
typedef long long ll;
typedef double db;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;
typedef __int128 LL;
typedef unsigned long long ull;

int main() {
    #ifndef LOCAL
        freopen("travel.in", "r", stdin);
        freopen("travel.out", "w", stdout);
    #endif
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::string c1, s1, c2, s2;
    std::cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) {
        std::cout << 1;
        if (s1[0] == s2[0] && s1[1] == s2[1]) {
            std::cout << 1;
            ll a = s1[2] - 'A';
            ll b = s2[2] - 'A';
            if ((a < 3 && b < 3) || (a > 2 && b > 2)) {
                std::cout << 1;
                if (std::abs(a - b) == 1) {
                    std::cout << 1;
                }
                else {
                    std::cout << 0;
                }
            }
            else {
                std::cout << "00";
            }
        }
        else {
            std::cout << "000";
        }
    }
    else {
        std::cout << "0000";
    }
    return 0;
}