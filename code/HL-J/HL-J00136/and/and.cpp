#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005], ans, tim;
bool cmp(int x, int y) {
	return x > y;
}
void dfs(int last, int rem, int res) {
	tim++;
	if (tim > 9e7 + 5e6) {
		return;
	}
	if (res < ans) {
		return;
	}
	if (rem <= 0) {
		ans = max(ans, res);
		return;
	}
	for (int i = last + 1; i <= n - rem + 1; i++) {
		dfs(i, rem - 1, res & a[i]);
	}
}
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1, cmp);
    if (m == n) {
        ans = a[1];
        for (int i = 1; i <= n; i++) {
            ans = ans & a[i];
        }
    }
    else if (m == 1) {
        ans = a[1];
    }
    else {
        dfs(0, m, (1 << 31) - 1);
    }
    printf("%d", ans);
    return 0;
}
