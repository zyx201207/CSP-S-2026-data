/*
14:57提交
水到家了，第一题，感觉会有一车人过A+基础暴力，区分度会很达芬
奖励一块巧克力。家委会的就是爽
*/

#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 500010;
int n;
ll m;
ll a[N];
ll d[N];
int l, r, mid, best = -1;

bool check (int x) { x --;
    ll now = 0;
    for (int i = 2; i <= x + 1; i ++) {
        now += d[i] * (i - 1);
    } for (int i = 2; i + x - 1 <= n; i ++) {
        if (now <= m) return true;
        now -= a[i + x - 1] - a[i - 1];
        now += x * d[i + x];
    }
    return false;
}

int main () {
    freopen ("crystal.in", "r", stdin);
    freopen ("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; i ++) {
        scanf("%lld", a + i);
    } sort (a + 1, a + n + 1);
    for (int i = 1; i <= n; i ++) {
        d[i] = a[i] - a[i - 1];
    } d[1] = 1145141919810810810; //fang zhi nao chou
    l = 2, r = n;
    while (l <= r) {
        mid = l + r >> 1;
        if (check (mid)) {
            best = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    } if (best == -1) printf("1\n");
    else printf("%d\n", best);
    return 0;
}