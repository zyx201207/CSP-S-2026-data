#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, a[500500], ans;

signed main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	
	bool AB = true;
	int k = a[2] - a[1];
	for(int i = 3; i <= n; i++)
		if(a[i] - a[i - 1] != k)
			AB = false;
	
	if(AB == true) {
		ans = 1;
		int t = k;
		while(m - t > 0)
		{
			m -= t;
			t += k;
			ans++;
		}
		cout << ans << '\n';
		
		return 0;
	}
	
	for(int i = 1; i <= n; i++) {
		int j = i, tm = m, cnt = 1;
		// cout << "i: " << i << "; a[i]: " << a[i] << '\n';
		while(j >= 1) {
			j--;
			int d = a[i] - a[j];
			if(tm - d < 0) break;
			// cout << "j: " << j << "; a[i]: " << a[i] << "; a[j]: " << a[j] << "; tm: " << tm << "; d: " << d << "\n";
			tm -= d;
			cnt ++;
			// cout << "tm: " << tm << "; cnt: " << cnt << "\n";
		}
		ans = max(ans, cnt);
		// cout << "ans: " << ans << "\n\n";
	}
	cout << ans << '\n';
	
	return 0;
}
