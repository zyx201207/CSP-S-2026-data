#include <bits/stdc++.h>
#define ll long long
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2)
	{
		cout << "1";
		int s3 = 0,s4 = 0;
		for (int i = 0;i <= 1;i++)
		{
			s3 += s1[i] - '0';
			s4 += s2[i] - '0';
			s3 *= 10;
			s4 *= 10;
		}
		if (s3 == s4)
		{
			cout << "1";
			if ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] <= 'D'))
			{
				cout << "1";
				char s5 = s1[2],s6 = s2[2];
				if (s6 < s5)
				{
					swap(s5,s6);
				}
				if ((s5 == 'A' && s6 == 'B') || (s5 == 'B' && s6 == 'C') || (s5 == 'D' && s6 == 'F'))
				{
					cout << "1";
				}
				else
				{
					cout << "0";
				}
			}
			else
			{
				cout << "00";
			}
		}
		else
		{
			cout << "000";
		}
	}
	else
	{
		cout << "0000";
	}
	return 0;
}
