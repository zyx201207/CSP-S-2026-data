#include <bits/stdc++.h>
using namespace std;
long long ppc(long long x) { long long cnt = 0; while(x) {x &= (x - 1); cnt++;} return cnt; }
long long digit(long long x) {
	long long cnt = 0;
	while(x) {
		x >>= 1;
		cnt ++;
	}
	return cnt;
}
long long a[500005];
bool cmp(int x , int y) {
	return ppc(x) > ppc(y);
}
int main() {
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long n , m;
	cin >> n >> m;
	for(long long i = 0; i < n; i++) cin >> a[i];
	if(n <= 20) { //枚举 
		long long ans = 0;
		for(long long mask = 0; mask < (1 << n); mask++) {
			long long res = (1 << 25);
			if(ppc(mask) != m) continue;
			long long digit = 0 , base = 1;
			while(base <= mask) {
				if(mask & base){
					res &= a[digit];
				}
				digit ++;
				base <<= 1; 
			}
			ans = max(ans , res);
		}
		cout << ans;
	} else if(m == 1) {
		long long ans = 0; for(long long i = 0; i < n; i++) ans = max(ans , a[i]); cout << ans;
	} else if(m == 2) {
		long long ans = 0;
		for(long long i = 0; i < n; i++) {
			for(long long j = (i + 1); j < n; j++) {
				ans = max(ans , a[i] & a[j]);
			}
		}
		cout << ans;
	} else {
		bool condition = true;
		for(int i = 0; i < n; i++) {
			condition &= (ppc(a[i]) == digit(a[i]));
		}
		if(condition) { //全是1 
			sort(a , a + n , cmp);
			cout << a[m]; //此时前m个数与运算等于第m个数 
		}
	}
	return 0;
}
