#include<bits/stdc++.h>

using namespace std;

string s;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n;
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		long long id;
		char a;
		cin >> id >> a;
		for(long long j = 1; j <= id; j ++) {
			s = s + a;
		}
	}
	long long l = 0, r = s.size() - 1;
	long long cnt = 0;
	while(l <= r) {
		if(s[l] != s[r]) cnt ++;
		l ++, r --;
	}
	cout << cnt << endl;
	return 0;
}
