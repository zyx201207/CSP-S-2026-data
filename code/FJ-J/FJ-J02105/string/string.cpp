#include <bits/stdc++.h>
using namespace std;
int n,m[100001],c;
char s[100001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 0;i < n;i ++) {
		cin >> m[i] >> s[i];
	}
	for (int i = 0;i < n/2;i ++) {
		if (s[i] != s[n - i - 1]) {
			c += max(m[i],m[n - i - 1]);
		} else {
			if (i != n / 2 - 1) {
				c += max(m[i],m[i - i - 1] - min(m[i],m[i - i - 1]));
			}
		}
	}
	cout << c;
	return 0;
}
