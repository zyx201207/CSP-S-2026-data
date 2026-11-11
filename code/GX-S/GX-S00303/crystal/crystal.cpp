#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5+5;
ll n , m;
ll a[N] , s[N];
int main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; ++i){
		cin >> a[i];
	}
	sort(a + 1 , a + n + 1);
	for(int i = 1 ; i <= n ; ++i)
		s[i] = s[i - 1] + a[i];
	ll ans = 0 , d = 0;
	for(int i = 1 ; i <= n ; ++i){
		ll p = (i - d) * a[i];
		if(p - (s[i] - s[d]) <= m){
			ans = i - d;
		}else{
			d++;
			if(p - (s[i] - s[d]) <= m)
				ans = i - d;
		}
	}
	cout << ans << '\n';
	return 0;
}
