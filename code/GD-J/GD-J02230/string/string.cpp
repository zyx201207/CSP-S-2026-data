#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	string s;
	int n;
	cin >> n;
	long long cnt = 0;
	for (int i = 1; i <= n; i ++){
		long long a;
		char c;
		cin >> a >> c;
		cnt += a;
		for (int j = 1; j <= a; j ++){
			s += c;
		}
	}
	long long ans = 0;
	for (long long i = 0, j = cnt - 1; i < j; i ++, j --){
		if (s[i] != s[j]) ans ++;
	}
	cout << ans << '\n';
	return 0;
}
