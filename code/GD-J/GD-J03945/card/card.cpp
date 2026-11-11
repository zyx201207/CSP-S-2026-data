#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+5]={0},b[n+5]={0},cnt[n+5]={0};
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	bool flag=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=2;j<=n;j++)
		{
			for(int k=1;k<j;k++)
			{
				if(a[j]==b[k])
				{
					for(int c=k;c<=j;c++)
					{
						b[i]=0;
					}
				}
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(b[j]==1)
			{
				cnt[b[j]]++;
			}
		}
		for(int i=1;i<=n;i++)
		{
			b[i]=a[i];
		}	
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
	return 0;
}

