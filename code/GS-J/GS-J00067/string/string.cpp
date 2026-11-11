#include <bits/stdc++.h>
using namespace std;
string x,p;
int s,n;
int num=0,a=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> s;
	for (int i = 1; i <= s; i++)
	{
		cin >> n >> x;
		for (int i = 1; i <= n; i++)
		{
			p += x;
			a += 1;
		}
	}
	int b = a/2;
	for (int i = 0; i < b; i++)
	{
		if (p[i] != p[a])
		{
			num += 1;
		}
		else
		{
			num == 0;
		}
	}
	cout << num;
	return 0;
}
