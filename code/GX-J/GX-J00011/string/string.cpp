#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n;
struct Seg {
    int l, r;
    char c;
} segs[N];
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    scanf("%d", &n);
    int record = 1;
    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d %c", &a, &segs[i].c);
        segs[i].l = record;
        segs[i].r = record + a - 1;
        record += a;
    }
    int l = 1, r = n;
    if (n & 1) {
        int pos = 1;
        for (; pos <= n; pos++) {
            if (segs[pos].l <= n / 2 + 1 && n / 2 + 1 <= segs[pos].r) break;
        }
        int iseg = pos;
        int jseg = pos;
        int i = n / 2 + 1, j = n / 2 + 1;
        long long ans = 0;
        while (i >= 1 && j <= n) {
            if (i - segs[iseg].l <= j - segs[jseg].r) {
                ans += i - segs[iseg].l
            }
        }
    }
}
