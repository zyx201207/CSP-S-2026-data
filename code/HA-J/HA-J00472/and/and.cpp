#include<bits/stdc++.h>
using namespace std;

int n, m, a[200005][35], mx, ans, maxx;
vector<int> v;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout); 
	
	cin>>n>>m;
	for(int i = 1; i <= n; i++) {
		cin>>a[i][33];
		maxx = max(maxx, a[i][33]);
		int x = a[i][33], cnt = 0;
		while(x) {
			a[i][cnt] = x & 1;
			x >>= 1;
			cnt++;
		}
		mx = max(mx, cnt);
	}
	if(m == 1) {
		cout<<maxx;
		return 0;
	}
	if(m == n) {
		ans = a[1][33];
		for(int i = 2; i <= n; i++) {
			ans &= a[i][33];
		}
		cout<<ans;
		return 0;
	}
	if(n <= 2000 && m == 2) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(i != j) {
					ans = max(ans, a[i][33] & a[j][33]);
				} 
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i = mx; i >= 0; i--) {
		if(v.size() >= m) {
			break;
		}
		for(int j = 1; j <= n; j++) {
			if(a[j][i] && a[j][33]) {
				v.push_back(a[j][33]);
				a[j][33] = 0;
			}
		}
	}
	if(v.size() < m) {
		cout<<"0\n";
		return 0;
	}
	ans = v[0];
	for(int i = 1; i < m; i++) {
		ans &= v[i];
	}
	cout<<ans<<"\n";
	
	return 0;
}
