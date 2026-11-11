#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, a, x = 0, sum = 0, cnt = 0;
string s,str;
char c;
signed main() {
	freopen("string","r",stdin);
	freopen("string","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i ++) {
		cin >> a >> c;
		cnt += a;
		for (int i = 1;i <= a;i ++) {
			s += c;
		}
	}
	int x = cnt;
	for (int i = 0;i <= cnt /2;i ++) {
		if (s[i] != s[x - 1]) {
			sum ++;
			x --;
		}
	}
	cout << sum;
	return 0;
}
