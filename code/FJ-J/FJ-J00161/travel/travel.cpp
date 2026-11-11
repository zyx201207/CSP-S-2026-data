#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);	
	
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) 
	{
		cout << "1";	
		string a, b;
		a = b = "";
		for (int i = 0; i < 2; i ++) a += s1[i];
		for (int i = 0; i < 2; i ++) b += s2[i];
		if (a == b) 
		{
			cout << "1";	
			char c = s1[2], d = s2[2];
			if (('A' <= c && c <= 'C' && 'A' <= d && d <= 'C') || ('D' <= c && c <= 'F' && 'D' <= d && d <= 'F'))
			{
				cout << "1";
				if (abs(c - d) == 1) cout << "1\n";
				else cout << "0\n";
			}
			else cout << "00\n";
		}
		else cout << "000\n";  	
	}
	else cout << "0000\n";
} 
