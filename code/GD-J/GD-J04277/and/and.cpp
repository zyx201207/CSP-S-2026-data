#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n, m;
	cin >> n >> m;
	long long a[100086];
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n);
	long long ans = a[n - m + 1];
	for(int i = n - m + 1; i <= n; i++) {
		ans &= a[i];
	} 
	cout << ans;
	return 0;
} 
