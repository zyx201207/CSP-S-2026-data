#include <bits/stdc++.h>
using namespace std; 
int main()
{
	fropen("cardin","r","stdin");
	fropen("cardout","w","stdout"); 
	int n,m,a[10005],b[10005],c[100005],v=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		c[i]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		v++;
		for(int j=v;j<=n;j++)
		{
			for(int k=i;k<=j;k++)
			{
				if(c[i]==c[j])
				{
					for(int w=i;w<=j;i++)
					{
						c[w]==0;
					}
				}
			}
		}
	}
	cout<<c[n];
}
