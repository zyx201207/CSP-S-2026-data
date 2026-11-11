#include <bits/stdc++.h>
using namespace std;
string a[4];
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> a[0] >> a[1] >> a[2] >> a[3];
	if (a[0] == a[2])
		cout << 1;
	else {
		cout << "0000";
		return 0;
	}
	string k1, k2;
	k1 += a[1][0], k1 += a[1][1];
	k2 += a[3][0], k2 += a[3][1];
	if (k1 == k2)
		cout << 1;
	else
		cout << 0;
	bool flag = true;
	if (k1 != k2)
		cout << 0;
	else if (((a[1][2] == 'D' || a[1][2] == 'F') && (a[3][2] == 'D' || a[3][2] == 'F')) || ((a[1][2] >= 'A' && a[1][2] <= 'C') && (a[3][2] >= 'A' && a[3][2] <= 'C'))) {
		cout << 1;
		flag = false;
	}
	else
		cout << 0;
	if (flag == true || k1 != k2)
		cout << 0;
	else {
		if (abs((int)a[1][2] - (int)a[3][2]) == 1)
			cout << 1;
		else
			cout << 0;
	}
	return 0;
}
