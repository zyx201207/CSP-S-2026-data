#include<bits/stdc++.h>
using namespace std;
int c1, c2;
string s1, s2;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2)
		cout << 1;
	else
		cout << 0;
	string n1 = s1.substr(0, 2), n2 = s2.substr(0, 2);
	if(n1 == n2 && c1 == c2)
		cout << 1;
	else
		cout << 0;
	char a1 = s1[2], a2 = s2[2];
	int d1, d2;
	if(a1 == 'A' || a1 == 'B' || a1 == 'C')
		d1 = 0;
	else
		d1 = 1;
	if(a2 == 'A' || a2 == 'B' || a2 == 'C')
		d2 = 0;
	else
		d2 = 1;
	if(d1 == d2 && n1 == n2 && c1 == c2)
		cout << 1;
	else
		cout << 0;
	bool ok = 0;
	if(a1 > a2)
		swap(a1, a2);
	if(a1 == 'A' && a2 == 'B')
		ok = 1;
	if(a1 == 'B' && a2 == 'C')
		ok = 1;
	if(a1 == 'D' && a2 == 'F')
		ok = 1;
	if(d1 == d2 && n1 == n2 && c1 == c2 && ok)
		cout << 1;
	else
		cout << 0;
	return 0;
} 
