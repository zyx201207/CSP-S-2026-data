#include <bits/stdc++.h>
using namespace std;

string tiqu(string s){
	string s1 = "";
	for (int i=s.size()-1; i>=0; i--){
		s1 += s[i];
	}
	return s1;
}

int panduan(string s, string s1){
	if (s1==s) return 1;
	else return 0;
}

int res(string s, string s1){
	int cnt = 0;
	int n = s.size() / 2 - 1;
	for (int i=0; i<=n; i++){
		if (s[i]!=s1[i]) cnt++;
	}
	return cnt;
}

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	int n, a;
	string c, s = "";
	cin >> n;
	for (int i=1; i<=n; i++){
		cin >> a >> c;
		for (int j=1; j<=a; j++){
			s += c;
		}
	}
	string s1 = tiqu(s);
	if (panduan(s, s1)) cout << 0;
	else{
		cout << res(s, s1);
	}
	
	
	//cout << s;
	return 0;
}