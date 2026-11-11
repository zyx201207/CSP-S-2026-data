#include<bits/stdc++.h>
using namespace std;
int n;
int a[500005],lst[500005];
int t[500005];
int s[300005],ans[300005];
void update(int x,int d)
{
	while(x<=n)
	{
		t[x]+=d;
		x+=(x&-x);
	}
}
int sum(int x)
{
	int ans=0;
	while(x)
	{
		ans+=t[x];
		x-=(x&-x);
	}
	return ans;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		lst[a[i]]=i;
	}
	if(n>5000)
	{
		for(int i=1;i<=m;i++)
		{
			printf("%d ",lst[a[i]]);
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			t[j]=0;
		}
		for(int j=1;j<=m;j++)
		{
			s[j]=0;
		}
		for(int j=i;j<=n;j++)
		{
			if(!sum(j))
			{
				update(j,1);
				update(lst[a[j]],-1);
			}
		}
		for(int j=i;j<=n;j++)
		{
			if(!sum(j))
			{
				s[a[j]]++;
			}
		}
		for(int j=1;j<=m;j++)
		{
			ans[j]+=s[j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d ",ans[i]);
	}
	return 0;
}
