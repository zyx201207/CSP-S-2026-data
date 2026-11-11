#include<bits/stdc++.h>
using namespace std;
long long n,m,ar[500005],ar2[500005];

int check(int x)
{
	long long a = 0;
	int b = 1;
	for(int i = 0;i<n;i++)
	{
		a = 0;
		for(int j = 0;j<n;j++)
		{
			ar2[j] = abs(ar[j]-ar[i]);
		}
		sort(ar2,ar2+n);
		for(int j = 0;j<x;j++)
		{
			a+=ar2[j];
			if(a>m) 
			{
				b = 0;
				break;
			}
		}
		if(b == 1)
		{
			return 1;
		}
		b = 1;
	}
	return 0;
}

int bi()
{
	int l = 0,r = n,mid;
	while(l<r)
	{
		mid = (l+r+1)/2;
		if(check(mid)) l = mid;
		else r = mid-1;
	}
	return l;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int y = 1,z = 1;
	long long zz = 0;
	cin>>n>>m;
	for(int i = 0;i<n;i++)
	{
		cin>>ar[i];
		if(ar[i]!=i+1) y = 0;
		if(i == 1)
		{
			zz = ar[i]-ar[i-1];
		}
		if(i!=0&&ar[i]-ar[i-1]!=zz) z = 0;
	}
	if(y)
	{
		int b = 1;
		long long a = 0;
		for(int j = 0;j*2<=n;j++)
		{
			if(a+j+1>m) 
			{
				break;
			}
			a+=(j+1);
			b++;
			if(a+j+1>m) 
			{
				break;
			}
			a+=(j+1);
			b++;
		}
		cout<<b;
		return 0;
	}
	if(z)
	{
		int b = 1;
		long long a = 0;
		for(int j = 0;j*2<=n;j++)
		{
			if(a+(j+1)*zz>m) 
			{
				break;
			}
			a+=(j+1)*zz;
			b++;
			if(a+(j+1)*zz>m) 
			{
				break;
			}
			a+=(j+1)*zz;
			b++;
		}
		cout<<b;
		return 0;
	}
	sort(ar,ar+n);
	cout<<bi();
	return 0;
}
