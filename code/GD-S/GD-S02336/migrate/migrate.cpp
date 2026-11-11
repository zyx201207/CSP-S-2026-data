#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2000010;

int x[N];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int t;
	
	cin >> t >> t;
	
	while (t--) {
		int n, d, ans = 0;
		
		cin >> n >> d;
		
		for (int i = 1; i <= n; ++i) {
			cin >> x[i];
		}
		
		cout << ans << '\n';
	}
	
	return 0;
} 
