#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10; 
ll n, m, a[N];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	if(n <= 5000){
		for(int i = 1; i <= n; i ++){
			cin >> a[i];
		}
		sort(a + 1, a + 1 + n);
		ll ans = 1;
		for(int i = 1; i <= n; i ++){
			ll tmp = m, cnt = 1;
			for(int j = i - 1; j >= 1; j --){
				if(a[i] - a[j] <= tmp){
					tmp = tmp - (a[i] - a[j]);
					cnt += 1;
				}
			}
			ans = max(ans, cnt);
		}
		cout << ans;
		return 0;
	}
	else{
		bool b = 1;
		for(int i = 1; i <= n; i ++){
			cin >>a[i];
			if(i == 1 || i == 2 || b == 0) continue;
			if(a[i] - a[i - 1] == a[i-1] - a[i]) b = 0;
		}
		sort(a + 1, a + 1 + n);
		for(int i = 3; i <= n; i ++){
			if(a[i] - a[i - 1] == a[i - 1] - a[i]){
				b = 0;
				break;
			}
		}
		if(b){
			ll cha = (a[2] - a[1]);
			m = m / cha;
			ll ans = 1;
			while(m - ans >= 0){
				m = m - ans; 
				ans ++;
			}
			cout << ans;
			return 0;
		}
		ll ans = 1;
		for(int i = 1; i <= n; i ++){
			ll tmp = m, cnt = 1;
			for(int j = i - 1; j >= 1; j --){
				if(a[i] - a[j] <= tmp){
					tmp = tmp - (a[i] - a[j]);
					cnt += 1;
				}
			}
			ans = max(ans, cnt);
		}
		cout << ans;
	}
	return 0;
}
