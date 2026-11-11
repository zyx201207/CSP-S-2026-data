#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;
const ll N = 2e6 + 10;

ll x[N];
ll n, d;
ll c, t;

void pian_fen_guo_yang_li_bao_li_chu_qi_ji(){
	bool flagggg = 1;
	ll dddd = x[2] - x[1];
	for(ll i = 3; i <= n; i++)
		if(dddd != x[i] - x[i - 1])
			flagggg = 0;
	if(!flagggg) {
		cout << 0 << '\n'; 
		return ;
	}
	if(n >= floor(d * 1.0 / dddd) * 2 && floor(d * 1.0 / dddd) >= 2) cout << n - (floor(d * 1.0 / dddd) * 2) + 1 << '\n';
	else cout << 0 << '\n';
	return ;
}

void solve(){
	cin >> n >> d;
	for(ll i = 1; i <= n; i++)
		cin >> x[i];
	////////////////////////////////////////
	pian_fen_guo_yang_li_bao_li_chu_qi_ji();
	////////////////////////////////////////
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while(t--){
		solve();
	}
	return 0;
} 
