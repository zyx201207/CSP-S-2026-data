#include <bits/stdc++.h>
using namespace std;

long long n, m;
const int N = 2e5 + 5;
long long a[N];

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin >> n >> m;
	for(long long i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n, greater<long long>());
	
	long long ans = a[0];
	for(long long i = 1; i < m; i++) {
		ans &= a[i];
	}
	cout << ans;
	return 0;
} 
