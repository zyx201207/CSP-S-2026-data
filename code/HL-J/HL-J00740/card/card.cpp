#include<bits/stdc++.h>
using namespace std;
int t[100];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a[100000];
	int n,m;
	cin>>n>>m;
	int c;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
		while(c>=1)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[i]==a[j])
				{
					for(int x=a[i];x<a[j];x++)
					{
						a[x]=0;
						
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;i++)
			if(a[i]==j)
			{
				t[j]++;
			}
		}
		c--;
		
	}
	for(int i=1;i<=n;i++)
	{
		cout<<t[i];
	}
	return 0;
}