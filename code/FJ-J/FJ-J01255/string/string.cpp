#include <bits/stdc++.h>
using namespace std;
long long n, a, Ans;
char c;
string s;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	while (n--) {
		cin >> a >> c;
		for (int i = 1; i <= a; i++) s += c;
	}
	int l = 0, r = s.size() - 1;
	while (l < r) {
		if (s[l] != s[r]) Ans++;
		l++;
		r--;
	}
	cout << Ans;
	return 0;
}
