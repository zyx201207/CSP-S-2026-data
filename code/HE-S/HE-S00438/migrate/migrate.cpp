#include<bits/stdc++.h>
using namespace std;
int main()
{
	feropen("migraet.in","r",stdin);
	feropen("migraet.out","w",stdout);
	int n,d;
	cin>>n>>d;
	int x[2000005];
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	int u,v,z=0;
	for(int i=1;i<=n;i++)
	{
		u=x[i];
		for(int j=3;j<=n;j++)
		{
			v=x[j];
			int b=10000000,c=0;
			while(u<v)
			{
				int a;
				if(x[u]>=x[v])
				{
					a=x[u]-x[v];
				} 
				else
				{
					a=x[v]-x[u];
				}
				if(a<b)
				{
					b=a;
					c=0;
				}
				else if(a==b)
				{
					c++;
				}
				u++
			}
			if(c=1)
			{
				z++;
			}
		}
	}
	cout<<z;
	return 0;
 } 
