#include <bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	long long n,change = 0;
	cin >> n;
	string s;
	bool flag = false,t = false;
	for (int i = 1;i <= n;i++)
	{
		long long x;
		string c;
		cin >> x >> c;
		for (int i = 1;i <= x;i++)
		{
			s += c;
		}
	}
	for (int i = 1;i <= s.length();i++)
	{
		if (s[i] == s[s.length() - i])
		{
			flag = true;
		}
		else
		{
			flag = false;
		}
	}
	if (flag == true)
	{
		cout << 0;
		
	}
	if (!flag)
	{
		for (int i = 1;i <= s.length();i++)
		{
			if (s[i] != s[s.length() - i])
			{
				s[s.length() - i] = s[i];
				change++;
			}
			for (int i = 1;i <= s.length();i++)
			{
				if (s[i] == s[s.length() - i])
				{
					t = true;
				}
				else
				{
					t = false;
				}
			}
			if (t == true)
			{
				cout << change;
				break;
			}
		}
	}
	return 0;
}
