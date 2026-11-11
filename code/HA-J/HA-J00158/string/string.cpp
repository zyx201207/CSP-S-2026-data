#include<bits/stdc++.h>
using namespace std;

int main () {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
	string s = "";
	long long l = 0;
	for (int i = 1;i <= n;i++) {
		long long a;
		cin >> a;
		l += a;
		char b;
		cin >> b;
		for (int j = 1;j <= a;j++) {
			s = s + b;
		}
	}
	string rs = s;
	reverse(rs.begin(),rs.end());
	if (rs == s) cout << 0;
	else {
		int num = 0;
		for (int i = 0;i < l / 2;i++) {
			long long j = l - 1;
			if (s[i] != s[j]) num++;
			j--;
		}
		cout << num;
	}
	return 0;
}
