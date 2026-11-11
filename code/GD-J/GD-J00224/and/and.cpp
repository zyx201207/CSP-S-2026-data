#include<bits/stdc++.h>
using namespace std;
int n,m,a[2005],maxn;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if(n == m)
	{
		maxn = a[1];
		for (int i = 2;i <= n;i++)
		{
			maxn = maxn&a[i];
		}
		cout << maxn;
		return 0;
	}
	if(m == 1)
	{
		sort(a+1,a+n+1);
		cout << a[n];
		return 0;
	}
	for (int i = 1;i <= n-m;i++)
	{
		int d = a[i];
		for(int j = i;j <= i+m;j++)
		{
			d = d&a[j];
		}
		maxn = max(maxn,d);
	}
	cout << maxn;	
	return 0;
 } 
