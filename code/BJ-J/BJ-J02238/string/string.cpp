#include <bits/stdc++.h>
using namespace std;
long long n, ln = 1, rn, llen, rlen = 0, len, ans = 0, temp;
int a[200005];
char c[200005];
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
        len += a[i];
    }
    rn = n, llen = a[1], rlen = len;
    for(long long i = 0; i < len / 2; i) {
        if(ln >= rn) {
            break;
        }
        if(i > llen) {
            ln++;
            llen += a[ln];
        }
        if(len - i <= rlen - a[rn - 1]) {
            rn--;
            rlen -= a[rn];
        }
        temp = 1;
        if(c[ln] != c[rn]) {
            ans += temp;
        }
        i += temp;
    }
    printf("%lld\n", ans);
    return 0;
}
