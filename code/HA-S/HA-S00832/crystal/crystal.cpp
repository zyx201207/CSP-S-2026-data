#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline ll read() {
	ll a = 0, f = 1;
	char c = getchar();
	while(!isdigit(c)) {
		if(c == '-') f = -1;
		c = getchar();
	}
	while(isdigit(c)) {
		a = a*10 + c-'0';
		c = getchar();
	}
	
	return a*f;
}

ll D(ll sx, ll mx, ll xs) {
	return ((sx+mx)*xs)/2;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	//---------
	int n = (int)read(), ans = -1;
	bool dc = 1;
	ll m = read();
	vector<ll> a(n), d(n-1);
	vector<bool> t(n, 0);
	vector<vector<ll> > dp(n, vector<ll>(n, 0));
	for(int i = 0; i < n; i++) a[i] = read();
	sort(a.begin(), a.end());
	for(int i = 0; i < n-1; i++) {
		d[i] = a[i+1]-a[i];
		if(d[i] != d[0]) dc = 0;
	}
	if(dc) {
		vector<ll> v(n+1, 0);
		for(int i = 1; i <= n; i++) {
			v[i] = D(0, (i-1)*d[0], i);
			if(v[i] > m) {
				cout << i-1;
				return 0;
			}
		}
		cout << n;
		return 0;
	}
	for(int j = 1; j < n; j++) {
		for(int i = 0; i+j < n; i++) {
			dp[i][j] = dp[i][j-1]+j*d[i+j-1];
			if(dp[i][j] <= m) ans = j;
		}
	}
	cout << ans+1;
	
	return 0;
}
