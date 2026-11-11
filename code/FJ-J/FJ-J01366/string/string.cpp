#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[11505][11505];
string s;
int n;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		char c;
		cin >> a >> c;
		for (int i = 1; i <= a; i++)
			s.push_back(c);
	}
	int len = s.size();
	s = " " + s;
	for (int l = 2; l <= len; l++)
		for (int i = 1; i+l-1 <= len; i++) {
			int j = i+l-1;
			f[i][j] = f[i+1][j-1] + (s[i] != s[j]);
		}
	cout << f[1][len];
	return 0;
}
