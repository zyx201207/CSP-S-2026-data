#include<bits/stdc++.h>
using namespace std;
long long a[2000010];
long long ans,n,d;
void dfs(int x,int y)
{
	if(x>=y)return ;
	int l=x+1,r=y;
	int id=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(a[mid]-a[x]<=d)
		{
			id=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	if(id==0)
	{
		ans=LONG_LONG_MAX;
		return ;
	}
	ans++;
	dfs(id,y);
}
int asdf;
void dfs1(int x,int y,int step)
{
	if(step>ans)return ;
	if(x==y)
	{
		if(step==ans)asdf++;
		return ;
	}
	for(int i=x+1;i<=y;i++)
	{
		if(a[i]-a[x]<=d)
		{
			dfs1(i,y,step+1);
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	scanf("%lld%lld",&c,&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		int ret=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=n;j>=i;j--)
			{
				if(a[j]-a[i]<=d)break;
				ans=0;
				asdf=0;
				dfs(i,j);
				dfs1(i,j,0);
				if(asdf==2)
				{
					ret++;
				}
			}
		}
		printf("%lld\n",ret);
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
