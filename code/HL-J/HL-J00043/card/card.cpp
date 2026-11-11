#include <bits/stdc++.h>
using namespace std;
int a[500010], s[500010];
int c[300010], cnt[300010];
/*int find(int u) {
	if(s[u] == 0) return u;
	return s[u] = find(u);
}*/
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for(int i = n; i >= 0; i--) {
		if(c[a[i]] == 0) {
			c[a[i]] = i;
		} else {
			s[i] = c[a[i]];
		}
	}
	//printf("mamamam");
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			//j = find(j);
			if(s[j] != 0) {
				j = s[j];
			}
			cnt[a[j]]++;
		}
	}
	for(int i = 1; i <= m; i++) {
		printf("%d ", cnt[i]);
	}
	return 0;
}
