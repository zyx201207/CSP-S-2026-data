#include <bits/stdc++.h>
using namespace std;
const int N = 1e1 + 5;
int x, y;
char st[N];
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	for (int i = 1; i <= 10; i++) cin >> st[i];
	if (st[1] == st[6] && st[2] == st[7]) {
		cout << "1";
		if (st[3] == st[8] && st[4] == st[9]) {
			cout << "1";
			x = st[5] - 'A' + 1;
			y = st[10] - 'A' + 1;
			if ((x <= 3 && y <= 3) || (x > 3 && y > 3)) {
				cout << "1";
				if (((x <= 3 && y <= 3) && abs(x - y) == 1) || (x > 3 && y > 3)) cout << "1";
				else cout << "0";
			} else cout << "00";
		} else cout << "000";
	} else cout << "0000";
	return 0;
}
