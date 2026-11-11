#include<bits/stdc++.h>
using namespace std;
int a[300005],aa[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,f=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>aa[i];
		a[aa[i]]=i;
		if(aa[i]<aa[i-1]) f=0;
	}
	if(f==1)
	{
		for(int i=1;i<=m;i++)
		{
			cout<<a[i]<<' ';
		}
	}
	else
	{
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)
		{
			int b[300005]={0};
			for(int j=i;j<=n;j++)
			{
				if(b[aa[j]]==0) b[aa[j]]=j;
				else
				{
					for(int k=b[aa[j]];k<j;k++)
					{
						b[aa[k]]=0;
					}
					b[aa[j]]=j;
				}
			}
			for(int j=1;j<=m;j++)
			{
				if(b[j]!=0) a[j]++;
			}
		}
		for(int i=1;i<=m;i++)
		{
			cout<<a[i]<<' ';
		}
	}
	return 0;
}
