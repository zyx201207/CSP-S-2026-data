#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char c[200005];
int s[200005];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i ++) {
		cin >> a[i] >> c[i];
		s[i] = s[i - 1] + a[i];
	}
	string s = "";
	for(int i = 1;i <= n;i ++) {
		for(int j = 1;j <= a[i];j ++) {
			s += c[i];
		}
	}
	string s1 = "";
	for(int i = s.size() - 1;i >= 0;i --) {
		s1 += s[i];
	}
	int ans = 0;
	for(int i = 0;i < s.size() / 2;i ++) {
		if(s[i] != s1[i]) {
			ans ++;
		}
	}
	cout << ans << endl;
	return 0;
}
