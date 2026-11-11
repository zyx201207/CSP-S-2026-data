#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
#define int long long
int a[N] , n , m; 
signed main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i ++) cin >> a[i];
	sort(a + 1 , a + 1 + n);
	//for (int i = 1 ; i <= n ; i ++) cout << a[i] << " ";
	int lr = 0 , sum = 0 , ans = 0;
	for (int l = 1 , r = 1 ; r <= n && l <= r ; r ++) {
		sum += (r - l) * (a[r] - a[r - 1]);
		//cout << l << ' ' << r << " " << sum << "\n";
		while (sum > m) {
			sum -= a[r] - a[l];
			l ++;
		}
		ans = max(ans , r - l + 1);
	}
	cout << ans;
	
} 
/*
11 5
1 2 3 4 5 6 6 7 7 7 7
*/
