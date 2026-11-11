#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],c[500005],t=1;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i+1]) t=0;
	}
	if(n<=500)
	{
		for(int i=1;i<=n;i++)
		{
			int cnt=0;
			for(int i=1;i<=n;i++) b[i]=0;
			for(int j=i;j<=n;j++)
			{
				int k=1,d=0;
				for(int v=1;v<=cnt;v++)
				{
					if(b[v]==a[j]) 
					{
						k=0;
						d=v;
						break;
					}
				}
				if(k==1) 
				{
					cnt++;
					b[cnt]=a[j];
				}
				else
				{
					int cnt1=cnt;
					for(int v=d;v<=cnt;v++)
					{
						cnt1--;
						b[v]=0;
					}
					cnt=cnt1;
					cnt++;
					b[cnt]=a[j];
				}
			}
			for(int j=1;j<=cnt;j++) c[b[j]]++;
		}
		for(int i=1;i<=m;i++) cout<<c[i]<<" ";
	}
	else if(t==1)
	{
		for(int i=1;i<=n;i++)
		{
			int cnt=0;
			for(int i=1;i<=n;i++) b[i]=0;
			for(int j=i;j<=n;j++)
			{
				if(b[cnt]!=a[j])
				{
					cnt++;
					b[cnt]=a[j];
				}
			}
			for(int j=1;j<=cnt;j++) c[b[j]]++;
		}
		for(int i=1;i<=m;i++) cout<<c[i]<<" ";
	}
	return 0;
}
