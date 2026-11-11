#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 2e6 + 10;

int n, d;
ll pl[N];

ll dis(int i, int j) {
	return abs(pl[i] - pl[j]);
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int c, T;
	cin >> c >> T;
	while (T--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> pl[i];
		
		ll ans = 0;
		for (int i = 1; i <= n; i++) 
			for (int j = i + 2; j <= n; j++) {
				ll sum = ceil(1.0 * abs(pl[i] - pl[j]) / d);
				int num = j - i + 1;
				
				if (abs(pl[i] - pl[j]) % d == 0) continue;
//				cout << i << " " << j <<endl;
				ans += (1 << (sum - 2));
			}
			
		cout << ans << '\n';
	}

	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
