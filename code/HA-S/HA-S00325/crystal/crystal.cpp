#include <bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x;
	cin >> x;
	return x;
}
const int N = 500005;
int n, m, ans, a[N], s[N];
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	n = read(), m = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	for(int i = 1; i <= n; i++){
		// ¿¼ÂÇÑ¡ÔñÄã¡£
		int l = 1, r = i;
		while(l < r){
			int mid = (l + r) >> 1;
			if((i - mid + 1) * a[i] - (s[i] - s[mid - 1]) > m) l = mid + 1;
			else r = mid;
		}
		ans = max(ans, i - l + 1);
	}
	cout << ans << '\n';
	return 0;
}
