#include <iostream>
#include <string>
std::string c1, s1, c2, s2;
int juedui(int a, int b) {
    if (a < b) {
        return (b - a);
    }
    else {
        return (a - b);
    }
}
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> c1 >> s1 >> c2 >> s2;
    if (c1 != c2) {
        std::cout << 0000 << '\n';
        return 0;
    }
    else {
        std::cout << 1;
        if (s1[0] != s2[0] || s1[1] != s2[1]) {
            std::cout << 000 << '\n';
        }
        else {
            std::cout << 1;
            if (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') {
                if (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') {
                    std::cout << 1;
                    if(juedui((int)(s1[2]), (int)(s2[2])) == 1) {
                        std::cout << 1 << '\n';
                    }
                    else {
                        std::cout << 0 << '\n';
                    }
                }
                else {
                    std::cout << 00 << '\n';
                }
            }
            if (s1[2] == 'D' || s1[2] == 'F') {
                if (s2[2] == 'D' || s2[2] == 'F') {
                    std::cout << 11 << '\n'
                }
                else {
                    std::cout << 00 << '\n';
                }
            }
        }
    }
    return 0;
}