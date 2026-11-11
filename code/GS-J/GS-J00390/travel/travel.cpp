#include <bits/stdc++.h>
using namespace std;
bool side (char a, char b)
{
	if (a == 'A' || a == 'B' || a == 'C')
	{
		if (b == 'A' || b == 'B' || b == 'C') return true;
		else return false;
	}
	else if (a == 'D' || a == 'F')
	{
		if (b == 'D' || b == 'F') return true;
		else return false;
	}
}
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1[0] == c2[0] && c1[1] == c2[1]) 
	{
		cout << 1;

		if (s1[0] == s2[0] && s1[1] == s2[1]) 
		{
			cout << 1;
		 	if (side(s1[2], s2[2]) )
		 	{
		 		cout << 1;
		 		if((s1[2] == 'C' && s2[2] == 'A') || (s1[2] == 'C' && s2[2] == 'A')) cout << 0;
		 		else cout << 1;
		 	}
		 	else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";

	fclose(stdin);
	fclose(stdout);
	return 0;
}
