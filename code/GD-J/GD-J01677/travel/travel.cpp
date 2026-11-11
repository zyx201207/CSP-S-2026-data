#include <bits/stdc++.h>
#define ll long long
using namespace std;
string c1, s1, c2, s2;
bool tc = 0, tz = 0, tp = 0;
int main()
{
	freopen("travel.in" , "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2)
	{
		cout << 1;
		tc = 1;
	}
	else cout << 0;
	if (tc && s1[0] == s2[0] && s1[1] == s2[1])
	{
		cout << 1;
		tp = 1;
	}
	else cout << 0;
	if (tc && tp && ((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')) || ((s1[2] == 'E' || s1[2] == 'F') && s2[2] == 'E' || s2[2] == 'F'))
	{
		cout << 1;
		tz = 1;
	}
	else cout << 0;
	char z1 = s1[2];
	char z2 = s2[2];
	if (tc && tz && tp && (z1 == z2 + 1 || z2 == z1 + 1 || (z1 == 'D' && z2 == 'F') || (z1 == 'F' && z2 == 'D')) && ((z1 != 'C' && z2 != 'D') && (z1 != 'D' && z2 != 'C'))) cout << 1;
	else cout << 0;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
