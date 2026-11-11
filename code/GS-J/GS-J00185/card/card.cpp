#include<bits/stdc++.h>
using namespace std;
int n,m,a[999],b[999];//aÅÆÖÖb×ÀÉÏÅÆ 

bool bo(int s)
{
	for(int i=1;i<=n;i++)
	{
		if(s==b[i])
		return 0;
	}
	return 1;
}
int o(int s)
{
	for(int i=1;i<=n;i++)
	{
		if(s==b[i])
		return i;
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.ans","w",stdout);
	
	cin>>n>>m;
	int c[m+1];//cÅÆÊý 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(bo(a[j]))
			{
				b[j]=a[j];
			}
			else
			{
				int y=o(a[j]);
				for(int p=y+1;p<=n;p++)
				{
					b[p]=0;
				}
			}
		}
		for(int w=i;w<=n;w++)
		{
			for(int j=1;j<=m;j++)
			{
				if(b[w]==j)
				{
					c[j]++;
				}
			}
		}
	cout<<endl;
			for(int i=1;i<=n;i++)
	 		{
				b[i]=0;
			}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
}
