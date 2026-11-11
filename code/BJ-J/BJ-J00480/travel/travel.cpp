#include<bits/stdc++.h>

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    std::string a1, a2, b1, b2;
    std::cin >> a1 >> a2 >> b1 >> b2;
    if (a1[1] == b1[1] && a1[0] == b1[0]) {
        std::cout << "1";
    } else {
        std::cout << "0000";
        return 0;
    }
    if (a2[1] == b2[1] && a2[0] == b2[0]) {
        std::cout << "1";
    } else {
        std::cout << "000";
        return 0;
    }
    bool flag = true;
    if ((a2[2] <= 'C' && b2[2] >= 'D') || (a2[2] >= 'D' && b2[2] <= 'C')) {
        std::cout << "00";
        flag = false;
        return 0;
    } else {
        std::cout << "1";
    }
    if (a2[2] <= 'C') {
        if (std::abs(a2[2] - b2[2]) == 1) {
            std::cout << "1";
        } else {
            std::cout << "0";
        }
    }
    if (a2[2] >= 'D') {
        std::cout << "1";
    }
    if (!flag) std::cout << "0";
    return 0;
}
