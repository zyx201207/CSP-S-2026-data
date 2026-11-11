#include <bits/stdc++.h>
using namespace std;
string str;
int n;
void solve();
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		int s;
		char c;
		cin >> s >> c;
		for (int j = 1; j <= s; j ++) {
			str += c;
		}
	}
	solve();
	return 0;
}
void solve() {
	int mid = str.size() / 2, step = 0;
	int i = 1, j = mid + 1;
	string s2 = "#" + str;
	reverse(str.begin(), str.end());
	str = "#" + str;
//	cout << str << endl << s2;
	for (int i = 1; i <= str.size(); i ++) {
		if (str[i] != s2[i]) {
			step ++;
		}
	}
	cout << step / 2;
}
/*
*/
