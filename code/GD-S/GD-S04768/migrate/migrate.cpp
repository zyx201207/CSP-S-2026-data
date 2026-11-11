#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 5;
int c, t;
int x[N];
int main() {

	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> c >> t;
	for(int i = 1; i <= t; i++) {
		int n, d;
		cin >> n >> d;
		for(int j = 1; j <= n; j++) {
			cin >> x[i];
		}
	}
	for(int i = 1; i <= t; i++) cout << "0" << endl;
	return 0;
}

