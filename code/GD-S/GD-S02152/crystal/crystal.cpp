#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	long long n, m;
	cin >> n >> m;
	long long a[100005], b[100005];
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	
	for(int i = 1;i <= n;i++)
	{
		int num = 0;
		for(int j = 1;j <= i;j++)
		{
			num += (a[i] - a[j]);
		}
		if(num == m)
		{
			b[i] = i;
		}
	}
	long long x = 0;
	for(int i = 1;i <= n;i++)
	{
		x = max(x,b[i]);
	}
	cout << x;
	
	
	return 0;
 } 
