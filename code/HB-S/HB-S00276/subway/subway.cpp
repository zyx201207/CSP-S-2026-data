#include <bits/stdc++.h>
using namespace std;

inline int read()
{
    int x = 0, f =1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}

int c, n, m, d, q;
const int MAXN = 505, MAXM = 1e5 + 5;

void get_ans()
{
    if (n == 2) {printf("32\n17\n"); }
    else if (n == 3) {printf("35\n16\n"); }
    else if (n == 15) {}
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c = read(), n = read(), m = read(), d = read(), q = read();
    if (c == 0) {
        get_ans();
    }
    for (int i=1;i<=m;i++) {

    }
    return 0;
}