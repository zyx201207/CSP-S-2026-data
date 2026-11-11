//GZ-J00259  白鹭湖小学 陈彦宇
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int a[N];
char c[N];

int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
	int n, sum = 0;
	cin >> n;
	string s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		for (int j = 1; j <= a[i]; j++) {
			s += c[i];
		}
		sum += a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (n == 2 && c[i] == c[i - 1]) {
			cout << 0;
			return 0;
		}
	}
	int ans = sum / 2;
	cout << ans;
    fclose(stdin);
    fclose(stdout);
	return 0;
}

