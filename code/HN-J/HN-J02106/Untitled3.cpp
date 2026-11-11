#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int n,m,x[100000000010],w[100000000010];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	for(int k=1;k<=n;k++)
	{
		int y[100000000010],z[100000000010];
		for(int j=1;j<=n;j++)
		{
			int o;
			o=x[j];
			y[j]=o;
			z[j]=o;
		}	
		for(int a=2;a<=n;a++)
		{
			for(int b=1;b<=a;b++)
			{
				if(x[a]==y[b])
				{
					for(int c=a-1;c>=1;c--)
					{
						z[c]=0;
					}
				}
			}
		}
		for(int s=1;s<=n;s++)
		{
			for(int p=1;p<=m;p++)
			{
				for(int q=1;q<=n;q++)
				{
					if(z[q]==p)
					{
						w[p]++;
					}
				}
			}
		}
	}
	for(int u=1;u<=m;u++)
	{
		cout<<w[u]<<" ";
	}
	return 0;
}
