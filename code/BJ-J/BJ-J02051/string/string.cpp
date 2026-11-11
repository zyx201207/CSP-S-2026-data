#include<bits/stdc++.h>
using namespace std;

int n;
long long mid, cnt;

struct str{
    char s;
    long long l, r;
}a[200005];

int f(long long x) {
    for (int i = 1; i <= n; i++)
        if (x >= a[i].l && x <= a[i].r)
            return i;
}

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    scanf("%d", &n);
    for (int x, i = 1; i <= n; i++) {
        scanf("%d %c", &x, &a[i].s);
        a[i].l = a[i - 1].r + 1;
        a[i].r = a[i - 1].r + x;
    }
    long long i = f(a[n].r >> 1), j = f(((1 + a[n].r) >> 1) + 1), mid = (1 + a[n].r + 1) >> 1;
    printf("%lld %lld %lld\n", i, j, mid);
    while (i >= 1 && j <= n) {
        if (a[i].s != a[j].s) {
            if (mid != -1) {//                     mid
                if (mid == i)//                .....|..***
                    a[i].r = 2 * mid - a[i].r;
                else if (mid == j)//           ...**|*****
                    a[j].l = 2 * mid - a[j].l;
                mid = -1;
            }
            int leni = a[i].r - a[i].l + 1, lenj = a[j].r - a[j].l + 1;
            int mn = min(leni, lenj);
            a[i].r -= mn, a[j].l += mn;
            if (a[i].r <= a[i].l)
                i--;
            if (a[j].l >= a[j].r)
                j++;
            cnt += mn;
//            printf("%lld %lld %lld %lld %lld\n", a[i].l, a[i].r, a[j].l, a[j].r, mid);
        }
        else {
            if (i == j) {
                i--, j++;
                continue;
            }
            int leni = a[i].r - a[i].l + 1, lenj = a[j].r - a[j].l + 1;
            int mn = min(leni, lenj);
            a[i].r -= mn, a[j].l += mn;
            if (a[i].r == a[i].l)
                i--;
            if (a[j].l == a[j].r)
                j++;
        }
    }
    printf("%lld", cnt);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
