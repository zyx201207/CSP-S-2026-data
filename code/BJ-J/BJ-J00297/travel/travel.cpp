#include <iostream>
#include <cmath>

using namespace std;

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' or ch > '9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' and ch <= '9') { x = (x << 3) + (x << 1) + (int)(ch ^ 48); ch = getchar(); }
    return x * f;
}

inline int read2() {
    int x = 0; char ch = getchar();
    while (ch < '0' or ch > '9') { ch = getchar(); }
    x = (x << 3) + (x << 1) + (int)(ch ^ 48); ch = getchar();
    x = (x << 3) + (x << 1) + (int)(ch ^ 48);
}

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    int c1 = read();
    int s1 = read2();
    int k1 = getchar() - 'A';
    int c2 = read();
    int s2 = read2();
    int k2 = getchar() - 'A';

    bool flag = true;

    if (c1 == c2) putchar('1');
    else flag = false, putchar('0');

    if (flag and s1 == s2) putchar('1');
    else flag = false, putchar('0');

    if (flag and k1 / 3 == k2 / 3) putchar('1');
    else flag = false, putchar('0');

    if (flag and abs(k1 - k2) == 1) putchar('1');
    else flag = false, putchar('0');

    return 0;
}
