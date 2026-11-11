#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n, m, a[N];
bool b[N];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) b[i] = true;
	int ans = 0;
	for (int i = 29; i >= 0; i--) {
		int res = 0;
		for (int j = 1; j <= n; j++) 
			if (b[j]) 
				res += (1 & (a[j] >> i));
		if (res >= m) {
			ans |= (1 << i);
			for (int j = 1; j <= n; j++)
				if (b[j] && !(1 & (a[j] >> i)))
					b[j] = false;
		}
	}
	printf("%d\n", ans);
	return 0;
}