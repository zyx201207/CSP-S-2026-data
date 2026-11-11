#include<bits/stdc++.h>
using namespace std;
long long cnt;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	string s;
	int n;
	cin >> n;
	bool flag = true;
	for(int i = 0; i < n; i++) {
		int x;char op;
		cin >> x;cin >> op;
		while(x--) s += op;
	}
	for(int i = 0, j = s.size() - 1; i <= s.size() / 2, j >= s.size() / 2; i++, j--)
		if(s[i] != s[j])
			cnt++;
	cout << cnt;
	return 0;
}
