#include<bits/stdc++.h>
using namespace std;
int a[5];
int b[5];
int c[5];
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
	while(1)
	{
		for(int i=1;i<=n;i++)
		{
			b[i]=a[i];
			for(int j=1;j<=n;j++)
			{
				if(b[i]==b[j]&&i!=i)
				{
					for(int l=j;l<=i;l++)
					{
						b[i]=0;
					}
				}
			}	
		}
		for(int i=1;i<=n;i++)
		{
			if(b[i]==1)
			{
				c[1]++;
			}
			if(b[i]==2)
			{
				c[2]++;
			}
		}
	}
	return 0;
} 
