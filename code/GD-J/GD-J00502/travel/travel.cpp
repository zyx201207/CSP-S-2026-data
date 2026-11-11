#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	
	int mn1 = min(int(s1[0]) * 10 + int(s1[1]), int(s2[0]) * 10 + int(s2[1]));
  int mx1 = max(int(s1[0]) * 10 + int(s1[1]), int(s2[0]) * 10 + int(s2[1]));
  int mn2 = min(s1[2], s2[2]);
  int mx2 = max(s1[2], s2[2]);
  
	int b1 = c1 == c2;
	int b2 = mn1 == mx1 && mn2 != mx2;
	int b3 = b2 && ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D')); 
  
  int b4 = (b3 && ((mn2 == 'D' && mx2 == 'F') || (mn2 + 1 == mx2))) || (mn1 + 1 == mx1 && mx2 == mn2); 
	cout << b1 << b2 << b3 << b4;
	return 0;
} 
