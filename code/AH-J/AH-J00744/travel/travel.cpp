#include <bits/stdc++.h>

using namespace std;

inline int read() {
    int f = 1, x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch <= '9' && ch >= '0') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return f * x;
}

inline void write(int x) {
    if (x < 0) {
        x = -x;
        putchar('-');
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

const int N = 100005, INF = 0x3f3f3f3f;

signed main(void) {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string a, b, x, y;
    int flag = 1;
    cin >> a >> b >> x >> y;
    if (a == x) write(1);
    else {
        flag = 0;
        write(0);
    }
    if (flag && b.substr(0, 2) == y.substr(0, 2)) write(1);
    else {
        write(0);
        flag = 0;
    }
    if (flag && (b[2] <= 'C' && y[2] <= 'C') || (b[2] >= 'D' && y[2] >= 'D')) write(1);
    else {
        write(0);
        flag = 0;
    }
    if (flag && (b[2] == 'D' && y[2] == 'F') || (b[2] == 'F' && y[2] == 'D')) {
        write(1);
        return 0;
    }
    if (flag && abs(b[2] - y[2]) == 1) write(1);
    else write(0);
    return 0;
}
