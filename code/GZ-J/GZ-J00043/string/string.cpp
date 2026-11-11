//贵阳市第十九中学 刘承福 GZ-J00043
#include <bits/stdc++.h>
using namespace std;

int n;
string s, s2, s3, s4;

string hui(string s)
{
	string sum;
	for (int i = s.size()-1; i >= 0; i--)
	{
		sum += s[i];
	}
	return sum;
}

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int a;
		char c;
		cin >> a >> c;
		for (int i = 1; i <= a; i++)
		{
			s += c;
		}
	}
	if (s.size() % 2 == 0)
	{
		for (int i = 0; i < s.size()/2; i++)
		{
			s2 += s[i];
		}
		s3 = hui(s2);
		s4 = s2 + s3;
	}
	else
	{
		for (int i = 0; i <= s.size()/2 - 1; i++)
		{
			s2 += s[i];
		}
		s3 = hui(s2);
		s4 = s2 + s[s.size()/2] + s3;
	}
	int ans = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != s4[i])
		{
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}

