#include <iostream>
#include <cstring>
using namespace std;

string s;
int n, a;
char c;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a >> c;
		for(int j = 1; j <= a; j++) s += c;
	}
	int m = s.size(), ans = 0;
	s = ' ' + s;
	for(int i = 1; i <= m / 2; i++) {
		if(s[i] != s[m - i + 1]) ans++;
	}
	cout << ans;
}
