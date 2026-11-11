#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 500, MAS = 1e9 + 10;
long long n, a, l = 1, sumN, cnt;
char c;
string s;
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for(long long i = 1; i <= n; i++) {
		cin >> a >> c;
		for(long long j = 0; j < a; j++) {
			s += c;
		}
		l += a;
	}
	for(long long i = 0; i <= l / 2; i++) {
		if(s[i] != s[l - i]) cnt++;
	}
	cout << cnt;
	return 0;
}
