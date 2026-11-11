#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, ans = 0, maxx = 0;
int a[200050];
int v[5];
void dfs(int i, int yy, int xl) {
	if (xl == m) {
		ans = max(ans, yy);
		return;  
	}
	if (i > n) {
		return;
	}
	if (xl < m&&i<n) dfs(i+1, yy&a[i+1], xl+1);
	dfs(i+1,yy,xl);
}
signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	bool f = true;
	bool f2 = true;
	bool f3 = true;
	for(int i=1;i <= n; ++i) {
		cin >> a[i];
		maxx = max(maxx, a[i]);
		int x = a[i];
		while(f && x){
			if ((x&1)==0){
				f=false;
				break;
			}
			x>>=1;
		}
		if (f2 && a[i]!=i-1){
			f2=false;
		}
		if (f3 && a[i]>=4){
			f3=false;
		}
	}
	if (m == 1) {
		cout << maxx << "\n";
		return 0;
	}
	if (f2) {
		cout << n - m << "\n";
		return 0;
	}
	if (n== m) {
		ans = INT_MAX;
		for (int i=1; i <= n; ++i) {
			ans &= a[i];
		}
		cout << ans << "\n";
		return 0;
	}
	if (f3) {
		for (int i=1; i <= n; ++i) {
			++v[a[i]];
		}
		if (m <= v[3]) {
			cout << 3;
		} else if (m <= (v[2] + v[3])) {
			cout << 2;
		} else if (m <= (v[1] + v[3])) {
			cout << 1;
		} else {
			cout << 0;
		}
		cout << "\n";
		return 0;
	}
	if (f) {
		sort(a+1,a+n+1,greater<int>());
		cout<<a[m]<<"\n";
		return 0;
	}
	for (int i=1;i<=n;++i){
		dfs(i,a[i],1);
	}
	cout<<ans<<"\n";
	return 0;
}
