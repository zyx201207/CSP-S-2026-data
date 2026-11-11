//GZ-S00140 贵阳市第一中学 赵思翰

#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 5e5 + 5;
ll n, m;
ll ans;
ll a[MAXN];

int main() {
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	sort(a + 1, a + 1 + n);
	
	ll l = 1, r = 2;
	ll w = 0;

	while(l <= r && r <= n) {
		if(w + (a[r] - a[r - 1]) * (r - l) <= m) {
			w = w + (a[r] - a[r - 1]) * (r - l);
			ans = max(ans, r - l + 1);
			r++;
		}
		else {
			w = w - (a[r] - a[l]);
			l++;
		}
	}
	
	cout << ans;
	
	return 0;
} 
