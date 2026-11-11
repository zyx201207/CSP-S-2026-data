#include <bits/stdc++.h>
using namespace std;

int main () {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	string c1, c2, s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int a1, a2, q1 = 0, q2 = 0, q3 = 0, q4 = 0;
	
	a1 = (c1[0] - '0') * 10 + (c1[1] - '0');
	a2 = (c2[0] - '0') * 10 + (c2[1] - '0');
	if (a1 == a2) q1 = 1;
	cout << q1;
	
	a1 = (s1[1] - '0');
	a2 = (s2[1] - '0');
	if (a1 == a2 && q1) q2 = 1;
	cout << q2;
	
	a1 = 0;
	a2 = 0;
	if (s1[2] == 'F' || s1[2] == 'D') a1 = 1;
	if (s2[2] == 'F' || s2[2] == 'D') a2 = 1;
	if (a1 == a2 && q1 && q2) q3 = 1;
	cout << q3;
	
	if (q1 && q2 && q3)
		if (s1[2] == 'F' && s2[2] == 'D' || s1[2] == 'D' && s2[2] == 'F' || s1[2] == 'C' && s2[2] == 'B' || s1[2] == 'B' && s2[2] == 'C' || s1[2] == 'A' && s2[2] == 'B' || s1[2] == 'B' && s2[2] == 'A')
			q4 = 1;
	cout << q4;
		
	return 0;
}
