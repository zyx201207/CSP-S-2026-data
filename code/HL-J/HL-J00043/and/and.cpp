#include <bits/stdc++.h>
using namespace std;
int a[200010];
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	scanf("%d", &a[1]);
	int cnt = a[1], maxn = a[1];
	for(int i = 2; i <= n; i++) {
		scanf("%d", &a[i]);
		cnt = cnt & a[i];
		maxn = max(maxn, a[i]);
	}
	if(m == 1) {
		printf("%d", maxn);
	} else if(m == n) {
		printf("%d", cnt);
	} else {
		sort(a + 1, a + 1 + n, cmp);
		int sum = a[1];
		for(int i = 2; i <= m; i++){
			sum = sum & a[i];
		} 
		printf("%d", sum);
	}
	return 0;
}
