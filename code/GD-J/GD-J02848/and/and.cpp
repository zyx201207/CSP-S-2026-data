#include<bits/stdc++.h>
using namespace std;
long long n, m, a[200005], ans; 
bool B[200005];
void xz(int x, long long y) {
	if(x == m - 1) {
		for(int i = 1; i <= n; i ++) {
			if(!B[i]) {
				long long t = (y & a[i]);
				if(t > ans) {
					ans = t;
				}
			}
		}
		return;
	}
	for(int i = 1; i <= n; i ++) {
		if(!B[i]) {
			B[i] = true; 
			xz(x + 1, (y & a[i]));
			B[i] = false;
		}
	}
	return;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= n; i ++) {
		scanf("%lld", &a[i]);
	}
	xz(0, 9223372036854775807);
	printf("%lld", ans);
	return 0;
}
