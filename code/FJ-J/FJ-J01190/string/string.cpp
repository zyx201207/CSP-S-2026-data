#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n;
char c[N];
long long a[N], ans = 0;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		char ch;
		scanf("%lld", &a[i]);
		scanf("%c", &ch); 
		scanf("%c", &c[i]);
	}
	int i = 1, j = n;
	while (i < j) {
		if (c[i] == c[j]) {
			if (a[i] >= a[j]) {
				a[i] -= a[j];
				a[j] = 0;
				j--;
			} else {
				a[j] -= a[i];
				a[i] = 0;
				i++;
			}
		} else {
			if (a[i] <= a[j]) {
				ans += a[i];
				a[j] -= a[i];
				a[i] = 0;
				i++;
			} else {
				ans += a[j];
				a[i] -= a[j];
				a[j] = 0;
				j--; 
			}
		}
	}
	printf("%lld", ans);
	return 0;
}
