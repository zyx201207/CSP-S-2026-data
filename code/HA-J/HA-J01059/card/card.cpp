#include<bits/stdc++.h>
using namespace std;
int main()
{
	openfile("card.in");
	int n,m,a[500001],i,i1,j1=1,b[300001]={0};
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=n;i++)
	{
		int c[300002]={0};
		i1=i;
		for(int j=i;j<=n;j++)
		{
			c[j1]=a[i1];
			for(int k=1;k<=j1;k++)
			{
				if(c[k]==c[j1])
				{
					for(int l=k+1;l<=j1;l++)
					{
						c[l]=0;
					}
					j1=k;
					break;
				}
			}
			i1++;j1++;
		}
		for(int h=1;h<=m;h++)
		{
			for(int g=1;g<=j1-1;g++)
			{
				if(c[g]==h)
				{
					b[h]++;
					break;
				}
			}
		}
	}
	for(int h=1;h<=m;h++)
	{
		cout<<b[h]<<' ';
	}
	putfile("card.out");
	return 0;
}
