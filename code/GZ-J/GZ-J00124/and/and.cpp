// 遵义市第四中学 杨浩辰 GZ-J00124
#include<iostream>
#include<string>
#include<vector>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
ll a[N], dp[25][25], mx, sum, m, n, b[N], bi, dp2[N];
int lowbit(ll x) {
	return (x&-x);
}
int check() {
	for (int i = 1; i <= n; i++) {
		while(b[i]) {
			if (!lowbit(b[i])) return 0;
			b[i]>>1;
		}
	}
	return 1;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	ll f = 1, cs = n;
	while(cs) {
		if (!lowbit(cs)) f=0;
		cs-=lowbit(cs);
		cs>>1;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
		if (a[i] > mx) bi = i;
		if (i == 1) sum = a[i];
		else sum&=a[i];
		if (a[i]!=i-1) f=0;
	}
	if (m == 1) {
		cout << mx;
	} else if (n <= 20) {
		for (int i = 1; i <= n; i++) {
			dp[i][1] = a[i];
		}
		for (int j = 1; j <= m; j++) {
			for (int i = j; i <= n; i++) {
				for(int k = 1; k <= i; k++) {
					dp[i][j]=max(dp[i][j],dp[i-k][j-1]&a[i]);
				}
			}
		}
		cout << dp[n][m];
	} else if (n == m) {
		cout << sum;
	} else if (m == 2) {
		ll ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j < i; j++) {
				ans = max(ans,(ll)a[i]&a[j]);
			}
		}
		cout << ans;	
	} else if (m == n-1) {
		ll ans = 0;
		for (int i = 1; i <= n; i++) {
			ans = max(ans,ll(sum|a[i]));
		}
	} else if (mx < 4) {
		ll t[4]={0,0,0,0};
		for (int i = 1; i <= n; i++) {
			t[a[i]]++;
		}
		if (t[3]>=2) cout << 3;
		else if (t[2]>=2) cout << 2;
		else if (t[1]>=2) cout << 1;
		else if (t[3]&&t[1]) cout << 1;
		else cout << 0;
	} else if (check()) {
		ll m2 = 0;
		for (int i = 1; i <= n; i++) {
			if (i!=bi) m2 = max(m2,a[i]);
		}
		cout << (mx&m2);
	} else if (f) {
		cout << (n&(n-1));
	} else {
		for (int i = 1; i <= n; i++) {
			dp2[i] = a[i];
		}
		for (int j = 1; j <= m; j++) {
			for (int i = j; i <= n; i++) {
				for(int k = i; k >= 1; k--) {
					dp2[i]=max(dp2[i],dp2[i-k]&a[i]);
				}
			}
		}
		cout << dp2[n];
	}
	return 0;
}
