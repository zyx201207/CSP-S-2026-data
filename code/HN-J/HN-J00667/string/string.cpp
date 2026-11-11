#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	string s;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int x;
		string y;
		cin >> x >> y;
		for (int j = 1; j <= x; j++){
			s += y;
		}
	}
	string s1 = s;
	reverse(s.begin(),s.end());
	if (s1 == s){
		cout << 0;
		return 0;
	}
	long long cnt = 0;
	for (int i = 0; i < s.size(); i++){
		if (s1[i] != s[i]){
			cnt++;
		}
	}
	cout << cnt / 2;
	return 0;
}

