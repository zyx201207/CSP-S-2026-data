#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	string s = "";
	for (int i = 1;i <= n;i++) {
		int q;
		char c;
		cin >> q >> c;
		while (q--) s += c;
	}
	string s1 = "aaa",s2 = "bbb";
	if (s.size() % 2 == 0) {
		s1 = s.substr(0,s.size() / 2);
		s2 = s.substr(s.size() / 2 + 1,s.size()-1);
	} else {
		s1 = s.substr(0,s.size() / 2);
		s2 = s.substr(s.size() / 2 + 1,s.size()-1);
	}
	reverse(s2.begin(),s2.end());
	int cnt = 0;
	for (int i = 0;i < s.size() / 2;i++) {
		if (s1[i] != s2[i]) cnt++;
	}
	cout << cnt;
	return 0;
}
