#include <bits/stdc++.h>
using namespace std;

struct ss {
    int numb;
    bool is1[35];
} sss[200005];

int n, m, w[35];

bool cmp(ss a, ss b) {
    long long tt = 1, aa = 0, bb = 0;
    for (int i = 1; i <= 33; i++) {
        aa += w[i] * a.is1[i] * tt;
        bb += w[i] * b.is1[i] * tt;
        tt *= 2;
    }
    return aa > bb;
}

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    scanf("%d%d", &n, &m);
    int t;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t);
        sss[i].numb = t;
        for (int j = 1; t; j++) {
            w[j] += t & 1;
            sss[i].is1[j] = t & 1;
            t >>= 1;
        }
    }
    for (int i = 1; i <= 35; i++) {
        w[i] = w[i] >= m;
    }
    sort(sss + 1, sss + n + 1, cmp);
    int ans = sss[1].numb;
    for (int i = 2; i <= m; i++) {
        ans &= sss[i].numb;
    }
    printf("%d", ans);
    return 0;
}