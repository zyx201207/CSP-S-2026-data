#include <bits/stdc++.h>
#define LL long long
using namespace std;

LL n, m, ans = 0, a[200005], vis[200005];

int main() {
	
//	freopen("1.in", "r", stdin);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout); 

	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	
	for (int j = 30; j >= 0; j --) {
		LL cnt = 0;
		for (int i = 1; i <= n; i ++) {
			if (!vis[i] && a[i] & (1 << j)) cnt ++;
		}
		if (cnt == 0)
			continue;
		if (cnt >= m) {
			for (int i = 1; i <= n; i ++) {
				if (!(a[i] & (1 << j))) 
					vis[i] = 1;
			}
			ans += (1 << j);
		} 
	}
	
	cout << ans << endl;
	
	return 0;
}
