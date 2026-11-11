#include<bits/stdc++.h>
using namespace std;
int a[100086];
char s[100086];
bool flag(int n, string c) {
	int h = n / 2, m = n - 1, i = 0;
	while(m != h) {
		if(c[i] != c[m]) {
			return false;
		}
		m--;i++;
	}
	return true;
}

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string c;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i] >> s[i];
		for(int j = 0; j < a[i]; j++) {
			c += s[i];
		}
	}
	int len = c.length();
	int ans = 0;
	bool check = flag(len, c);
	if(check) {
		cout << 0;
	}
	else {
		len -= 1;
		int h = len / 2, i = 1;
		while(len != h) {
			if(c[i] != c[len]) ans++;
			len--;i++;
		}
		cout << ans;
	}
	return 0;
} 
