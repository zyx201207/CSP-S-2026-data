#include <stdio.h>
#include <vector>
int a[500005];
int cnt[500005];
bool s[500005];
std::vector<int> q;
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	for (int i = 0; i < n; i++) {
		q.clear();
		for (int j = i; j < n; j++) {
			if (s[a[j]]) {
				while (!q.empty()) {
					int k = q.back();
					q.pop_back();
					s[k] = 0;
					if (k == a[j]) break;
				}
			}
			q.push_back(a[j]);
			s[a[j]] = 1;
		} 
		for (int v: q) {
			cnt[v]++;
			s[v] = 0;
		}
	}
	for (int i = 1; i <= m; i++) {
		printf("%d ", cnt[i]);
	}
	return 0;
} 
