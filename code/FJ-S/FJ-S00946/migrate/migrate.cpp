#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=2e6+10;
int a[N];
int n,d;

void solve() {
	int ans=0;
	for (int i=1;i<=n;i++) {
		if (a[i]-a[1]>d) {
			ans=i-2;
			break;
		}
	}	
	if (a[2]-a[1]>=d||d>=a[n]-a[1]) {
		cout << 0 << '\n'; 
		return ;	
	}
	int cnt=0;
	for (int i=2*ans+1;i<=n;i+=ans) {
		cnt++;
	}
	cout << cnt*(cnt-1)-(2+cnt)*(cnt-2)/2 << '\n';
	return ;
}

signed main() {
	freopen("migrate4.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	
	int c,t;
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i=1;i<=n;i++) cin >> a[i];
		solve();
	}	
	return 0;
}
