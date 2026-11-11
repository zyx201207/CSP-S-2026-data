
#include <bits/stdc++.h>
using namespace std;
#define N 200005

int n; string s;

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    // scanf("%d", &n);
    // for (int i = 1; i <= n; i++) {
    //     char s[5];
    //     scanf("%d%s", &a[i], s);
    //     c[i] = s[0];
    //     len += a[i];
    // }
    // long long now = 0; bool ok = 0;
    // for (int i = 1; i <= n; i++) {
    //     now += a[i];
    //     if (now > (len + 1) / 2) {
    //         if (!ok) {
    //             ok = 1;
    //             long long tmp = len / 2 - now + a[i];
    //             if (tmp <= 0) {
    //                 len1 = i - 1;
    //                 b[++len2] = a[i];
    //             } else {
    //                 len1 = i;
    //                 b[++len2] = a[i] - tmp;
    //             } d[len2] = c[i];
    //             if (now - a[i] < (len + 1 >> 1) && (len & 1)) --b[len2];
    //             if (tmp > 0) a[i] = tmp;
    //         } else b[++len2] = a[i], d[len2] = c[i];
    //     } else if (now == (len + 1 >> 1) && (len & 1)) {
    //         --a[i]; ok = 1;
    //         if (a[i] == 0) len1 = i - 1;
    //         else len1 = i;
    //     }
    // }
    // reverse(b + 1, b + len2 + 1);
    // reverse(d + 1, d + len2 + 1);
    // // for (int i = 1; i <= len1; i++) printf("%d %c\n", a[i], c[i]);
    // // puts("----------------------------");
    // // for (int i = 1; i <= len2; i++) printf("%d %c\n", b[i], d[i]);
    // // long long t = 0;
    // // for (int i = 1; i <= len2; i++) t += b[i];
    // // cerr << t << '\n';
    // long long nowi = 0, nowj = 0, lst = 0; b[0] = 0;
    // for (int i = 1, j = 0; i <= len1; i++) {
    //     printf("When i = %d, nowi = %lld, nowj = %lld\n", i, nowi, nowj);
    //     if (nowi + a[i] <= nowj) {
    //         if (d[j] != c[i]) ans += a[i], printf("0, ans += %d\n", a[i]);
    //         lst -= a[i]; nowi += a[i];
    //         continue;
    //     } else if (d[j] != c[i]) ans += b[j] - lst;
    //     nowi += a[i]; nowj += b[++j];
    //     while (nowj <= nowi && j <= len2) {
    //         if (d[j] != c[i]) ans += b[j];
    //         nowj += b[++j];
    //     }
    //     if (nowi > nowj - b[j] && c[i] != d[j])
    //         ans += nowi - nowj + b[j];
    //     lst = nowi - nowj + b[j];
    // } printf("%lld\n", ans);
    for (int i = 1; i <= n; i++) {
        int len; char ch[5];
        scanf("%d%s", &len, ch);
        for (int j = 1; j <= len; j++) s.push_back(ch[0]);
    } int len = s.size(), ans = 0;
    for (int i = 0; i < (len + 1 >> 1) - 1; i++)
        if (s[i] != s[len - i - 1]) ++ans;
    printf("%d\n", ans);
    return 0;
}