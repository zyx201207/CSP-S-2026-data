#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1],b[m+1],c[n+1];
	for(int i=1;i<=m;i++)
	{
		b[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		c[i]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{	
			c[j]=a[j];
		}
		int head=i,wb=n;
		for(int j=1;j<=n;j++)
		{
			bool iop=true;
			for(int k=i;k<=wb;k++){
			
				if(c[k]==a[j])
				{
					wb=k;
					c[wb]=a[j];
					iop=false;
					break;
				}
				
			}
			if(iop==false)
			{
				continue;
			}
			else
			{
				c[++wb]=a[j];
			}
		}
		for(int j=i;j<=wb;j++)
		{
			b[c[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
}
