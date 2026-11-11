#include <bits/stdc++.h>
using namespace std;
int n,len = 0;
string s{};
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	char zw = '0';
	s += zw;
	for (int i = 1;i <= n;i++)
	{
		int a;
		cin >> a;
		len += a;
		char b;
		cin >> b;
		for (int j = 1;j <= a;j++)
		{
			s += b;	
		}
	}
	int a = 0;
	for (int i = 1;i <= len / 2 + 1;i++)
	{
		if (s[i] != s[len - i + 1])
		{
			a++;
		}
	}
	cout << a;
	return 0;
}
