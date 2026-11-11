#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int N = 5e5 + 1030;
int n , m , a[N];
int ans;

signed main() {
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
	cin >> n >> m; 
	for (int i = 1 ; i <= n ; i++) cin >> a[i];
	sort(a + 1 , a + n + 1 , less<long long>());
	// 特殊性质 :  
	if (n > 5000) {
		int diff = a[2] - a[1];
		int k = 2 * m / diff;
		int h = sqrt(k);
		if ((h + 1) * h <= k) cout << h + 1;
		else cout << h;
		return 0;
	}
	// 正常 :  
	for (int i = 1 ; i <= n ; i++) {
		int cnt = 0 , sum = m;
		for (int j = i ; j >= 1 ; j--) {
			int diff = a[i] - a[j];
			if (sum >= diff) {
				cnt++;
				sum -= diff;
			} else {
				break;
			}
		}
		ans = max(ans , cnt);
	}
	cout << ans;
	return 0;
}

