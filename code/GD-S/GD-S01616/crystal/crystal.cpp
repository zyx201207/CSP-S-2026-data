#include<bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 5;
long long n , m , a[N] , cnt = -1e15 , ans = 1e15 + 5;
int main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		cnt = max(cnt , a[i]);
	}
	sort(a + 1 , a + n + 1);
	for(; cnt >= 1; cnt--){
		long long cost = 0 , i;
		for(i = 1; i <= n; i++){
			if(a[i] > cnt) break;
			else cost += cnt - a[i];
		}
		if(cost <= m){
			cout << i - 1;
			return 0;
		}
		ans = min(ans , cost);
	}
	cout << ans;
	return 0;
}
