#include <iostream>
#include <algorithm>
#include <cmath>
const int MAXN = 5e5 + 10;
typedef long long LL;
using namespace std;

int n;
LL m, a[MAXN];
LL ans = 1;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	scanf ("%d%lld", &n, &m);
	LL sum = 0;
	for (int i = 1; i <= n; i++) {
		scanf ("%lld", &a[i]);
		sum += a[i];
	}
	
	LL arv = sum / n;
	sort(a + 1, a + 1 + n);
	
	LL cntt = 0;
	for (int i = 1; i <= n; i++) {
		cntt += a[n] - a[i];
	}
	if (cntt <= m) {
		ans = n;
		printf ("%lld\n", ans);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	
//	ans = (long long)sqrt(double(1LL + 8LL * (a[2] - a[1]) * m));
	if (n > 5000) {
		m /= (a[2] - a[1]);
		for (int i = 1; i <= n; i++) {
			m -= i, ans ++;
			if (m <= 0) {
				ans --;
				break;
			}
		}
	}
	else {
		int i = n;
		for (i; i >= 1; i--) {
			if (a[i] <= arv) break;
		}
		for (int j = i - 1; j >= 1; j--) {
			m -= (a[i] - a[j]);
			if (m >= 0) ans ++;
			else break;
		}
	}
	
	printf ("%lld\n", ans);
	
//	printf ("%lld", kjz);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
