#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	long long b[n+5];
	long long a[n+5];
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int z;
	int num=0;
	
	for(int i = 2; i <= n; i++)
	{
		if(a[i]>a[i-1])
		{
			z=a[i];
			a[i]=a[i-1];
			a[i-1]=z;
		}

	}
	for(int i = 2; i <= n; i++)
	{
		if(a[i]>a[i-1])
		{
			z=a[i];
			a[i]=a[i-1];
			a[i-1]=z;
		}

	}
	if(m==1)
	{
		cout << a[2];
	}
	for(int i = 1; i <= n; i++)
	{
		z=i-1;
		if(a[i]==z)
		{
			num++;
		}
		if(num==n)
		{
			cout << a[n-1];
			return 0;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		cout << a[n-1];
		return 0;
		
	}
}
