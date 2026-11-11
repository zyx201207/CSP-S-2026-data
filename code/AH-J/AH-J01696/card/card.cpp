#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int b[1000010];
int c[1000010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);	
	int n;
	int m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		a[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=n;i++)
	{
		int number=0;
		for(int j=i;j<=n;j++)
		{
			bool pd=true;
			for(int k=1;k<=number;k++)
			{
				if(b[j]==c[k])pd=false;
			}
			if(pd||(pd==false&&number==0))
			{
				number++;
				c[number]=b[j];
			}
			else
			{
				for(int k=1;k<=number;k++)
					c[k]=0;
				number=1;
				c[1]=b[j];
			}
		}
		for(int t=1;t<=m;t++)
		for(int j=1;j<=number;j++)
		{
			if(c[j]==t)a[t]++;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<a[i]<<' ';
	return 0;
}
