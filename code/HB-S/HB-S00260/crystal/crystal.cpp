#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long n;
long long m, a[N], ans;

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(long long i = 1ll; i <= n; i += 1ll) scanf("%lld", &a[i]);
	sort(a + 1ll, a + 1ll + n);
	long long ct = 1, x = a[1];
	for(long long i = 2ll; i <= n; i += 1ll){
		if(x == a[i]) ct++;
		else ct = 1;
		x = a[i];
		ans = max(ans, ct);
	}
	long long l = a[1], r = a[n];
	while(l <= r){
		long long mid = l + (r - l) / 2ll;
		long long loc = 0, cnt = 0;
		bool flag = 0;
		for(long long i = 1ll; i <= n; i += 1ll){
			if(a[i] > mid) break;
			if(loc > m){
				flag = 1;
				break;
			}
			cnt++;
			loc += (mid - a[i]);
		}
		if(!flag){
			ans = max(ans, cnt);
			l = mid + 1ll;
		}else r = mid - 1ll;
	}
	cout << ans;
	return 0;
}
