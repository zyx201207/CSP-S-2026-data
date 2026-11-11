//GZ-S00272  贵阳市第三实验中学  闫张玴 
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+10;
int n, m, a[N], b[N], dp[N], s[N];
int rp, ans;
int c, cnt=1, cha; 
bool f = true;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}
	cha = a[2] - a[1];
	for(int i=3; i<=n; i++) {
		int cmp = cha;
		cha = a[i] - a[i-1];
		if(cha != cmp) {
			f = false;
			break;
		}
	}
	if(f) {
		while(cnt*cha <= m) {
			m-=cnt*cha;
			cnt++;
		}
		cout << cnt;
		return 0;
	}
	sort(a+1, a+1+n);
	for(int i=1; i<=n; i++) {
		b[i] = a[i] - a[i-1];
		s[i] = s[i-1] + b[i];
	}
	b[1] = 0;
	for(int i=2; i<=n; i++) {
		rp = LONG_LONG_MAX;
		for(int j=1; j<i; j++) dp[j] = 0;
		for(int j=i; j<=n; j++) {
			dp[j] = dp[j] + s[j] - s[j-i+1];
			rp = min(rp, dp[j]);
		}
		if(rp <= m) ans = i;
		else break;
	} 
	cout << ans;
	
	return 0;
}
