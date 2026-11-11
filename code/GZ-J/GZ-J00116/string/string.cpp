//GZ-J00116 贵阳市第一实验中学 姚彦竹
#include <iostream>
#include <vector>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	int n, x, ans = 0; char c;
	cin >> n;
	string s;
	s.reserve(n*1e3);
	for (int i = 0; i < n; i++) {
		cin >> x >> c;
		while (x--) s += c;
	}
	for (int i = 0; i < s.length() / 2; i++) {
		if (s[i] != s[s.length()-1-i])
			ans++;
	}
	cout << ans;
	return 0;
}
