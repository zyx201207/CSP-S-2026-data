#include<iostream>
#include<algorithm>
#define ll long long
#define N 500005 
using namespace std;

ll n, m;
ll a[N], p[N];
ll ans = 1;

int main() {
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);	
	
	cin >> n >> m;
	for(ll i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(ll i = 1; i <= n; i++) p[i] = p[i - 1] + a[i];
	
	for(ll i = 2; i <= n; i++) {
		ll l = 1, r = i;
		while(l <= r) {
			ll mid = l + r >> 1;
			if(p[i] - p[mid - 1] + m >= a[i] * (i - mid + 1)) {
				r = mid - 1;
			} else l = mid + 1;
		}		
		ans = max(ans, i - l + 1);
	}
	
	cout << ans;
	
	cout.flush();
	return 0;
}
/*
5 8
-3 -1 2 2 7

5 5
1 2 4 8 9

*/
