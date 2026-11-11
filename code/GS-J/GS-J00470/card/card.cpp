#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n],b[m];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<m;i++)
	{
		b[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		long long c[n];
		for(int j=0;j<n;j++)
		{
			c[j]=0;
		}
	 	for(int j=i;j<n;j++)
	 	{
	 		for(int l=0;l<n;l++)
	 		{
	 			if(a[j]==c[l])
	 			{
	 				for(int f=l;f<n;f++)
	 				{
	 					c[f]=0;
					}
				}
			}
			c[j-i]=a[j];
		}
		
		
		for(int j=0;j<n;j++)
		{
			for(int l=0;l<m;l++)
			{
				if(c[j]==l+1)
				{
					b[l]=b[l]+1;
				}
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
 } 
