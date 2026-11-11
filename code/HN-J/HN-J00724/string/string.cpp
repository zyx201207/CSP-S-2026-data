#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, a, l = 0, cnt = 0;
	char c;
	string s;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a >> c;
		l += a;
		s += c;
	}
	for (int i = 0; i < l / 2; i++){
		if (s[i] != s[l - i + 1]){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
