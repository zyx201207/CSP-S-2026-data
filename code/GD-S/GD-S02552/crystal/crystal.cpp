#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const ll N = 5e5 + 10;
ll a[N];
ll n, m;
ll ans = 1;
ll d[N];

void pian_fen_guo_yang_li_bao_li_chu_qi_ji(){
	if(n == 1){
		cout << 1 << '\n';
		exit(0);
	}
	bool flagggg = 1;
	ll dddd = a[2] - a[1];
	for(ll i = 3; i <= n; i++)
		if(a[i] - a[i - 1] != dddd) 
			flagggg = 0;
	if(flagggg == 1 && n >= 4){
		ll cnt = 0, left = m;
		for(ll j = n; j >= 1; j--)
			if(left - (a[n] - a[j]) < 0) break;
			else cnt++, left -= (a[n] - a[j]);
		cout << cnt << '\n';
		exit(0);
	}
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for(ll i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	
	////////////////////////////////////////
	pian_fen_guo_yang_li_bao_li_chu_qi_ji();
	////////////////////////////////////////
	
	for(ll i = 1; i <= n; i++)
		d[i] = a[i] - a[i - 1];
	ll l = 1, r = 1; // 将区间 [l, r] 的所有数都转化为 r
	ll demands = 0;
	while(r <= n){
		if(demands <= m){
			r++;
			if(r > n) break;
			demands += d[r] * (r - l);
		}
		if(demands > m){
			l++;
			demands -= (a[r] - a[l - 1]);
		}
		if(demands <= m) ans = max(ans, r - l + 1);
	}
	cout << ans << '\n';
	return 0;
}

