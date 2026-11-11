#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n, m, maxx = 0, ans;
	cin >> n >> m;
	vector<int> a(n + 1, 0);
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		maxx = max(maxx, a[i]);
	}
	ans = a[1];
	if(m == 1) {
		cout << maxx;
		return 0;
	}
	if(m == n) {
		for(int i = 2; i <= n; ++i) {
			ans = (ans & a[i]);
		}
		cout << ans;
		return 0;
	}
	if(m == 2) {
		ans = 0;
		maxx = 0;
		for(int i = 1; i <= n; ++i) {
			for(int j = i + 1; j <= n; ++j) {
				int ans = (a[i] & a[j]);
				maxx = max(maxx, ans);
			}
		}
		cout << maxx;
		return 0;
	}
	if(m == n - 1) {
		int k = 1;
		int maxx = 0;
		do{
			int ans = a[k + 1];
			for(int i = 1; i <= n; ++i) {
				if(i == k || i == k + 1) continue;
				ans = (ans & a[i]);
			}
			maxx = max(maxx, ans);
			k++;
		}while(k < n);
		cout << maxx;
		return 0;
	}
	sort(a.begin() + 1, a.end(), greater<int>());
	ans = a[1];
	for(int i = 2; i <= m; ++i) {
		ans = (ans & a[i]);
	}
	cout << ans;
	return 0;
}
