#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll f = 1;ll x = 0;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = x * 10 + (c ^ 48);
		c = getchar();
	}
	return f * x;
}
const ll N = 2e6 + 10;
ll c, t, n;
ll d, x[N], s[N];
ll l, r, cnt[N];
pair<ll, ll> q[N];
void solve1(){
	ll ans = 0;
	for(int i = 1;i <= n - 2;++ i){
		l = 1, r = 1;q[r] = {i, 0}, cnt[0] = 1, s[i] = 1;
		for(int j = 1;j <= n;++ j) cnt[j] = 0;
		for(int j = i + 1;j <= n;j ++) s[j] = 0;
		for(int j = i + 1;j <= n;++ j){
			while(r >= l && x[j] - x[q[l].first] > d) cnt[q[l].second] --, l ++;
			if(r < l) break;
			if(s[l + cnt[q[l].second] - 1] - s[l - 1] == 2) ans ++;
			ll tmp = q[l].second + 1;
			q[++ r] = {j, tmp};
			cnt[tmp] ++, s[r] = s[r - 1] + s[l + cnt[q[l].second] - 1] - s[l - 1];
		}
	}
	printf("%lld\n", ans);
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t --){
		cin >> n;d = read();
		for(int i = 1;i <= n;++ i) x[i] = read();
		if(n <= 5000) solve1();//O(N^2) 40pts
		else puts("0");
	}
	return 0;
}
