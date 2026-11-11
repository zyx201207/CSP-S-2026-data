#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,dir=0,asd=0;
	cin>>n>>m;
	long long a[n],b[m]={},d[n]={};
	bool c[m+1]={};
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(c[a[j]-1]==true)
			{
				for(int v=0;v<n;v++)
				{
					if(d[v]==a[j])
					{
						dir=v;
					}
				}
				for(int v=dir;v<=asd;v++)
				{
					c[d[v]-1]=false;
					d[v]=0;
				}
				asd=dir;
			}
			d[asd]=a[j];
			asd++;
			c[a[j]-1]=true;
		}
		for(int j=0;j<m;j++)
		{
			if(c[j]==true)
			{
				b[j]++;
			}
		}
		for(int j=0;j<n;j++)
		{
			c[j]=false;
			d[j]=0;
		}
		asd=0;
		dir=0;
	}
	for(int i=0;i<m;i++) cout<<b[i]<<" ";
	return 0;
}
