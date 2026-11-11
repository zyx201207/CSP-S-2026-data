#include<bits/stdc++.h>
using namespace std;
int n, ans;
string s;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		int a;
		char c;
		cin >> a >> c;
		for(int i = 1;i <= a;i++) s += c;
	}
//	cout << s << endl;
	long long len = s.size();
//	cout << len << endl;
	s = "0" + s;
	if(len % 2 == 1) {
		for(int i = 1;i <= len / 2;i++) {
			if(s[i] != s[len + 1 - i]) ans++;
		}
	}
	else {
		for(int i = 1;i <= (len - 1) / 2;i++) {
			if(s[i] != s[len + 1 - i]) ans++;
		}
	}
	cout << ans;
	return 0;
}
