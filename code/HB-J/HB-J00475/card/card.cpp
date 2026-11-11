#include<bits/stdc++.h>
using namespace std;
int a[500005];
int s[500005],h=0;
int ans[500005];
int v[500005];
int f(int k)
{
	for(int i=1;i<=h;i++)
	{
		if(s[i]==k)
		{
			return i;
		}
	}
	return -1;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		h=0;
		memset(s,0,sizeof(s));
		memset(v,0,sizeof(v));
		for(int j=i;j<=n;j++)
		{
			if(v[a[j]]==0)
			{
				h++;
				s[h]=a[j];
				v[a[j]]=1;
			}
			else
			{
				int p=f(a[j]);
				for(int k=h;k>p;k--)
				{
					v[s[k]]--;
				}
				h=p;
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(v[j]==1)
			{
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d ",ans[i]);
	}
	return 0;
}
