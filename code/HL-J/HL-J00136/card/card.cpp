#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], cnt[500005], ans[500005];
bool used[500005];
struct node {
	int s, e;
} num[500005];
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
    	scanf("%d", &a[i]);
	}
	for (int j = 1; j < n; j++) {
		if (used[j]) {
			continue;
		}
		int k = 1;
		while (j - k >= 1 && j + k <= n) {
			if (a[j - k] == a[j + k]) {
				for (int l = j - k; l < j + k; l++) {
					num[l] = {j - k, j + k};
				}
				break;
			}
			k++;
		}
	}
	for (int i = 1; i <= n; i++) {
		cnt[n]++;
		for (int j = i; j < n; j++) {
			if (!num[j].s || num[j].s < i) {
				cnt[j]++;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		ans[a[i]] = max(ans[a[i]], cnt[i]);
	}
	for (int i = 1; i <= m; i++) {
		printf("%d ", ans[i]);
	}
    return 0;
}
