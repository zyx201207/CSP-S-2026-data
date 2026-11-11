#include <bits/stdc++.h>
using namespace std;
string a,b;
int n;
int ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >>n;
	for (int i = 0;i < n;i++)
	{
		int ai;
		string ci;
		cin >>ai >> ci;
		for (int j = 0;j < ai;j++)
		{
			a += ci;
		}
	}
	for (int i = a.size() - 1;i >=0;i--)
	{
		b += a[i];
	}
	for (int w = (a.size() / 2 )- 1;w >= 0;w--)
	{
		if (a[w] != b[w])
		{
			ans++;
		}
	}
	cout <<ans;
	return 0;
}
