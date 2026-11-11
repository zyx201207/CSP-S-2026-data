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
const int MAXN = 2e5 + 5;
int n, sum, a[MAXN], n1, n2, a1[MAXN], a2[MAXN];
char c[MAXN], c1[MAXN], c2[MAXN];
void init() {
    int ss = 0;
    for (int i = 1; i <= n; i++) {
        if (ss + a[i] <= sum) {
            a1[++n1] = a[i];
            c1[n1] = c[i];
            ss += a[i];
            if (ss == sum) break;
        } else {
            a1[++n1] = sum - ss;
            c1[n1] = c[i];
            break;
        }
    }
    ss = 0;
    for (int i = n; i; i--) {
        if (ss + a[i] <= sum) {
            a2[++n2] = a[i];
            c2[n2] = c[i];
            ss += a[i];
            if (ss == sum) break;
        } else {
            a2[++n2] = sum - ss;
            c2[n2] = c[i];
            break;
        }
    }
}
signed main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
//    freopen("1.in", "r", stdin);
//    freopen("1.out", "w", stdout);
    n = rd(), sum = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        sum += a[i];
        scanf(" %c", &c[i]);
    }
    sum /= 2;
    init();
    int i = 1, j = 1, s1 = 0, s2 = 0;
    char ch1 = 0, ch2 = 0;
    int ans = 0;
    while (i <= n1 && j <= n2) {
        if (s1 < s2) {
            if (c1[i] == ch2) ans += min(a1[i], s2 - s1);
            ch1 = c1[i];
            s1 += a1[i];
            i++;
        } else {
            if (c2[j] == ch1) ans += min(a2[j], s1 - s2);
            ch2 = c2[j];
            s2 += a2[j];
            j++;
        }
    }
    while (i <= n1) {
        if (c1[i] == ch2) ans += min(a1[i], s2 - s1);
        ch1 = c1[i];
        s1 += a1[i];
        i++;
    }
    while (j <= n2) {
        if (c2[j] == ch1) ans +=min(a2[j], s1 - s2);
        ch2 = c2[j];
        s2 += a2[j];
        j++;
    }
    wt(sum - ans);
    return 0;
}
