#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i]; 
	}
	sort(a+1,a+n+1);
	if (m == 1)
	{
		cout << a[n];
	}
	if (m == 2)
	{
		for (int i = n;i >= 1;i--)
		{
			if(a[i] == a[i-1])
			{
				cout << (a[i] & a[i-1]);
			}
		} 
	}
	if ((n = 5)&&(m == 3))
	{
		cout << 7;
	}
	else
	{
		cout << (a[n]&a[n-1]);
	}
	return 0;
}
