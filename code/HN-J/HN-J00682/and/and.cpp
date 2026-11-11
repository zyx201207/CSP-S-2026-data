#include<bits/stdc++.h>
using namespace std;
int a[20000005];
int b[20000005];
int c[210000000];
int d[210000000];
int main()
{
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	int m,n,y;
	cin>>n>>m;
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for (int i=0;i<n;i++)
	{

		y=a[i];
		b[i]+=y%2;
		y/=2;
		bool belike=1;
		while (belike)
		{
			b[i]*=10;
			b[i]+=y%2;
			
			y/=2;
			if (y==0)
			{
				belike=0;
			}
		//cout<<b[i]<<' ';
		}
	cout<<b[i]<<' ';	
	}
	 
	int ij=0;
	int amax=-1;
	int x;
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++)
		{
			for (int k=0;k<n;k++)
			{
				if(m==0)
				{
					c[ij]=b[k] && b[j];
					x=c[ij];
					amax=max(amax,x);
				}
				else if(k%2==1)
				{
					d[ij]=c[k] && c[j];
					x=d[ij];
					if (x>amax)
					{
						amax=x;
					}
					for (int l=0;l<n;l++)
					{
						c[l]=d[l];
					 } 
					//cout<<b[ij]<<' ';
				 } 
				else
				{
					c[ij]=d[k] && d[j];
					x=c[ij];
					if (x>amax)
					{
						amax=x;
					}	
					for (int l=0;l<n;l++)
					{
						d[l]=c[l];
					 }
				}
			}
		}
	 } 
	// cout<<x;
	int y1;
	y1=0;
	int z=0;
	while (x>=10)
	{
		y1+=x%10;
		x/10;
	}
	while (y1>=10)
	{
		z+=(y1%10);
		x/10;
		z*=2;
	}
	//cout<<z;
	return 0;
}
