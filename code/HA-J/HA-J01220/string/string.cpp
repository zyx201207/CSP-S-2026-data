#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, a[200001];
char c[200001];
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	int i, j;
	for (i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		
	}
	int ans = 0;
	i = 1;
	j = n;
	while (i <= j) {
		if (c[i] == c[j]) {
			if (a[i] > a[j]){
				a[i] -= a[j--];
			}
			else{
				a[j] -= a[i++];
			}
		}
		else{
			if (a[i] > a[j]){
				ans += a[j];
				j--;
				a[i] -= a[j];
			}
			else{
				ans += a[i];
				i++;
				a[j] -= a[i];
			}
		}
	}
	cout << ans;
	return 0;
}