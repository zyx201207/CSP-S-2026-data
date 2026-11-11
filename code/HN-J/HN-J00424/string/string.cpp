#include <bits/stdc++.h>

using namespace std;

int n, sum, t;
char s[501], b[251];

int main () {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x;
		char c[3];
		scanf("%d%s", &x, c + 1);
		for (int j = 1; j <= x; j++)
			s[++sum] = c[1];
	}
	if (sum % 2 == 1) {
		for (int i = 1; i <= sum / 2; i++)
			b[i] = s[i];
		for (int i = sum / 2 + 2; i <= sum; i++)
			if (b[i] != s[i])
				t++;
	}
	else {
		for (int i = 1; i <= sum / 2; i++)
			b[i] = s[i];
		for (int i = sum / 2 + 1; i <= sum; i++)
			if (b[i] != s[i])
				t++;
	}
	printf("%d\n", t);
	return 0;
}
