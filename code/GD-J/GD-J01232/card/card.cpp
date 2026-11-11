#include <iostream>
#include <algorithm>
using namespace std;
int a[500001],b[300001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
	}
	while(n--)
	{
		for(int i=1;i<=n;i++)
		{
			a[i]=a[i+1];
		}
		int c[500001];
		for(int i=1;i<=n;i++)
		{
			c[i]=a[i];
			for(int j=1;j<=i;j++)
			{
				if(c[i]==c[j])
				{
					c[j]=c[i];
					for(int t=j;t<=n;t++)
					{
						c[i]=0;
					}
					break;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(c[i]==j)
				{
					b[i]++;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<b[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
