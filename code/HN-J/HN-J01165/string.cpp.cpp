#include <bits/stdc++.h>
using namespace std;
int n, a;
string b_z, c, b_f;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a >> c;
		for (int i = 1;i <= a;i++)
		{
			b_z += c;
		}
	}
	for (int i = b_z.size();i >= 0;i--)
	{
		b_f += b_z[i];
	}
	if (b_f == b_z)
	{
		cout << 0;
		return 0;
	}
	else
	{
		if (b_z.size() % 2 == 0)
		{	 
			cout << b_z.size() / 2;
		}
		else
		{
			cout << (b_z.size() - 1) / 2;
		}
	}	
	return 0;
 } 
