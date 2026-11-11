#include <bits/stdc++.h>
#include <iostream> 
#include <string>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	
	string c1, s1, c2, s2;
	cin >> c1 >> c2 >> s1 >> s2;
	int m, n;
	
	m = (c1[0] - '0') * 10 + (c1[1] - '0');
	n = (s1[0] - '0') * 10 + (s1[1] - '0');
	
	if (m == n ) {
		cout << "1" ;
	}
	else {
		cout << "0000";
		return 0;
	}
	
	m = (c2[0] - '0') * 10 + (c2[1] - '0');
	n = (s2[0] - '0') * 10 + (s2[1] - '0');
	
	if (m == n ) {
		cout << "1";
	}
	else {
		cout << "000";
		return 0;
	}
	
	int a, b;
	a = c2[2] - 'A';
	b = s2[2] - 'A';
	if (a >= 0 && a <= 2 && b >= 0 && b <= 2 || a == 3 && a == 5 && b == 3 && b == 5) {
		cout << "1" ;
	}
	else {
		cout << "00";
		return 0;
	}
	
	if (a + 1 == b || a - 1 == b) {
		cout << "1" ;
	}
	else {
		cout << "0";
		return 0;
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
