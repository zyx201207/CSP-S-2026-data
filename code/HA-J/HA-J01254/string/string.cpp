#include<bits/stdc++.h>
using namespace std;
int n, a[200020] = {0}, cnt = 0, len, minc;
char c[200020] = {0}; bool f = 0; string s;
void combine() {
	for(int i = 0; i < n; i++) {
		for(int p = 0; p < a[i]; p++) s += c[i];
	}
}
void is() {
	f = 0;
	for(int i = 0; i <= s.size() / 2; i++) {
		if(s[i] == s[len - i - 1]) f = 1;
		else {
			f = 0;
			break;
		}
	}
}
void edit() {
	for(int i = 0; i <= s.size() / 2; i++) {
		is();
		if(!f) {
			if(s[i] != s[len - i - 1]) {
				s[i] = s[len - i - 1];
				cnt++;
			}
		}	
	}
}
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i] >> c[i];
	}
	combine();
	len = s.size();
	edit();
	cout << cnt << endl;
	return 0; 
}

