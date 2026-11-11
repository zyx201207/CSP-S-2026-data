#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline int read() {
    int rd = 0, f = 1, ch = getchar_unlocked();
    while ((ch < 48 || ch > 57) && ch != 45) ch = getchar_unlocked();
    if (ch == 45) f = -1; else rd = ch ^ 48; ch = getchar_unlocked();
    while (ch >= 48 && ch <= 57) rd = (rd << 1) + (rd << 3) + (ch ^ 48), ch = getchar_unlocked();
    return rd * f;
}

inline void write(int x) {
    if (x > 9) write(x / 10);
    putchar_unlocked((x % 10) ^ 48);
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = read();
    ll sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += read();
    }
    write((int)(sum & INT_MAX);
}