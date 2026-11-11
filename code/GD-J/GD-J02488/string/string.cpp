#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","r",stdout);
	long long n,a[10000],num=0;
	cin >> n;
	string c,s;
	char f;
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i] >> f;
		for(int j = 1;j<=a[i];j++)
		{
			c+=f;
		}
	}
	for(int i = 1;i<=n;i++)
	{
		s[i] =c[n+1-i];
		
	}
	if(s==c)
	{
		cout << 0;
	}
	else
	{
		for(int i = 1;i<=n;i++)
		{
			if(s[i]!=c[i])
			{
				num++;
			}
		}
		cout << num/2;
	}
	return 0;
}
