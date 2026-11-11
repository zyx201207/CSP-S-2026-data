#include <cstdio>
#define rep(i, l, r) for (int i = (l); i <= (r); i++)
#define per(i, r, l) for (int i = (r); i >= (l); i--)
using namespace std;
int n, m;
int a[200010];
bool hasbit(int x, int pos) {
    return x & (1 << pos);
}
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    scanf("%d%d", &n, &m);
    rep (i, 1, n) scanf("%d", &a[i]);
    int ans = 0;
    per (pos, 30, 0) {
        int cnt = 0;
        int t = ans | (1 << pos);
        rep (i, 1, n) cnt += (t & a[i]) == t;
        if (cnt >= m) ans = t;
        // printf("%d %d\n", t,  cnt);
    }
    printf("%d", ans);
    return 0;
}
