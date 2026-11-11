//GZ-J00395  贵阳市第三实验中学  闫张玴
#include <bits/stdc++.h> 
using namespace std;
#define int unsigned long long
int n, ans;
string s;
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i=1; i<=n; i++) {
		int a;
		char c;
		cin >> a >> c;
		for(int j=1; j<=a; j++) s+=c; 
	}
	for(int i=0; i<=s.size()/2; i++) {
		if(s[i] != s[s.size()-i-1]) ans++;
	}
	cout << ans;
	return 0;
}
