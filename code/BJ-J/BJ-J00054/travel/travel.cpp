#include <bits/stdc++.h>


int chexiang1, chexiang2;
char zuowei1[3], zuowei2[3];

bool issamePai() {
    if (chexiang1 != chexiang2) return false;
    if (zuowei1[0] == zuowei2[0] && zuowei1[1] == zuowei2[1]) return true;
    else return false;
}

bool isTongce() {
    char ce1 = zuowei1[2];
    char ce2 = zuowei2[2];

    if (ce1 == 'A' || ce1 == 'B' || ce1 == 'C') {
        if (ce2 == 'A' || ce2 == 'B' || ce2 == 'C') return true;
        else return false;
    } else {
        if (ce2 == 'D' || ce2 == 'F') return true;
        else return false;
    }
}

bool isXiangling() {
    if (zuowei1[2] == char(zuowei2[2] - 1)) return true;
    if (zuowei2[2] == char(zuowei1[2] - 1)) return true;
    if (zuowei1[2] == 'D' && zuowei2[2] == 'F') return true;
    if (zuowei1[2] == 'F' && zuowei2[2] == 'D') return true;
    return false;
}

int main() {
    std::freopen("travel.in", "r", stdin);
    std::freopen("travel.out", "w", stdout);

    std::cin >> chexiang1 >> zuowei1 >> chexiang2 >> zuowei2;

    if (chexiang1 == chexiang2) std::cout << 1;
    else std::cout << 0;

    if (issamePai()) std::cout << 1;
    else std::cout << 0;

    if (issamePai() && isTongce()) std::cout << 1;
    else std::cout << 0;

    if (issamePai() && isTongce() && isXiangling()) std::cout << 1;
    else std::cout << 0;

    return 0;
}
