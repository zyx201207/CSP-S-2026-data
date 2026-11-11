#include<bits/stdc++.h>
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
using namespace std;

int T;
const int N = 5e5+5;
int n, m;
int a[N];

void solve() {
	cin >> n >> m;
	bool f=true;
	int t;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
		if(i == 2){
			t = a[i] - a[i-1];
		}else if(i != 1){
			f = ((a[i]-a[i-1])==t);
		}
	}
	sort(a+1, a+n+1);
	if(f) {
		int ans=1;
		int cnt=0, tt=t;
		while(1){
			cnt += tt;
			tt += t;
			if(cnt > m){
				break;
			}
			ans++;
		}
		cout << ans << endl;
	} else {
		vector<int> c(n+1);
		int ans=0;
		for(int i=n; i>1; i--) {
			int cnt=0;
			for(int j=1; j<=n; j++) {
				if(j <= i) {
					c[j] = a[i] - a[j];
				} else {
					c[j] = a[j];
				}
			}
			int mt = m;
			for(int j=i; j>=1; j--) {
				if(c[j] <= mt) {
					mt -= c[j];
					cnt++;
				} else {
					break;
				}
			}
			ans = max(ans, cnt);
		}
		cout << ans << endl;
	}
	return;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	IOS;
	T = 1;
//	cin >> T;
	while(T--) {
		solve();
	}
	return 0;
}
