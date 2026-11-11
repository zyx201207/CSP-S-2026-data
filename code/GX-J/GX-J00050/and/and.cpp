#include<bits/stdc++.h>
using namespace std;
long long n, m, a[500001], ans;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(long long i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n - m; i++)
		for(int j = i + 1; j <= n; j++)
			ans = max(ans, a[i] & a[j]);
	cout << ans;
	return 0;
}
