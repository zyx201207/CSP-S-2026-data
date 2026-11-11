//Àî¼ÎÁú GZ-J00155
#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, l, m = 0;
	string s = "", c;
	cin >> n;
	for (int i = 0; i < n; i ++)
	{
		cin >> l >> c;
		for (int j = 0; j < l; j++)
		{
			s += c;
		}
	 } 
	
	
	for (int i = 0; i < s.size()/2; i++)
	{
		if (s[i] != s[s.size()- i - 1]) m++;
	}
	
	cout << m;
	return 0;
 } 
