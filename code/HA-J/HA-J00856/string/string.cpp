#include <bits/stdc++.h>
using namespace std;

string s, s1, s2, s3;
string a, a1, a2, a3;
int vis1[30], vis2[30];
int ans, ans1;

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int a;cin >> a;
		char b;cin >> b;
		for(int i = 0; i < a; i++) {
			s = s + b;
		}
	}	
	s1 = s;
	reverse(s.begin(), s.end());
	if(s == s1) {
		cout << 0;
		return 0;
	}
	int len = s.size();
	int cnt = 0;
	
	for(int i = 0; i < len / 2; i++) {
		s2 = s2 + s1[i];
		cnt++;
	}
	for(int i = len; i >= cnt + 1; i--) {
		s3 = s3 + s1[i];
	}
	int len1 = s2.size();
	
	for(int i = 0; i < len1; i++) {
		if(s2[i] != s3[i]) {
			ans++;
		}
	}
	cout << ans;
	return 0;
} 
