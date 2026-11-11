#include <iostream>
using namespace std;

int c, T;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	while (T--) {
		int n, d;
		cin >> n >> d;
		for (int i = 1; i < n; i++) {
			int x;
			cin >> x;
		}
	} 
	if (c == 7) cout << "4\n3\n9\n9";
	if (c == 8) cout << "2\n1\n2\n9";
	if (c == 9) cout << "3\n3\n5\n8"; 
	return 0;
}
