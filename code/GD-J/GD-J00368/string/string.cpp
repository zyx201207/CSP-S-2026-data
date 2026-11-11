#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, len = 0;
vector<pair<ll, char>> v;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for (ll i = 0;i < n;i++){
		ll a;
		char s_sub;
		cin>>a>>s_sub;
		len += a;
		v.push_back({a, s_sub});
	}
	
	ll ans = 0, l = 0, r = n - 1, l_limit = v[0].first, r_limit = v[n - 1].first;
	for (int i = 0;i < (len / 2);i++){
		if (v[l].second != v[r].second){
			ans++;
		}	
		l_limit--;
		r_limit--;
		if (l_limit == 0){
			l++;
			l_limit = v[l].first;
		}
		if (r_limit == 0){
			r--;
			r_limit = v[r].first;
		}
	}
	
	cout<<ans;

	return 0;
} 
