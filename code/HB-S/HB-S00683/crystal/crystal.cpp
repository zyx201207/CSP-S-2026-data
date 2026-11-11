#include <bits/stdc++.h>
using namespace std;

const long long MxN = 500005;
long long n, m, a[MxN];

bool check(long long s, long long x) {
    long long sum = 0;
    for (int i = s; i < x; i++) {
        sum += a[x] - a[i];
    }
    return sum <= m;
}

long long ef(long long l, long long r) {
    long long ss = l;
    while (l < r) {
        if (r - 1 == l) {
            if (check(ss, r)) l = r;
            break;
        }
        long long mid = (l + r) / 2;
        if (check(ss, mid)) {
            l = mid;
        } else {
            r = mid;
        }
        // printf("%lld %lld\n", l, r);
    }
    return l;
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", a + i);
    }
    sort(a + 1, a + n + 1);
    long long l = 1, r = n + 1;
    if (n <= 5000) {
        long long mx = 0;
        for (int i = 1; i <= n; i++) {
            long long tmp = ef(1, n + 1);
            mx = max(mx, tmp);
        }
        printf("%lld", mx);
    } else {
        printf("%lld", ef(1, n + 1));
    }
    return 0;
} // 75?