#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005];
bool cmp(ll a, ll b) {
	return a > b;
}
ll pow_(ll a, int b) {
	ll ans = 1;
	for(int i = 1; i <= b; i++) ans *= a;
	return ans;
} 
int main() {
	freopen("and.in", "r", stdin);
	freopen("ans.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i]; 
	}                      
	if(m == 1) {            
		ll mmax = -1;
		for(int i = 1; i <= n; i++) {
			if(mmax < a[i]) mmax = a[i];
		}
		cout << mmax;
	} else if(m == n) {
		ll ans = pow_(2ll, 31) - 1;
		for(int i = 1; i <= n; i++) {
			ans = ans & a[i];
		}
		cout << ans;
	} else if(m == 2) {
		ll ans = -1;
		for(int i = 1; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
				if(ans < (a[i] & a[j])) ans = a[i] & a[j];
			}
		}
		cout << ans;
	} else if(m == n - 1) {
		ll ans = -1;
		for(int i = 1; i <= n; i++) {
			ll sum = pow_(2ll, 31) - 1;
			for(int j = 1; j <= n; j++) {
				if(i != j) sum = sum & a[j];
			}
			if(ans < sum) ans = sum;
		}
		cout << ans;
	} else {
		sort(a + 1, a + 1 + n, cmp);
		ll ans = pow_(2ll, 31) - 1;
		for(int i = 1; i <= m; i++) ans = ans & a[i];
		cout << ans;
	}
	return 0;
}
