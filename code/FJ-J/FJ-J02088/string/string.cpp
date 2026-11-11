#include <bits/stdc++.h>
using namespace std;

int n;
int a[200010];
char c[200010];
long long len = 0;
char s[200010], top = 0;

inline int whats(long long &point) {
	long long p = point;
	int i = 1;
	int ans = 1;
	while (p - a[i] > 0 && ans != n) {
		p -= a[i];
		++ans;
	}
	return ans;
}
int main() { 
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1;i <= n;i++) {
		scanf("%d%s", &a[i], &c[i]);
		len += a[i];
	}
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= a[i];j++)
			s[++top] = c[i];
	}
	long long i = 1, j = len;
	long long ans = 0;
	while (i < j) {
		if (s[i] != s[j])
			++ans;
		++i;
		--j;
	}
	printf("%lld", ans);
	fclose(stdin);
	fclose(stdout);
}
