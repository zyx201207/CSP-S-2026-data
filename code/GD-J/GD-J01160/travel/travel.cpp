#include <bits/stdc++.h>
using namespace std;
signed main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string s1, s2;
	int a, b;
	cin >> a >> s1 >> b >> s2;
	bool f = 1;
	if (a == b) printf("1");
	else{
		printf("0");
		f = 0;
	}
	if (f && s1.substr(0, 2) == s2.substr(0, 2)) printf("1");
	else{
		printf("0");
		f = 0;
	}
	if (f && (s1[2] < 'D' && s2[2] < 'D' || s1[2] > 'C' && s2[2] > 'D')) printf("1");
	else{
		printf("0");
		f = 0;
	}
	if (f && abs(s1[2] - s2[2]) <= 1) printf("1");
	else{
		printf("0");
	}
	return 0;
}
