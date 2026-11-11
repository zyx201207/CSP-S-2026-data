#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int f = (c1 == c2);
	cout << f;
	if (!f)
	{
		cout << "000";
		return 0;
	}
	f = 1;
	for (int i = 0; i < 2; i++)
		if (s1[i] != s2[i])
		{
			f = 0;
			break;
		}
	cout << f;
	if (!f)
	{
		cout << "00";
		return 0;
	}
	f = ((s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C') || (s1[2] >= 'D' && s1[2] <= 'F' && s2[2] >= 'D' && s2[2] <= 'F'));
	cout << f;
	if (!f)
	{
		cout << 0;
		return 0;
	}
	cout << ((s1[2] != 'C' && s1[2] != 'D' && s2[2] != 'C' && s2[2] != 'D' && (s1[2] + 1 == s2[2]) || (s2[2] + 1) == s1[2]));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
