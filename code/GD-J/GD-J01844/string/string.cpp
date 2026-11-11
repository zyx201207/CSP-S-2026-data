#include <bits/stdc++.h>
using namespace std;
int n, a[201000];
char c[201000];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d %c", &a[i], &c[i]);
	long long sum = 0, ans = 0;
	for (int i = 1; i <= n; i++)
		sum += a[i];
	if (sum <= 2000 * 50) {
		string s;
		s.clear();
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= a[i]; j++)
				s += c[i];
		int len = s.size(), ans = 0;
		for (int i = 0; i < len / 2; i++) {
			if (s[i] != s[len - i - 1])
				ans++;
		}
		printf("%d\n", ans);
		return 0;
	}
	int i = 1, j = n;
	while (i < j) {
		if (c[i] == c[j]) {
			int x = min(a[i], a[j]);
			a[i] -= x;
			a[j] -= x;
			if (a[i] == 0)
				i++;
			if (a[j] == 0)
				j--;
		}
		else {
			// c[i] != c[j]
			int x = min(a[i], a[j]);
			ans += x;
			a[i] -= x;
			a[j] -= x;
			if (a[i] == 0) 
				i++;
			if (a[j] == 0)
				j--;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
