#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long a[200005];
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	long long ans;
	sort(a,a + n + 1);
	ans = a[n];
	for (int i = m - 1;i > 0;i--) {
		ans &= a[n - i];
	}
	cout << ans << endl;
	return 0;
} 

