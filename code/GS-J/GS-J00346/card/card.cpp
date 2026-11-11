#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,m;
	cin>>n>>m;
	int a[10005],c[10005];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int b[10005];
		for(int j=1;j<=n-i+1;j++)
		{
			a[j]=b[j];
			for(int q=1;q<j;q++)
			{
				if(a[j]==b[q])
				{
					for(int w=q;w<=j-1;w++)
					{
						b[w]=0;
					}
				}
			}
		}
		for(int e=1;e<=n-i+1;e++)
		{
			for(int r=1;r<=m;r++)
			{
				if(b[e]==r)
				{
					c[r]+=1;
				}
			}
		}
		for(int i=1;i<=m;i++)
	    {
	    	cout<<c[i]<<" ";
		}
	}
}
