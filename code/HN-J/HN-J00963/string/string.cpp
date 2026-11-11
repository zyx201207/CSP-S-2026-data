#include <bits/stdc++.h>
using namespace std;

long long n, a[200010], a2[200010], ans;
char c[200010], c2[200010];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {cin >> a[i] >> c[i]; a2[n + 1 - i] = a[i]; c2[n + 1 - i] = c[i];};
	int i = 1, j = 1;
	while(i <= n && j <= n) {
		if(i == n + 1 && j == n + 1) break;
		if(a[i] == a2[j]) {
			if(c[i] != c2[j]) ans += a[i];
			i ++; j ++; continue; 
		}
		if(a[i] < a2[j]) {
			if(c[i] != c2[j]) ans += a[i];
			a2[j] -= a[i]; i ++; continue;
		}
		if(a[i] > a2[j]) {
			if(c[i] != c2[j]) ans += a2[j];
			a[i] -= a2[j]; j ++; continue;
		}
	}
	cout << ans / 2;
	return 0;
}
