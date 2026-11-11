#include<bits/stdc++.h>
using namespace std;
string s,c,h;
int n,a,sum,j,zs;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1 ; i <= n ; i ++)
	{
		cin >> a >> c;
		sum += a;
		for (int i = 1 ; i <= a ; i ++)
		{
			s += c;
		}
	}
	for (int i = n - 1 ; i >= 0 ; i --)
	{
		h += s[i];
	}
	if (s == h)
	{
		cout << 0;
		return 0;
	}
	if (sum % 2 == 0)
	{
		for (int i = 0 ; i < sum  / 2; i ++)
		{
			if (s[i] != s[sum - 1 - i])
			{
				zs ++;
			}
		}
	}
	else
	{
		for (int i = 0 ; i < (sum + 1)  / 2 - 1; i ++)
		{
			if (s[i] != s[sum - 1 - i])
			{
				zs ++;
			}
		}
	}
	cout << zs;
	return 0;
}
