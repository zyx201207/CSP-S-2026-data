#include<bits/stdc++.h>
using namespace std;//&
int n,m,k=(2<<31)-1;
long long a[200020];
int b[200020][31],c[31],d[200020];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	/*
	int o,p=a[n];
	for(o=0;p>1;p/=2)
	{
		o++;
	} 
	for(int i=o;i>0;i--)
	{
		for(int j=n;j>0;j--)
		{
			if((a[j]>>(i-1)-(a[j]>>i)<<1)==1)
			{
				b[j][i]++;
				c[i]++;
			}
		}
		if(c[i]>=m)
		{
			for(int j=n;j>0;j--)
			{
				if((a[j]>>(i-1)-(a[j]>>i)<<1)!=1)
				{
					a[j]=0;
				}
			}
		}
	}
	*/
	for(int i=0;i<m;i++)
	{
		for(int j=n;j>n-m;j--)
		{
			k=k&a[j];
		}
	 } 
	 cout<<k;
	return 0;
}
