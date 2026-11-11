#include<bits/stdc++.h>
using namespace std;
long long a[200200];
char c[200200];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long ai;
		char ci;
		cin>>ai>>ci;
		a[i]=ai;
		c[i]=ci;
	}
	long long sum=0;
	int i=1,j=n,x=0,y=0;
	while(i<j)
	{
		if(c[i]!=c[j])
		{
			if((a[i]-x)>(a[j]-y))
			{
				int t=a[j]-y;
				x+=t;
				sum+=t;
				j--;
				y=0;			
			}
			else if((a[i]-x)<(a[j]-y))
			{
				int t=a[i]-x;
				y+=t;
				sum+=t;
				i++;
				x=0;
			}
			else
			{
				sum=sum-x+a[i];
				i++;
				x=0;
				j--;
				y=0;
			}
		}
		else
		{
			if((a[i]-x)>(a[j]-y))
			{
				x=x-y+a[j];
				j--;
				y=0;
			}
			else
			{
				y=y-x+a[i];
				i++;
				x=0;
			}
		}
	}
	cout<<sum;
	return 0;
}
