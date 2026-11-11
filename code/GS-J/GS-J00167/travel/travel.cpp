#include <bits/stdc++.h>
using namespace std;

char a[5] = {'A','B','C','D','F'};

int main()
{
	freopen("travel.in", "r",stdin);
	freopen("travel.out", "w",stdout);
	int c1,c2;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2)
	{
		cout << "0000";
	}
	else
	{
		cout << "1";
		if (s1[0] == s2[0] && s1[1] == s2[1])
		{
			cout << "1";
			if ((s1[2] <= a[2] && s2[2] < a[2]) || (s1[2] >= a[3] && s2[2] > a[3]))
			{
				cout << "1";
				int t1,t2;
				for (int i = 0; i < 5 ; i++)
				{
					if (s1[2] == a[i])
						t1 = i;
				}
				for (int i = 0; i < 5 ; i++)
				{
					if (s2[2] == a[i])
						t2 = i;
				}
				if (((t1 + 1) == t2) || ((t1 - 1) == t2))
					cout << "1";
				else
					cout << "0";
			}
			else
				cout << "00";
		}
		else
			cout << "000";
	}
	return 0;
}
