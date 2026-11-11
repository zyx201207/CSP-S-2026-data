#include <bits/stdc++.h>
using namespace std;
int a[200005];
char b[200005], dq;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int i = 1, n, xyg = 0;
	string zfc = "";
	long long xb = 1, s = 0;
	cin >> n;
	for (int ii = 1;ii <= n;ii++) {
		cin >> a[ii] >> b[ii];
		for (int j = 0;j < a[ii];j++) zfc += b[ii];
	}
	for (int i = 0;i < zfc.size() / 2;i++) {
//		if (zfc.size() % 2 == 1 && i == zfc.size() / 2) {
//			break;
//		}
		if (zfc[i] != zfc[zfc.size() - i - 1]) {
//			cout << zfc[i] << " ";
			xyg++;
		}
	}
	cout << xyg << zfc;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
