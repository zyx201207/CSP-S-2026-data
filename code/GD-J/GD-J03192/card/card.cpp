#include <iostream>
using namespace std;
int n,m,a[100000],b[10000],c[10000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		c[i]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int i=1;i<=n;i++)
	    {
		    a[i]=c[i];
	    }
		for(int j=i;j<=n;j++)
		{
			b[a[j]]++;
		}
		for(int j=i;j<=n;j++)
		{
			
			for(int v=i;v<j;v++)
			{
				if(a[j]==a[v])
				{
					for(int s=v;s<=j-1;s++)
					{
						b[a[s]]--;
						a[s]=0;
					}
				}
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
 } 
