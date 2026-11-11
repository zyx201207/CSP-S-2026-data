#include<bits/stdc++.h>
using namespace std;

long long n, m, a[200100], is[200100], is2[200010], maxj, ans;
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	for(int j = 30; j >= 0; j --) {
		int cnt = 0;
		for(int i = 1; i <= n; i ++) 
			if(a[i] % (1 << (j + 1)) >= (1 << j)) cnt ++;
		if(cnt >= m) {
			for(int i = 1; i <= n; i ++) 
				if(a[i] % (1 << (j + 1)) >= (1 << j)) is[i] = 1;
			maxj = j; break;
		}
	}	
	for(int j = maxj; j >= 0; j --) {
		int cnt = 0;
		for(int i = 1; i <= n; i ++)
			if(a[i] % (1 << (j + 1)) >= (1 << j) && is[i] == 1) cnt ++;
		if(cnt < m) continue;
		for(int i = 1; i <= n; i ++) 
			if(a[i] % (1 << (j + 1)) < (1 << j)) is[i] = 0; 
		ans += (1 << j);
	}
	cout << ans;
	return 0;
}
