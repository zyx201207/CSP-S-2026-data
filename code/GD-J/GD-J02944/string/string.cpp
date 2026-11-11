#include <bits/stdc++.h>
using namespace std;

int n;
bool hui(string s)
{
	for(int i = 0 ; i <= s.size() - 1 ; i ++)
	{
		if(s[i] != s[s.size() - 1 - i])
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	cin >> n;
	string s;
	for(int i = 1 ; i <= n ; i ++)
	{
		int a;
		cin >> a;
		char c;
		cin >> c;
		for(int j = 1 ; j <= a ; j ++)
		{
			s += c;
		}
	}
	if(hui(s))
	{
		cout << 0;
	}
}
