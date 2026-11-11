#include <bits/stdc++.h>
using namespace std;

string c1, s1 , c2 , s2;
int c;

int main () {
	
	freopen ("travel.in" , "r" , stdin);
	freopen ("travel.out" , "w" , stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	bool flag = true;
	s1 = "#" + s1;
	s2 = "#" + s2;
	c1 = "#" + c1;
	c2 = "#" + c2;
	//1 
	if (c1 == c2) 
		printf ("1");
	else 
		printf ("0") , flag = false;
	//2
	//cout << s2;
	bool ok = true;
	for (int i = 1 ; i <= 2 ; i ++) 
		if (s1[i] != s2[i]) 
			ok = false;
	if (flag && ok) 
		printf ("1");
	else 
		printf ("0");
	// 3
	if (flag && s1[3] >= 'A' && s1[3] <= 'C' && s2[3] >= 'A' && s2[3] <= 'C')
		c = 1;
	else if (flag && ((s1[3] == 'D' && s2[3] == 'F') || (s1[3] == 'F' && s2[3] == 'D')))
		c = 2;
	else 
		c = 3;
	if (flag && ok && (c == 1 || c == 2)) 
		printf ("1");
	else 
		printf ("0");
	// 4
	if (flag && ok && c == 2)
	 	printf ("1");
	else if (flag &&   ok && c == 1 && (s1[3] + 1  == s2[3] || s2[3] + 1 == s1[3]))
		printf ("1");
	else 
		printf ("0");
 	
	return 0;
} 
// 02 01A 02 01B
