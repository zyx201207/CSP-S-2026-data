#include <bits/stdc++.h>
using namespace std;
char c[1000000];
int a[1000000];
int main()
{
	freopen("string.in","r",stdin)
	freopen("string.out","w",stdout)
	int n,x=0,y=0,z=0,l=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
		y=y+c[i];
	}
	
	if(n%2!=0)
	{
		l=1;
	}
	for(int i=0;i<n%2+l;i++)
	{
		if(n%2!=0&&i==n/2+1)
		{
			x=x;
		}
		else
		{
			if(c[i]!=c[n-i-1])
			{
				if(c[i]>c[n-i-1])
				{
					x=x+c[n-1-i];
					z=c[i]-c[n-i-1];
					c[n-2-i]=c[n-2-i]-z;
				}
				else if(c[i]==c[n-i-1])
				{
					x=x+c[n-1-i];
					z=0;
				}
				else
				{
					x=x+c[i];
					z=c[n-i-1]-c[i];
					c[i+1]=c[i+1]-z;
				}
			}
		}
			
	}
	cout<<x;
	return 0;
	
	
	
}
