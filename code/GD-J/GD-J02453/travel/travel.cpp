#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	//	ios::sync_with_stdio(0);
	//	cin.tie(0),cout.tie(0);
	string s, s1, t, t1;
	cin >> s >> s1 >> t >> t1;
	if (s == t)
	{
		cout << 1;
	}
	else
	{
		cout << 0 << 0 << 0 << 0;
		return 0;
	}
	if (s1[0] == t1[0] && s1[1] == t1[1])
	{
		cout << 1;
	}
	else
	{
		cout << 0 << 0 << 0;
		return 0;
	}
	if ((s1[2] == 'D' && t1[2] == 'E') || (s1[2] == 'E' && t1[2] == 'D'))
	{
		cout << 11;
	}
	else if (s1[2] == 'D' || t1[2] == 'E' || s1[2] == 'E' || t1[2] == 'D')
	{
		cout << 0 << 0;
		return 0;
	}
	cout << 1;
	if ((s1[2] == 'A' && t1[2] == 'B') || (s1[2] == 'B' && t1[2] == 'A') || (s1[2] == 'C' && t1[2] == 'B') || (s1[2] == 'B' && t1[2] == 'C'))
	{
		cout << 1;
	}
	else
		cout << 0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
