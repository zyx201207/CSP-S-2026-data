#include <bits/stdc++.h>
using namespace std;

long long c, t;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> t;
	for(int i = 1; i <= t; i++) {
		cout << rand() % 10 << '\n';
	}
	return 0;
}
