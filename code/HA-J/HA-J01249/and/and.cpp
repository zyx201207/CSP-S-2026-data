#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],x,mi,b[200005],c,ma,k,y=1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n,m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		x=1;
		while(a[i]=1)
		{
			c=c*10+a[i]%2;
			a[i]/=2;
			x++;
		}
		c=c*10+1;
		for(int j=x;j>=1;j--)
		{
			b[i]=b[i]*10+c%10;
			c/=10;
		}	
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(b[i]+b[j]>ma)
			{
				ma=b[i]+b[j];
			}
		}
	}
	while(ma==0)
	{
		if(ma%10==2)
		{
			for(int i=1;i<=k;k++)
			{
				y*=2;
			}
			mi+=y;
		}
		k++;
		y=0;
	}
	cout<<mi;
	return 0;
}
