#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],p[300005],j[500005],y[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int t=1;t<=n;t++)
	{
		p[t]=a[t];
		for(int i=t+1;i<=n;i++)
		{
			p[i]=a[i];
			for(int j=1;j<=i;j++)
			{
				if(p[j!=0]){
					if(p[i]==p[j])
					{
						for(int l=j+1;l<=i;l++)
						{
							p[l]=0;
						}
					}
				}
			}
		}
		for(int i=1;i<=m+1;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(p[j]!=0)
				{
					if(p[j]==i)
					{
						y[i]++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			p[i]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<y[i]<<" ";
	}
	return 0; 
}
