#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c1, c2;
string s1, s2;
bool check(string s1, string s2)
{
	char a = s1[2], b = s2[2];
	if((a == 'A' && b == 'B') || (a == 'B' && b == 'A'))
	{
		return true;
	}
	else if((a == 'B' && b == 'C') || (a == 'C' && b == 'B'))
	{
		return true;
	}
	else if((a == 'D' && b == 'F') || (a == 'F' && b == 'D'))
	{
		return true;
	}
	else
	{
		return false;	
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2)
	{
		cout << 1;
		if(s1[0] * 10 + s1[1] == s2[0] * 10 + s2[1])
		{
			cout << 1;
			if((s1[2] < 'D'&& s2[2] < 'D') || (s1[2] >= 'D' && s2[2] >= 'D'))
			{
				cout << 1;
				if(check(s1, s2))
				{
					cout << 1;
				}
				else
				{
					cout << 0;
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
