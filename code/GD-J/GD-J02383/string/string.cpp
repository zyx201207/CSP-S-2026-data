#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	int a[n+3];
	string b[n+3];
	for (int i=1;i <= n;i++)
	{
		cin >> a[i] >> b[i];
	}
	int c=0,h=0;
	for (int i=1;i <= n;i++)
	{
		if (a[1]!=a[i])h=1;
		if (b[1] != b[i])c=1;
	}
	if (!c)
	{
		cout << 0;
		return 0;
	}
	int ans=0;
	string m;
	if (!h)
	{
		for (int i=1;i <= n;i++)
		{
			m+=b[i];
		}
		int len=m.size();
		for (int i=1;i <= len/2;i++)
		{
			if (m[i] != m[n-i])
			{
				ans++;
			}
		}
		cout << ans*a[1]+a[1] ;
		return 0;
	}
	for (int i=1;i <= n;i++)
	{
		for (int j=1;j <= a[i];j++)
		{
			m+=b[i];
		}
	}
	int len=m.size();
	for (int i=0;i < len/2;i++)
	{
		if (m[i] != m[len-i])
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
 } 
