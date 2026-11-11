#include <bits/stdc++.h>
using namespace std;

long long n, x, a, cnt;
char c;
string s;

int main() {
//	freopen("string.in", "r", stdin);
//	freopen("string.out", "w", stdout);
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++) {
		cin >> x >> c;
		while(x--) s += c;
	}
	a = s.length();
	for(int i = 1; i < a - 1; i++)
		if(s[i - 1] != s[a - i]) s[a - i] = s[i - 1], cnt++;
	printf("%lld", cnt);
	return 0;
}
