#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c, s, c_, s_;
	cin >> c >> c_ >> s >> s_;
	if(c == s) cout << 1;
	else cout << 0;
	if(c == s) {
		if(c_[0] == s_[0] && c_[1] == s_[1]) cout << 1;
		else cout << 0;
	} else cout << 0;
	if(c == s) {
		if(c_[0] == s_[0] && c_[1] == s_[1]) {
			if(c_[2] == 'A' || c_[2] == 'B' || c_[2] == 'C') {
				if(s_[2] == 'A' || s_[2] == 'B' || s_[2] == 'C') cout << 1;
				else cout << 0;
			} else {
				if(s_[2] == 'D' || s_[2] == 'F') cout << 1;
				else cout << 0;
			} 
		} else cout << 0;
	} else cout << 0;
	if(c == s) {
		if(c_[0] == s_[0] && c_[1] == s_[1]) {
			if(c_[2] == 'A') {
				if(s_[2] == 'B') cout << 1;
				else cout << 0;
			} else if(c_[2] == 'B') {
				if(s_[2] == 'A' || s_[2] == 'C') cout << 1;
				else cout << 0;
			} else if(c_[2] == 'C') {
				if(s_[2] == 'B') cout << 1;
				else cout << 0;
			} else if(c_[2] == 'D') {
				if(s_[2] == 'F') cout << 1;
				else cout << 0;
			} else {
				if(s_[2] == 'D') cout << 1;
				else cout << 0;
			} 
		} else cout << 0;
	} else cout << 0;
	return 0; 
} 
