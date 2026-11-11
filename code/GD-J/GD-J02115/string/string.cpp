#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	string s;
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	while(n--){
		int a;
		char c;
		cin >> a >> c;
		string st(a, c);
		s += st;
	}
	int len = s.size();
	long long l = 0, r = len-1, cnt = 0;
	while(l <= r){
		if(s[l]!=s[r]) cnt++;
		l++; r--;
	}
	cout << cnt;
	return 0;
}
