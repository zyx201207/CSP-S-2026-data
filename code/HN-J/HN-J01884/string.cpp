#include <bits/stdc++.h>
using namespace std;
int n, a[2 * 100000];
string c[2 * 100000], s, k, h; 
int main()
{
	//freopen ("string.in","r",stdin);
	//freopen ("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i] >> c[i];
		for (int j = 1;j <= a[i];j++)
		{
			s += c[i];
		}
	}
	int len = s.size();
	if (len % 2 == 0)
	{
		for (int i = 1;i <= len / 2;i++)
		{
			k += c[i];
		}
		for (int i = len;i >= len / 2;i--)
		{
			h += c[i];
		}
	}
	if (k == h)
	{
		cout << "0";
	}
	return 0;
}
