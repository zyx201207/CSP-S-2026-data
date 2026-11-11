#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 10;

ll n, m, a[N], sum[N];
bool check(ll x){
	for(int l = 1;l <= n - x + 1;l++){
		int r = l + x - 1;
		ll num = a[r] * x - (sum[r] - sum[l - 1]);
		if(num <= m) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for(int i = 1;i <= n;i++) sum[i] = sum[i - 1] + a[i];
	ll l = 1, r = n, ans = 0;
	while(l <= r){
		ll mid = (l + r) >> 1;
		if(check(mid)){
			ans = mid;
			l = mid + 1;
		} else {
		 	r = mid - 1;
		}
	}
	cout << ans << '\n';
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
