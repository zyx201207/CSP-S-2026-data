#include <bits/stdc++.h>
using namespace std;
string rx, ry, xx, xy;
int a[6] = {1, 1, 1, 2, 3, 3};
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> rx >> ry >> xx >> xy;
	if (rx == xx) {
		cout << 1;
		if (ry[0] == xy[0] && ry[1] == xy[1]) {
			cout << 1;
			if (a[ry[2] - 'A'] == a[xy[2] - 'A']) {
				cout << 1;
				if (abs(ry[2] - xy[2]) == 1) {
					cout << 1;
				} else {
					cout << 0;
				}
			} else {
				cout << 0;
				cout << 0;
			}
		} else {
			cout << 0;
			cout << 0;
			cout << 0;
		}
	} else {
		cout << 0;
		cout << 0;
		cout << 0;
		cout << 0;
	}
	return 0;
}
