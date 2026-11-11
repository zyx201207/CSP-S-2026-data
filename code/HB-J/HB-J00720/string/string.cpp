#include <bits/stdc++.h>
#define i64 long long
using namespace std;

const i64 MxN = 200005;
i64 n, a[MxN];
i64 st[MxN];
char c[MxN];

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    scanf("%lld", &n);
    for (i64 i = 1; i <= n; i++) {
        scanf("%lld", a + i);
        getchar();
        scanf("%c", c + i);
    }
    i64 i = 1, j = n;
    i64 gsum = 0;
    while (1) {
        if (i >= j) break;
        if (c[i] != c[j]) {
            gsum += min(a[i], a[j]);
        }
        if (a[i] < a[j]) {
            a[j] -= a[i];
            i++;
        }
        if (a[i] > a[j]) {
            a[i] -= a[j];
            j--;
        }
        if (a[i] == a[j]) {
            i++;
            j--;
        }
    }
    printf("%lld", gsum);
    return 0;
}