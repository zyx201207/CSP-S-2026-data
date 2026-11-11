#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6+5;
int c, T, n, d;
int x[N], pre[N], nxt[N], f1[N], f2[N], s2[N], f3[N], s3[N];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	
	cin >> c >> T;
	while (T--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> x[i];
		int cur = 1;
		for (int i = 2; i <= n; i++) {
			while (x[i]-x[cur] > d) cur++;
			pre[i] = cur;
		}
		int cur = n;
		for (int i = n-1; i >= 1; i--) {
			while (x[cur]-x[i] > d) cur--;
			nxt[i] = cur;
		}
		f1[1] = 0;
		for (int i = 2; i <= n; i++) {
			int x1 = x[pre[i]+1], x2 = x[pre[i]+2];
			if (x2 > x[i]) continue;
			int num1 = x1-d, num2 = x2-d;
			int cur1 = lower_bound(x+1, x+n+1, num1)-x, cur2 = lower_bound(x+1, x+n+1, num2)-x;
			cur2--;
			f1[i] = (cur2-cur1+1);
		}
		f2[0] = s2[0] = 0;
		for (int i = 2; i <= n; i++) {
			int x1 = x[pre[i]], x2 = x[pre[i]+1];
			if (x2 > x[i]) continue;
			int num1 = x1-d, num2 = x2-d;
			int cur1 = lower_bound(x+1, x+n+1, num1)-x, cur2 = lower_bound(x+1, x+n+1, num2)-x;
			cur2--;
			f2[i] = s2[cur2]-s2[cur1-1]+(cur2-cur1+1);
			s2[i] = s2[i-1]+f2[i];
		}
		f3[n] = f3[n] = 0;
		for (int i = n-1; i >= 1; i--) {
			int x1 = x[nxt[i]], x2 = x[nxt[i]-1];
			if (x2 < x[i]) continue;
			int num1 = x1-d, num2 = x2-d;
			int cur1 = upper_bound(x+1, x+n+1, num1)-x-1, cur2 = upper_bound(x+1, x+n+1, num2)-x;
			f3[i] = s3[cur2]-s3[cur1+1]+(cur1-cur2+1);
			s3[i] = s3[i+1]+f3[i];
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) ans += f1[i];
		for (int )
		cout << ans << '\n';
	}	
	return 0;
}
