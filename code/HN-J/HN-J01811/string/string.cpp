#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 10;
string s;
char x;
int n, a;
ll ans;
inline int read() {
	char ch;
	while(!isdigit(ch = getchar()));
	int res = ch ^ 48;
	while(isdigit(ch = getchar()))
		res = (res << 1) + (res << 3) + (ch ^ 48);
	return res;
}
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	n = read();
	for(int i = 1; i <= n; ++i) {
		a = read();
		cin >> x;
		for(int j = 1; j <= a; ++j)
			s += x;
	}
	for(int i = 0; i < s.size() / 2; ++i)
		ans += (s[i] != s[s.size() - i - 1]);
	cout << ans;
	return 0;
}//64
