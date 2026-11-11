#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[500005],desk[500005],shu[500005],ans[500005];
int pos[500005],cnt;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n*n*n<=200000000)
	{
		for(int i=1;i<=n;i++)
		{
			memset(desk,0,sizeof(desk));
			memset(shu,0,sizeof(shu));
			memset(pos,0,sizeof(pos));
			cnt=0;
			for(int j=i;j<=n;j++)
			{
				if(shu[a[j]])
				{
					for(int k=pos[a[j]];k<=j;k++)
					{
						pos[desk[k]]=0;
						shu[desk[k]]--;
						desk[k]=0;
					}
				}
				desk[++cnt]=a[j];
				pos[a[j]]=cnt;
				shu[a[j]]++;
			}
			for(int j=1;j<=m;j++)
			{
				if(shu[j]>0)ans[j]++;
			}
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(j==i||a[j]!=a[j-1])ans[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
/*
5 3
31 3 1 15 7
*/
