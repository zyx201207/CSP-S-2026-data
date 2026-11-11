#include<bits/stdc++.h>
#define I return
#define AK 0
#define IOI ;
using namespace std;
long long n, m, k, x, y, a[1234567], b[1234567], ans;
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int j = 30; j >= 0; j--) {
		k = 0;
		for(int i = 1; i <= n; i++)if(a[i] & (1 << j))b[++k] = a[i];
		if(k >= m) {
			for(int i = 1; i <= k; i++)a[i] = b[i];
			n = k;
			ans += 1 << j;
		}
	}
	cout << ans << '\n';
	return 0;
}
