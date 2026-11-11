#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 2e6 + 5;
int n;
ll d;
ll x[N];

inline int num(ll l, ll r){
	int L = lower_bound(x + 1, x + n + 1, l) - x;
	int R = upper_bound(x + 1, x + n + 1, r) - x - 1;
	int cnt = R - L + 1;
	if(cnt < 0) return 0;
	else return cnt;
}

inline void spj(){
	cin >> n >> d;
	for(int i = 1;i <= n;i ++){
		cin >> x[i];
	}
	ll ans = 0;
	for(int i = 3;i <= n;i ++){
		ll x_1 = x[i - 2], x_2 = x[i - 1], x_3 = x[i];
		ll num1 = num(x_2 - d, x_3 - d - 1);
		ll num2 = num(x_2 + 1, x_1 + d);
		if(num(x_2 - d, x_1 - 1) == 1) ans += 1ll * num1 * num2;
	}
	cout << ans << '\n';
}

inline void solve(){
	cin >> n >> d;
	for(int i = 1;i <= n;i ++){
		cin >> x[i];
	}
	ll len = 1ll * d * 2;
	ll ans = n - len + 1;
	if(ans < 0) ans = 0;
	cout << ans << '\n';
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(0) -> ios::sync_with_stdio(0);
	int c, T = 1;
	cin >> c >> T;
	if(11 <= c && c <= 12) while(T --)	solve();
	else while(T --) spj();
	return 0;
}
