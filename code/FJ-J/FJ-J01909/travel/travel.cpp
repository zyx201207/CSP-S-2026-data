#include <bits/stdc++.h>
using namespace std;
int fun(string s) {
	int x = 0;
	for(int i = s.size() - 1; i >= 0; i--) {
		if(s[i] >= 'A' && s[i] <= 'Z') {
			continue;
		}
		x *= 10;
		x += s[i] - '0';
	}
	return x;
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool m=false,n=false,p=false,q=false;
	if(fun(c1) == fun(c2)) {
		m = true;
	}
	if(fun(s1) == fun(s2) && m == true) {
		n = true;
	}
	char l = s1[s1.size() - 1];
	char r = s2[s2.size() - 1];
	if((l == 'A' && (r == 'B' || r == 'C')) || (l == 'B' && (r == 'A' || r == 'C')) || (l == 'C' && (r == 'B' || r == 'A')) || (l == 'D' && r == 'F') || (l == 'F' && r == 'D')) {
		if(n == true) p = true;
	}
	else {
		p = false;
	}
	int x = l, y = r;
	if(abs(x - y) == 1 && p == true) {
		q = true;
	}
	cout << m << n << p << q;
	return 0;
}
