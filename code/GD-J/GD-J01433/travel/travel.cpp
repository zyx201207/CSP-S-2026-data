#include<bits/stdc++.h>
using namespace std;
int main () {
	freopen ("travel.in" , "r", stdin);
	freopen ("travel.out" , "w", stdout);
    string s1, s2, t1, t2;
    cin >> s1 >> t1 >> s2 >> t2;
    if (s1 != s2) {
    	cout << "0000";
    	return 0;
	} else {
		cout << "1";
	}
	char  c1 = t1[2], c2 = t2[2];
	int a, b;
	if (c1 == 'A') a = 1;
	if (c1 == 'B') a = 2;
	if (c1 == 'C') a = 3;
	if (c1 == 'D') a = 4;
	if (c1 == 'F') a = 5;
	if (c2 == 'A') b = 1;
	if (c2 == 'B') b = 2;
	if (c2 == 'C') b = 3;
	if (c2 == 'D') b = 4;
	if (c2 == 'F') b = 5;
	int ok = 0;
	for (int i = 1; i <= 2; i++) {
		if (t1[i - 1] == t2[i - 1]) ok++;
	}
	if (ok != 2) {
		cout << "000";
		return 0;
	}else {
		cout << 1;
	}
	
	if (((a >= 1 && a <= 3) && (b >= 1 && b <= 3)) || ((a == 4 && a == 5) && (b == 4 && b == 5))) {
		cout << 1;
	} else {
		cout << "00";
		return 0;
	}
	if (abs(a - b) == 1) {
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
} 
