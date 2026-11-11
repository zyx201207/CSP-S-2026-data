#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll ans = 0;
string s;

int main() {
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	int n, l = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		char c;
		scanf("%i %c", &x, &c);
		l += x; 
		while (x--) 
			s.push_back(c);
	} 
	for (int i = 0; i <= l / 2; i++) 	
		if (s[i] != s[l + 1 - i])
			ans++;
	cout << ans;
	return 0;
} 
