#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxx=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j)
				{
					continue;
				}
				maxx=max(maxx,(a[i]&a[j]));
			}
		}
		cout<<maxx;
		return 0;
	}
	else if(m==3)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int k=1;k<=n;k++)
				{
					if(i==j||i==k||j==k)
					{
						continue;
					}
					maxx=max(maxx,(a[i]&a[j]&a[k]));
				}
				
			}
		}
		cout<<maxx;
		return 0;
	}
	else if(m==4)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int k=1;k<=n;k++)
				{
					for(int z=1;z<=n;z++)
					{
						if(i==j||i==k||j==k||i==z||j==z||k==z)
						{
							continue;
						}
						maxx=max(maxx,(a[i]&a[j]&a[k]&a[z]));
					}
					
				}
				
			}
		}
		cout<<maxx;
		return 0;
	}
	else if(m==5)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int k=1;k<=n;k++)
				{
					for(int z=1;z<=n;z++)
					{
						for(int l=1;l<=n;l++)
						{
							if(i==j||i==k||j==k||i==z||j==z||k==z||i==j||j==l||z==l)
							{
								continue;
							}
							maxx=max(maxx,(a[i]&a[j]&a[k]&a[z]&a[l]));
						}
					}
				}
			}
		}
		cout<<maxx;
		return 0;
	}
	else if(m==1)
	{
		cout<<(a[1]&a[1]);
	}
	else{
		cout<<1000000;
	}
	return 0;
}
