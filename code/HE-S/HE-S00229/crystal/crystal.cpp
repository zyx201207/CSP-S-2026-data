#include<bits/stdc++.h>
using namespace std;
const int N = 5*1e5+10;
long long a[N];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	for(long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a, a+n);
	long long cnt = 0, c, ans;
	for(long long i = 1; i <= n; i++) {
		c = cnt;
		cnt = 0;
		for(long long j = 1; j <= i; j++) {
			cnt += a[i]-a[j];
		}
		if(cnt > m) {
			cnt = c;
			ans = i-1;
			break;
		}
	}
	cout << ans;
	
	
	return 0;
}
