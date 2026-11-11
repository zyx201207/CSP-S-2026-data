#include<bits/stdc++.h>
#define ll long long
#define pii pair<string, bool>
#define fi first
#define se second
using namespace std;
ll n, m, a[200005], ans = 0;
vector<pii> v;
void sl(ll x){
	ll c[35];
	ll k = 0;
	while(x > 0){
		k++;
		c[k] = x % 2;
		x /= 2;
	}
	string s = "";
	for(ll i = 1;i <= 31 - k;i++){
		s += '0';
	}
	for(ll i = k;i >= 1;i--){
		s += c[i] + '0';
	}
	v.push_back({s, 1});
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		sl(a[i]);
	}
	for(int i = 0;i < 31;i++){
		ll cnt = 0;
		ans *= 2;
		for(int j = 0;j < v.size();j++){
			if(v[j].fi[i] == '1' && v[j].se){
				cnt++;
			}
		}
		if(cnt >= m){
			ans += 1;
			for(int j = 0;j < v.size();j++){
				if(v[j].fi[i] != '1'){
					v[j].se = 0;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
