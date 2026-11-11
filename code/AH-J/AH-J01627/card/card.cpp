#include<bits/stdc++.h>
int n,m,a[100001],b[100001],q[100001];
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=n;i>=1;i--)
	{
		cin>>a[i];
	}
	while(n>0)
	{
		for(int i=n;i>=1;i--)
		{
			for(int j=1;j<=n;j++)
			{
				if(b[j]==a[i])
				{
					for(int k=j;k<=n;k++)
					{
						b[k]=0;
					}
					b[j]=a[i];
					
				}
				else
				{
					b[j]=a[i];
				}
			}
		}
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(b[j]==i)
				{
					q[i]++;
					break;
				}
				
			}
		}
		for(int i=1;i<=n;i++)
		{
			b[i]=0;
		}
		n--;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<q[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
