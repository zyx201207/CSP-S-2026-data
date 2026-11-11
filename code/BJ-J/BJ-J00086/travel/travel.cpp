#include <bits/stdc++.h>
#define int long long
using namespace std;
#define gc() getchar()
inline int rd() {
    int x = 0, f = 1;
    char c = gc();
    for (; !isdigit(c); c = gc()) if (c == '-') f = -1;
    for (; isdigit(c); c = gc()) x = x * 10 + c - '0';
    return x * f;
}
inline void wt(int x) {
    if (x < 0) putchar('-'), x = -x;
    if (x >= 10) wt(x / 10);
    putchar(x % 10 + '0');
}
char c1[4], s1[4], c2[4], s2[4];
bool f1(char c1, char c2) {
    if (c1 <= 'C' && c2 <= 'C') return 1;
    return 'D' <= c1 && 'D' <= c2;
}
bool f2(char c1, char c2) {
    return c1 - c2 == 1 || c2 - c1 == 1;
}
signed main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
//    freopen("1.in", "r", stdin);
//    freopen("1.out", "w", stdout);
    scanf("%s%s%s%s", c1 + 1, s1 + 1, c2 + 1, s2 + 1);
    if (c1[1] == c2[1] && c1[2] == c2[2]) {
        if (s1[1] == s2[1] && s1[2] == s2[2]) {
            if (f1(s1[3], s2[3])) {
                if (f2(s1[3], s2[3])) {
                    puts("1111");
                } else puts("1110");
            } else puts("1100");
        } else puts("1000");
    } else puts("0000");
    return 0;
}
