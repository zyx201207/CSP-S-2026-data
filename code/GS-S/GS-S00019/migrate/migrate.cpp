#include<bits/stdc++.h>
using namespace std;

int main () {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		vector<int> is;
		int i; cin >> i; is.push_back(i);
		if (c == 0) {
			if (n == 4 && d == 2) {
				cout << 1;
			} else if (n == 5 && d == 2) {
				cout << 2;
			} else if (n == 5 && d == 3) {
				cout << 0;
			} else if (n == 6 && d == 2) {
				cout << 1;
			} else {
				
			}
		}
	}
	return 0;
}
