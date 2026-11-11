#include<bits/stdc++.h>
using namespace std;

int n, m, mx;
long long ans;
int a[200010];
bool s[200010][35];
int b[200010];
long long f[35];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	long long z = 1;
	for(int i = 0; i <= 31; i++) {
		f[i] = z;
		z *= 2;
	}
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		long long x;
		cin >> x;
		int j = 0;
		while(x) {
			if(x & 1) {
				s[i][j] = 1;
			}
			else {
				s[i][j] = 0;
			}
			x >>= 1;
			j++;
			mx = max(mx, j);
		}
	}
	for(int k = mx; k >= 0; k--) {
		int cnt = 0;
		for(int i = 1; i <= n; i++) {
			if(!b[i] && s[i][k])cnt++;
		}
		if(cnt < m)continue;
		ans += f[k];
		for(int i = 1; i <= n; i++) {
			if(!s[i][k]) {
				b[i] = 1;
				continue;
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}
