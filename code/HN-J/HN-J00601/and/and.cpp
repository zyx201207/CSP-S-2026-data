#include<bits/stdc++.h>
using namespace std;
bool stl(int a, int b) {
	return a > b; 
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n, m;
	scanf("%d %d", &n, &m);
	long long a[n + 5];
	for(long long i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	if(m == 2) {
		long long ma = -1000;
		for(long long i = 1; i < n; i++) {
			for(long long j = i + 1; j <= n; j++) {
				ma = max(a[i] & a[j], ma);
			}
		}
		printf("%d\n", ma);
		return 0;
	}
	sort(a + 1, a + n + 1, stl);
	if(m == 1) {
		printf("%d\n", a[1]);
	}
	int ans = a[1];
	for(int i = 2; i <= m; i++) {
		ans = ans & a[i]; 
	}
	printf("%d\n", ans);
	return 0;
} 
