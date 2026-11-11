//crystal
#include <stdio.h>
#include <algorithm>
int n;
long long m, a[514514], pre[514514];
long long Max(long long a, long long b) {return (a > b) ? a : b;}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d %lld", &n, &m);
	int i;
	for(i = 1; i <= n; i += 1) scanf("%lld", &a[i]);
	std::sort(a + 1, a + n + 1);
	long long lastValid = 0;
	for(i = 1; i <= n; i += 1) {
		pre[i] = pre[i - 1] + a[i];
		if(a[i] * i - pre[i] >= 0 && a[i] * i - pre[i] <= m) {
			lastValid = i;
		}
		else {
			int l = 1, r = i;
			while(l < r) {
				int mid = ((l + r) >> 1);
				long long v = a[i] * (i - mid + 1) - (pre[i] - pre[mid - 1]);
				if(v >= 0 && v <= m) {
					r = mid;
					lastValid = Max(lastValid, i - mid + 1);
				}
				else {
					l = mid + 1;
				}
			}
		}
	}
	printf("%lld", lastValid);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
