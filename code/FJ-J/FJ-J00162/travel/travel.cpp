#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
char a, b, c, d, e, f;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2)
	{
		cout << "0000"; 
		return 0;
	}
	cout << 1;
	a = s1[0], b = s1[1], c = s1[2], d = s2[0], e = s2[1], f = s2[2];
	if(a == d && b == e)
		cout << 1;
	else
	{
		cout << "000";
		return 0;
	}
	if((c == 'F' && f == 'D') || (c == 'D' && f == 'F') || ((c == 'C' || c == 'B' || c == 'A') && (f == 'C' || f == 'B' || f == 'A')))
		cout << 1;
	else
	{
		cout << "00";
		return 0;
	}
	if((c == 'F' && f == 'D') || (c == 'D' && f == 'F') || (c == 'A' && f == 'B') || (c == 'B' && f == 'A') || (c == 'B' && f == 'C') || (c == 'C' && f == 'B'))
		cout << 1;
	else
		cout << 0;
	return 0;
} 
