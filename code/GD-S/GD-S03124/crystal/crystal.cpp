#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll a[500005];

int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll n, m;
	cin >> n >> m;
	
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	
	sort(a+1,a+n+1,greater<ll>());
	
	ll ans =  LLONG_MIN;
	for (int i = 1;i <= n;i++){
		ll rst = m, cnt = 1;
		for (int j = i+1;j <= n;j++){
			ll d = a[i] - a[j];
			if (rst < d) break;
			rst -= d;
			cnt++;
		}
		ans = max(ans,cnt);
	}
	
	cout << ans << '\n';
	
	return 0;
}
