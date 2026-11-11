#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5 + 10;

ll n, m, a[N], ans, op[N];
int main() {
	freopen("and.in","r",stdin);
	freopen("and,out","w",stdout);
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	sort(a + 1, a + n + 1, greater<>());
	cout << a[m];
	//for (int i = 1; i <= n; i++) {
		//for (int j = 1; j <= m; j++) {
			//ans = max(ans, a[j])
		//}
	//}
	return 0;
} 
