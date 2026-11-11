#include <bits/stdc++.h>
using namespace std;
int main()
{
	preopen("crystal.in","r",stdin);
	preopen("crystal.out","w",stdout);
	int su=1;
	long long m,n; 
	cin>>n>>m;
	long long a[n],l=n/2,um=0,k=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(i==l)
		{
			um=a[i];
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
			if(a[j]<a[j-1])
			{
				swap(a[j],a[j-1]);
			}
		}
	}
	long long  b[n-1],j=0;
	for(int i=0;i<n-1;i++)
	{
		b[i]=a[i+1]-a[i];
		if(i>0)
		{
			if(b[i]=b[i-1])
			{
				j+=1;
			}
		}
	}
	if(j==n-1)
	{
		long long o=b[1],q=b[0],h=0;
		int u=1;
		while(u==1)
		{
			h+=o;
			if(h>=m)
			{
				break;
			}
			else
			{
				o+=q;
				su+=1;
			}
		}
	} 
	else
	{
		for(int i=l-1;i>=0;i--)
	{
		k=a[l]-a[i]+k;
		if(k<=m)
		{	su+=1;
			continue;
		}
		else
		{
			break;
		}
	}
	for(int i=n-1;i>l;i--)
	{
		if(a[i]==a[l])
		{
			su+=1;
		}
	}
	}
	cout<<su<<endl;
	return 0;
}
