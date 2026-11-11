#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
long long n, a, cnt = 0;
char c;
string s = "";
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	while(n--) {
		cin >> a >> c;
		for (int i = 1; i <= a; ++i) s += c;
	}
	long long l = s.size() - 1;
	for (int i = 0; i <= l / 2; ++i) {
		if (s[i] != s[l - i]) cnt++;
	}
	
	cout << cnt;
	return 0;
}
