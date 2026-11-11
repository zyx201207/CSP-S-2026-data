#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],c[500005];
int u[300005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	c[1]=1;
	for(int i=1;i<=n;i++)
	{
		for(int o=1;o<=n;o++)
		{
			b[o]=0;
			u[o]=0;
		}
		for(int j=i;j<=n;j++)
		{
			u[j]=a[j];
			if(b[a[j]]==0)
			{
				b[a[j]]=1;
			}
			else
			{
				for(int k=j;k<n;k++)
				{
					b[a[k]]=0;
					u[k]=0;
				}
			}
			
		}
		for(int k=i;k<=n;k++)
			{
				if(b[a[k]]==1)
				{
					c[a[k]]++;
				}
			}
		
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
