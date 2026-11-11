#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5 + 5;

ll n, m, sum[N], a[N], ans;

bool check(ll x, ll t){
	ll nd = (t - x + 1) * a[t];
	ll ls = sum[t] - sum[x - 1];
	if(nd - ls > m) return 0;
	ans = max(t - x + 1, ans);
	return 1;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0); 
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1 ; i <= n ; i ++){
		sum[i] = sum[i - 1] + a[i];
	}
	for(int i = 1 ; i <= n ; i ++){
		ll l = 1, r = i;
		while(l <= r){
			ll mid = (l + r) / 2;
			if(check(mid, i)){
				r = mid - 1;
			}
			else{
				l = mid + 1;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
//窗外的天气 
