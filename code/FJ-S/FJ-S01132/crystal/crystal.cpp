#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 5e5 + 3;
int a[MAXN];
int n, m;
bool check() {
	int d = a[2] - a[1];
	for(int i = 1; i <= n; i++) if(a[i] != (a[i - 1] + d)) return false;
	return true;
}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	if (check()) {
		for (int i = n; i >= 1; i--) {
			int t = (a[i] - a[1]) * i / 2;
			if(t <= m){
				cout << i << endl;
				return 0;
			}
		} 
	}
	int ans = 0;
	for (int j = 1; j <= n; j++){
		int s = m, cnt = 1;
		for (int i = j - 1; i >= 1; i--) {
			if (s >= (a[j] - a[i])) {
				s -= (a[j] - a[i]);
				cnt++;
			} else {
				s = s - a[j] + a[i];
				break;
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}
