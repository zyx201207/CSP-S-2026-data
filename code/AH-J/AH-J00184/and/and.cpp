#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn = 1e7 + 5;
ll ans[maxn];
ll ans_2[maxn];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ll n, m;
	cin >> n >> m;
	for(ll i = 1; i <= n; ++i){
		ll a;
		cin >> a;
		ll x = 1;
		while(1){
			if(x == 0)break;
			ans[i] = a%2 * x;
			a %= 2;
			x *= 10;
		}
	}
	int cnt_1 = 0;
	if(m == 2){
		for(ll i = 1; i <= n; ++i){
			int cnt = 0;
			for(ll j = i + 1; j <= n; ++j){
				for(ll x = 1; x <= 20; ++x){
					if(ans[i] == 1 && ans[i] == ans[j]){
						cnt += 1 * pow(10,(20 - x + 1));
					}
					else if(ans[i] != ans[j]){
						cnt+= 0;
					}
				}
			}
			if(cnt > cnt_1) cnt_1 = cnt;
		}
		for(ll i = 1; i <= 20; ++i){
			ll po = pow(10,20 - i);
			ans_2[i] = cnt_1/ po%10;
		}
		int ans_3 = 0;
		for(ll i = 20; i >= 1; --i){
			if(ans_2[i] == 0)continue;
			if(ans_2[i] == 1) ans_3 = ans_2[i] * pow(2,i);
		}
		cout << ans_3;
	}
	return 0;
}
