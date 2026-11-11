#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500009];
int main(){
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	scanf ("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf ("%lld", &a[i]);
	}
	sort (a + 1, a + n + 1);
	if (n == 1) {
		printf ("1");
		return 0;
	}
	if (n <= 5000) {
		int d = 0;
		for (int i = 1; i <= n; i++) {
			int sum = 1;
			long long z = m;
			for (int j = i - 1; j >= 1; j--) {
				if (a[i] - a[j] <= z) {
					sum++;
					z = z - (a[i] - a[j]);
				}
				else {	
					break;
				}
			}
			d = max (d, sum);
		}
		printf ("%d", d);
		return 0;
	}
	int sum = 1;
	long long z = a[2] - a[1];
	while (m >= z) {
		if (sum >= n) {
			break;
		}
		if (m >= z) {
			sum++;
			m = m - z; 
		}
		z = z + z;
	}
	printf ("%d", sum);
	return 0;
} 
