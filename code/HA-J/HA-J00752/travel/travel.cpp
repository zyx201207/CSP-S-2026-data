#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s1,s2,s3,s4;
	cin >> s1 >> s2 >> s3 >> s4;
	if (s1 != s3)
	{
		cout << "0000";
		return 0;
	}
	cout << "1";
	if (s2[1] == s4[1])
	{
		cout << "1";
		if ((s2[2] < 'D' && s4[2] < 'D') || (s2[2] >= 'D' && s4[2] >= 'D'))
		{
			cout << "1";
			if ((int)s2[2] - (int)s4[2] == 1 || (int)s2[2] - (int)s4[2] == -1 || (s4[2] == 'F' && s2[2] == 'D') || (s4[2] == 'F' && s2[2] == 'D'))
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
		cout << "00";
		if (s2[2] == s4[2])
		{
			if (s2[1] - s4[1] == 1 || s2[1] - s4[1] == -1)
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
			cout << "0";
		}
	}
	return 0;
}
