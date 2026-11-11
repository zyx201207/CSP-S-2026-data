#include <bits/stdc++.h>
using namespace std;
int n, m, a[200006], mi[36], num[36], maxmi = 0, s, p[36];
bool t[200006][36];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1;i <= n;i++)
		scanf("%d", &a[i]);
	mi[1] = 1;
	for (int i = 2;i <= 31;i++)
		mi[i] = mi[i - 1] * 2;
	for (int i = 1;i <= n;i++)
		for (int j = 30;j >= 1;j--) {
			if (a[i] >= mi[j])
				a[i] -= mi[j], t[i][j] = true, num[j]++;
			else
				t[i][j] = false;
		}
	for (int i = 30;i >= 1;i--) {
		if (num[i] >= m) {
			maxmi = i, s = mi[maxmi];
			//cout << mi[maxmi] << endl;
			break;
		}
	}
	if (maxmi == 0) {
		cout << "0" << endl;
		return 0;
	}
	int q = 0;
	for (int i = maxmi - 1;i >= 1;i--) {
		q = 0;
		for (int j = 1;j <= n;j++)
			if (t[j][maxmi] == true && t[j][i] == true) {
				q++;
			}
		if (q >= m) {
			s += mi[i];
		}
	}
	cout << s;
}
