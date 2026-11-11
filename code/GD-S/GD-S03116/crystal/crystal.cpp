#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m;

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	ll h = m;
	ll a[n+2];
	for (int i = 0;i < n;i ++) {
		cin >> a[i];
	}
	ll ans=1,lastans=0,num=0;
	ll nums[n];
	for (ll i = 0;i <= n-1;i ++) {
		num = a[i+1] - a[i];
		if (num < 0) num = -1 * num;
		nums[i] = num;
	};
	ll r = 1;
	ll sum = 0;
	ll ss = 1;
	for (ll i = 1;i <= n;i ++) {
		m = h;
		sum = 0;
		r = 1;
		for (ll j = i;j <= n;j ++) {
			sum += nums[j] * r;
			m = m - sum;
			r ++;
			if (m >= 0) {
				ss = ss + 1;
			}
			else {
				ans = max(ss,lastans);
				lastans = ss;
				break;
			}
		}
	}
	cout << ans;
	return 0;
} 
