#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
	
	ll n, m;
	cin >>n>>m;
	vector<ll> a(n+1);
	for (ll i = 1; i <= n; i++) {
		cin >>a[i];
	}
	sort(a.begin()+1, a.end(), [](ll x, ll y){return x<y;});
	vector<ll> b(n+1, 0);
	for (ll i = 1; i < n; i++) {
		b[i] = a[i+1]-a[i];
	}
	
	vector<int> dp(n+1, 0);
	ll items = 1, chlength = 0, resl = 0, t = 1;
	while(items <= n) {
		dp[items] = dp[items-1] + (items-t)*b[items-1];
		chlength++;
		
		if (dp[items] > m) {
			chlength--;
			dp[items] = dp[items] - (a[items] - a[t-1]);
			t++;
		}
		resl = ((resl > chlength) ? resl : chlength);
		items ++;
	}
	resl = ((resl > chlength) ? resl : chlength);
	cout <<resl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
