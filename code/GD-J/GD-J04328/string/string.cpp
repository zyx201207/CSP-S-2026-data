#include <bits/stdc++.h>
using namespace std;

string s;
int n;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		char c;
		cin >> a >> c;
		for (int j = 1; j <= a; j++)
			s.push_back(c);
	}
	s = " " + s;
	n = s.size();
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (s[i] != s[n + 1 - i]) {
			s[i] = s[n + 1 - i];
			++cnt;
		}
	printf("%d\n", cnt);
	return 0;
}
