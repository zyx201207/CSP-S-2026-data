#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m;
vector<ll> a;
const int N = 5e5 + 10;
ll pre[N];
bool cmp(ll a, ll b){
	if(a != b) return a < b;
	return 0;
}
bool check(ll x){
	ll mx = 1e18;
	for(int i = 0; i + x - 1 < n; i++){
		int j = i + x - 1;
		ll cnt = -1;
		ll nu = 1LL * x * (1LL * a[n - 1] - a[j]);
		if(i != 0){
			cnt = pre[j] - pre[i - 1] - nu;
		}else{
			cnt = pre[j] - nu;
		}
		if(cnt < mx){
			mx = cnt;
		}
	}
	return mx <= m;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll ans = -1;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		ll x;
		cin >> x;
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	ll an = a[n - 1];
	for(int i = 0; i < n; i++){
		if(i == 0){
			pre[i] = an - a[0];
			continue;
		}else{
			pre[i] = pre[i - 1] + (an - a[i]);
		}
	}
	ll l = 1, r = n;
	while(l <= r){
		ll mid = (l + r) >> 1;
		if(check(mid)){
			l = mid + 1;
			ans = mid;
		}else{
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
}
