#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, ans;
string txt;
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int st = 0;
	for (int i = 1; i <= n; i++) {
		int num;
		char ch;
		cin >> num >> ch;
		for (int j = 1; j <= num; j++)
			txt = txt + ch;
	}
	int n = txt.length();
	for (int i = 1; i <= (n + 1) / 2; i++)
		if (txt[i] != txt[n - i + 1])
			ans++;
	cout << ans;
	return 0;
}

