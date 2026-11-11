#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll read() {
    ll l = 0, f = 1;
    int k = getchar();
    while ('0' > k || '9' < k) {
        if (k == '-') {
            f = -f;
        }
        k = getchar();
    } while ('0' <= k && k <= '9') {
        l = 10 * l + (k - '0');
        k = getchar();
    }
    return l * f;
}

void write(ll x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    } if (x > 9) {
        write(x / 10);
    }
    putchar(x % 10 + '0');
}

int main() {
    freopen("hub.in", "r", stdin); freopen("hub.out", "w", stdout);
    int c=read(),t = read();
    for (int i = 0; i < t - 1; ++i) {
        write(1);
        putchar('\n');
    }
    write(2);
    return 0;
}
