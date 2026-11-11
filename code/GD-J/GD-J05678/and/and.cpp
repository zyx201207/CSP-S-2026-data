#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int a[200005];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}	
	if(m==1)
	{
		int x=a[0];
		for(int i=1;i<n;i++)
		{
			if(a[i]>x)
			{
				x=a[i];
			}
		}
		cout<<x;
	}
	else if(m==2)
	{
		int y=a[0]&a[1];
		
		int z=a[0];
		for(int i=1;i<n;i++)
		{
			if(a[i]>z)
			{
				z=a[i];
			}
		}
		int d=a[0];
		for(int i=1;i<n;i++)
		{
			if(a[i]>d&&a[i]!=z)
			{
				d=a[i];
			}
		}
		int u=d&z;
		cout<<u;
	}
	else
	{		
		int y=a[0]&a[1];		
		int z=a[0];
		for(int i=1;i<n;i++)
		{
			if(a[i]>z)
			{
				z=a[i];
			}
		}
		int d=a[0];
		for(int i=1;i<n;i++)
		{
			if(a[i]>d&&a[i]!=z)
			{
				d=a[i];
			}
		}
		int e=a[0];
		for(int i=1;i<n;i++)
		{
			if(a[i]>e&&a[i]!=z&&a[i]!=d)
			{
				e=a[i];
			}
		}
		int u=d&z&e;
		cout<<u;
	}	
		
	
	return 0;
}
