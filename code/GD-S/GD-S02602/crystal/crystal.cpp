#include<bits/stdc++.h>
#define ll long long
using namespace std;

// crystal
const int N = 5e5 + 10;
ll a[N], sum[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ll n, m; cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i ++){
		sum[i] = sum[i - 1] + a[i];
	}
	ll ans = 1;
	for(ll i = 2; i <= n; i ++){
		ll l = 1, r = i - 1, mid, an = 1;
		while(l <= r){
			mid = (l + r) / 2;
			if(a[i] * (i - mid) - (sum[i - 1] - sum[mid - 1]) <= m){
				an = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		if(a[i] * (i - an) - (sum[i - 1] - sum[an - 1]) <= m){
			ans = max(ans, i - an + 1);
		}
	}
	cout << ans;
	
	return 0;
} 
