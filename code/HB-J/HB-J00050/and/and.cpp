#include <bits/stdc++.h>
using namespace std;
#define N 200005

int n, m, ans;
bool b[32][N], in[N];

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        for (int j = 0; j <= 30; j++)
            if ((x >> j) & 1) b[j][i] = 1;
        in[i] = 1;
    }
    for (int j = 30; j >= 0; j--) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) if (in[i] && b[j][i]) ++cnt;
        if (cnt >= m) {
            for (int i = 1; i <= n; i++)
                if (in[i] && !b[j][i]) in[i] = 0;
            ans += (1 << j);
        }
    } printf("%d\n", ans);
    return 0;
}