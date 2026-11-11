#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int n, m;
int a[N], vis[N], dp[N];
int ans;
bool flag = false;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[i] = a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (m == 0) break;
			if (a[i] == a[j] * 2) {
				flag = true;
				if (a[j] - a[j - 1] >= a[j]) {
					if (a[i] != dp[j]) {
						m -= a[j];
					    a[j] = a[i];
					    dp[i] *= 2;
				    }else {
					    continue;
				    }
				}else {
					m = m - a[j] + a[j - 1];
					a[j - 1] = a[j];
				}
				
			}
		}
	}
	
	if (flag == false) {
		a[1] = a[2];
		m = m - a[2] + a[1];
		while (m) {
			sort(a + 1, a + 1 + n);
			a[1]++;
			m--;
		}
	}
	
	if (flag == true && m != 0) {
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (a[j] == a[i] * 2) {
					if (a[i] - a[i - 1] <= m) {
						a[i - 1] = a[i];
						m = m - a[i] + a[i - 1];
					}
				}
			}
	    }
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (a[j] == a[i]) {
				a[j] = 0;
				a[i] *= 2;
				vis[i] = 1;
				vis[j] = 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 1) {
			ans++;
		}
	}
	cout << ans;
	return 0; 
}
