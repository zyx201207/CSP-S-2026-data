#include <bits/stdc++.h>
using namespace std;
string c1, c2, s1, s2;
int main ()
{
    freopen ("travel.in", "r", stdin);
    freopen ("travel.out", "w", stdout);
    
    cin >> c1 >> s1 >> c2 >> s2;
    
    if (c1 == c2)
    {
    	cout << 1;
	}
	else
	{
		cout << 0;
	}
	
	if (s1[1] == s2[1])
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	bool m = true;
	if ((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C'))
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	
	if ((s1[2]  + 1 == s2[2]) || s1[2] - 1 == s2[2])
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
    return 0; 
} 
