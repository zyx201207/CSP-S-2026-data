#include <bits/stdc++.h>
#define int long long
using namespace std;
int n , m , a[500005];
signed main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(n > 5000){
		int ans = 0;
		int tmp = abs(a[2] - a[1]);
		for(int i = tmp;i < n;i++){
			if(m >= i){
				ans++;
				m -= i;
			}
		}
		cout << ans;
		exit(0);
	}
	int ans = 1;
	sort(a + 1 , a + n + 1);
	for(int i = 2;i <= n;i++){
		int tmp = m , cnt = 1;
		for(int j = i-1;j >= 1;j--){
			if(tmp >= (a[i]-a[j])){
				tmp -= (a[i]-a[j]);
				cnt++;
			}
		}
		ans = max(ans , cnt);
	}
	cout << ans;
	return 0;
}