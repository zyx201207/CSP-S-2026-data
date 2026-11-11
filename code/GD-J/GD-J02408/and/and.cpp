#include <bits/stdc++.h>

using namespace std;

//#define LOCAL

namespace my {
	// Globals

	constexpr int N = 2e5 + 10;
	
	int a[N];
	vector <int> has[40];

	int main() {
		#ifndef LOCAL
			freopen("and.in", "r", stdin);
			freopen("and.out", "w", stdout);
			
			ios::sync_with_stdio(false);
			cin.tie(nullptr); 
		#endif

		int n, m; cin >> n >> m;
		
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		
		sort(a + 1, a + 1 + n, greater <int> ());
		
		int ans = a[1];
		for (int i = 2; i <= m; i++) ans &= a[i];
		
		cout << ans << '\n';
		
		#ifndef LOCAL
			fclose(stdin);
			fclose(stdout);
		#endif

		return 0;
	}
}

int main() {
	my::main();

	return 0;
}

