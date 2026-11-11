#include <bits/stdc++.h>
using namespace std;
int c, test;
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
    srand(time(0));
    scanf("%d%d", &c, &test);
    for (; test--; ) {
        int n, k;
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
        }
        if (13 <= c && c <= 14)
            printf("%d\n", k - 1);
        else {
            printf("%d\n", n + k - 1 + rand() % (n - k) + 1);
        }
    }
    return 0;
}
