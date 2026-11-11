#include <bits/stdc++.h>
using namespace std;
int main() {
	//freopen("string.in", "r", stdin);
	//freopen("string.out", "W", stdout);
	int n;
	cin >> n;
	string s;
	long long num = 0;
	for(int i = 1; i <= n; i++) {
		long long x;
		char a;
		cin >> x >> a;
		num += x;
		for(int i = num - x; i <= num; i++) s[i] = a;
	}
	long long ans = 0;
	for(int i = 0; i < num / 2; i++) {
		if(s[i] != s[num - i]) ans++;
	}
	cout << ans;
	return 0;
}
