#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a;
	string s,t;
	char c;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a >> c;
		for(int j = 1;j <= a;j++)
		{
			s = s + c;
		}
	}
	string x,y;
	if(s.length() % 2 == 0)
	{
		for(int i = 0;i < s.length() / 2;i++)
		{
			x = x + s[i];
		}
		for(int i = s.length() / 2;i < s.length();i++)
		{
			y = y + s[i];
		}
	}
	else
	{
		for(int i = 0;i < s.length() / 2;i++)
		{
			x = x + s[i];
		}
		for(int i = s.length() / 2 + 1;i < s.length();i++)
		{
			y = y + s[i];
		}
	}
	int ans = 0;
	for(int i = 0;i < x.length();i++)
	{
		if(x[i] != y[i])
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
