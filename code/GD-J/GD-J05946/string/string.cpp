#include <iostream>
#include <cstdio>
using namespace std;

const int maxn = 2e5 + 10;
int a[maxn] = { 0 };
char c[maxn];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	int n;
	unsigned long long ans = 0;
	
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		
		char tmp = getchar();
		c[i] = getchar();
	}
	
	int l = 1, r = n;
	while (l < r) {	
		//cout << l << ' ' << r << ' ' << ans << endl;	
		if (c[l] == c[r]) {
			if (a[l] == a[r]) {
				l++, n--;
			} else if (a[l] > a[r]) {
				a[l] -= a[r--];
			} else {
				a[r] -= a[l++];
			}
		} else {
			if (a[l] == a[r]) {
				ans += a[l];
				l++, n--;
			} else if (a[l] > a[r]) {
				a[l] -= a[r];
				ans += a[r--];
			} else {
				a[r] -= a[l];
				ans += a[l++];
			}
		}
	}
	
	printf ("%lld", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
