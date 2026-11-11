# include <bits/stdc++.h>
using namespace std;
const int N = 1e8 + 5;
long long n, m, a[N], maxx, max2, maxi, s[N], ans;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+1+n);
	for (int i = 1; i <= m; i++){
		s[i] = a[i];
		ans |= s[i];
	}
	printf("%lld", ans);
	return 0;
}
