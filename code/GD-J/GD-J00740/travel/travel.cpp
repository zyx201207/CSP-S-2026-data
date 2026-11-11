#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c, s, cc, ss;
	cin >> c >> s >> cc >> ss;
	if(c.size() != cc.size()) {
		cout << "0000";
		return 0;
	}
	bool flag = true;
	for(int i = 0; i < c.size(); i++) {
		if(c[i] != cc[i]) {
			cout << 0;
			flag = false;
			break;
		}
	}
	if(flag) cout << 1;
	
	bool v = true;
	if(!flag) {
		v = false;
		cout << 0;
	} else {
		for(int i = 0; i < s.size(); i++) {
			if(isdigit(s[i]) && isdigit(ss[i])) {
				if(s[i] != ss[i]) {
					cout << 0;
					v = false;
					break;
				}
			}
		}
		if(v) cout << 1;
	}
	
	bool vis = true;
	if(!v) {
		cout << 0;
		vis = false;
	} else {
		if(s[2] >= 'D') {
			if(ss[2] >= 'D') cout << 1;
			else {
				cout << 0;
				vis = false;
			}
		} else {
			if(ss[2] <= 'C') cout << 1;
			else {
				cout << 0;
				vis = false;
			}
		}
	}
	
	if(!vis) cout << 0;
	else {
		int t = s[2] - ss[2];
		if(abs(t) == 1) cout << 1;
		else cout << 0;
	}
	
	return 0;
} 
