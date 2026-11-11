#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, ans = 0, l, cs;
struct s{
	ll self, to, zhi;
}a[500005];
bool cmp(s x, s b){
	return x.self <= b.self;
}
int dfs(ll x, ll dt){
	if(dt < 0 || x == n){
		return l;
	}
	l++;
	dt -= cs * a[x].to;
	cs++;
	dfs(x + 1, dt);
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(ll i = 1; i <= n; i++){
		cin >> a[i].self;
		if(a[i].self == i) ans++;
	}
	if(m == 0){
		cout << 0 << "\n";
		return 0;
	}
	sort(a + 1, a + n + 1, cmp);
	for(ll i = 1; i <= n - 1; i++){
		a[i].to = a[i+1].self - a[i].self;
	}
	bool p = true;
	for(ll i = 1; i <= n - 2; i++){
		if(a[i].to != a[i+1].to){
			p = false;
			break;
		}
	}
	if(p == true){
		ll t = 0, k = a[1].to;
		for(ll i = 1; i <= n; i++){
			if(m < 0){
				t = i - 1;
				break;
			}
			m -= i * k;
		}
		if(t == 0){
			cout << n << "\n";
			return 0;
		}
		cout << t << "\n";
		return 0;
	}
	for(ll i = 1; i <= n - 1; i++){
		ll dt = m;
		l = 0, cs = 1;
		a[i].zhi = dfs(i, dt);
	}
	ll sum = a[1].zhi;
	for(ll i = 2; i <= n - 1; i++){
		if(a[i].zhi > sum) sum = a[i].zhi;
	}
	cout << sum << "\n";
	return 0;
}
