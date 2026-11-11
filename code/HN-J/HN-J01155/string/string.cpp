#include <bits/stdc++.h>
using namespace std;
int n,a,num;
string v;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a;
		cin >> v;
		for (int i = 1;i <= a;i++)
		{
			s += v;
		}
	}
	for (int i = 0;i < s.size() / 2;i++)
	{
		if (s[i] != s[s.size() - i - 1])
		{
			num++;
		}
	}
	cout << num;
	return 0;
} 
