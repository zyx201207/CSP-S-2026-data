#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 500000;

int n;
long long m;
long long a[N + 5], s[N + 5];

bool chk(int l, int r) {
    //printf("chk: l=%d, r=%d\n", l, r);
    //printf("exp: %lld, now: %lld\n", );
    return a[r] * (r - l) - (s[r - 1] - s[l - 1]) <= m;
}


long long fr() {
    long long x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while ('0' <= c && c <= '9') {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return x * f;
}

int main() {
    //if (false) {
        freopen("crystal.in", "r", stdin);
        freopen("crystal.out", "w", stdout);
    //}
    n = fr();
    m = fr();
    for (int i = 1; i <= n; i++) {
        a[i] = fr();
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        int l = 1, r = i;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (chk(mid, i)) r = mid;
            else l = mid + 1;
        }
        //printf("i=%d, l=%d\n", i, l);
        ans = max(ans, i - l + 1);
    }
    printf("%d\n", ans);
    return 0;
}
