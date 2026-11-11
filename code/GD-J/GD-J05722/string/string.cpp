#include<bits/stdc++.h>
#define I return
#define AK 0
#define IOI ;
using namespace std;
long long n, m, k, x, y, a[1234567], ans;
char c[1234567];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n, x = 1, y = n;
	for(int i = 1; i <= n; i++)cin >> a[i] >> c[i];
	while(x < y) {
		k = min(a[x], a[y]);
		if(c[x] != c[y])ans += k;
		a[x] -= k, a[y] -= k;
		if(a[x] == 0)x++;
		if(a[y] == 0)y--;
	}
	cout << ans << '\n';
	return 0;
}
