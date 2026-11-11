#include<bits/stdc++.h>
using namespace std;
int a[500000];
int b[500000];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,temp,x,y,z,c;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int j=1;j<=n;j++)
	{
		for(int i=1;i<n;i++)
		{
			if(a[i]>a[i+1])
			{
				temp=a[i+1];
				a[i+1]=a[i];
				a[i]=temp;
			}
		}
	
	}

	for(int i=1;i<n;i++)
	{
		b[i]=a[i+1]-a[i];
	}

	y=0,x=0;
	for(int i=1;i<n;i++)
	{

		if(b[i]<=m && i<n)
		{
			x=2;
		}
		z=1;
		c=b[i];
		while(c+b[i+z]*(z+1)<=m && i+z<n)
		{
			if(c+b[i+z]*(z+1)<=m && i+z<n)
				{
					x++;
				}
			c=c+b[i+z]*(z+1);
			z++;
		}
		
		
		if(x>y)
		{
			y=x;
		}
	}
cout<<y;
	
	
	return 0;
}
