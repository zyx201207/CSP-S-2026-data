#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
  for (int i = 0; i < n; i++) {
  	int t; char c;
  	cin >> t >> c;
  	
  	for (int i = 0; i < t; i++) {
  		s += c;
		} 
	}
	unsigned long long ans = 0;
	unsigned long long len = s.size();
	for (unsigned long long i = 0; i <= len - i - 1; i++) {
		if (s[i] != s[len - i - 1]) ans++;
	}	
	
	
	cout << ans;
	return 0;
}
