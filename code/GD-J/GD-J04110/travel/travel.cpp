#include <bits/stdc++.h>
using namespace std; 

string c1, c2, s1, s2; 

int main()
{
	freopen("travel.in", "r", stdin); 
	freopen("travel.out", "w", stdout); 
	cin >> c1 >> s1 >> c2 >> s2; 
	if (c1 == c2) 
	{
		cout << "1"; 
		string x = "", y = ""; 
		x += s1[0], y += s2[0]; 
		x += s1[1], y += s2[1]; 
		if (x == y) 
		{
			cout << "1"; 
			if (s1[2] <= 'C' && s2[2] <= 'C')
			{
				cout << "1"; 
				if (s1[2]+1 == s2[2] || s1[2]-1 == s2[2]) cout << "1"; 
				else cout << "0"; 
			}
			else if (s1[2] > 'C' && s2[2] > 'C')
			{
				cout << "1"; 
				if (s1[2]+1 == s2[2] || s1[2]-1 == s2[2]) cout << "1"; 
				else cout << "0"; 
			}
			else cout << "00";
		}
		else cout << "000"; 
	}
	else cout << "0000"; 
} 
