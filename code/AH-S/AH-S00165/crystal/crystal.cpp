#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n;
long long m;
long long a[N], sum[N];
bool check(int x) {
	for(int i = 1; i + x - 1 <= n; ++i) {
		int j = (i + x - 1);
		
		if(a[j] * x - (sum[j] - sum[i - 1]) <= m) return true;
	}
	
	return false;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	scanf("%d", &n);
	scanf("%lld", &m);
	
	for(int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
	}
	
	sort(a + 1, a + n + 1);
	
	for(int i = 1; i <= n; ++i) {
		sum[i] = sum[i - 1] + a[i];
	}
	
	
	int l = 1, r = n, ans = 0;
	
	while(l <= r) {
		int mid = (l + r) / 2;
		if(check(mid)) {
			l = mid + 1;
			ans = mid;
		} else {
			r = mid - 1;
		}
	}
	
	cout << ans << endl;
}
