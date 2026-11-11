#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int c[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int d[500005]={0};
	for(int i=1;i<=n;i++)
	{
		bool f[500005]={0},fl[500005]={0};
		for(int j=i;j<=n;j++)
		{
			d[j-i+1]=a[j];
			bool flag=false;
			for(int k=1;k<=j-i;k++)
			{
				if(f[k]==0&&d[k]==a[j])
				{
					flag=true;
					f[k]=true;
				}
				if(flag)
				{
					f[k]=true;
				}
			}
		}
		for(int j=1;j<=n-i+1;j++)
		{
			if(f[j]==0&&fl[d[j]]==0)
			{
				c[d[j]]++;
				fl[d[j]]=1;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
