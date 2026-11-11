#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	string s;
	int len = 0;
	while(n--) {
		int m;
		cin >> m;
		len += m;
		char a;
		cin >> a;
		while(m--) {
			s += a;
		}
	}
	//cout << s;
	//cout << (len + 1) / 2;
	long long cnt = 0;
	for(int i = 0; i < (len + 1) / 2; i++) {
		if(s[i] != s[len - i - 1]) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
