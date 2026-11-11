#include<bits/stdc++.h>
using namespace std;
long long n , m , a[500005] , maxx = 1;
int main() {
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	cin >> n >> m;
	for(long long i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1 , a + 1 + n);
	long long l = n - 1 , r = n , cost = a[n] - a[n - 1];
	while(l >= 1) {
		if(cost <= m) {
			maxx = max(maxx , r - l + 1);
			l--;
			cost += a[r] - a[l];
		}
		else {
			cost -= (r - l) * (a[r] - a[r - 1]);
			r--;
		}
	}
	cout << maxx;
	return 0;
}
