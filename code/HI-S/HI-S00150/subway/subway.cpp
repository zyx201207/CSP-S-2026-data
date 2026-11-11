#include<bits/stdc++.h>
using namespace std;
int c=0,n=0,m=0,d=0,q=0;
long long w[500005];
struct Node
{
	int xian;
	int zhan[10];
	long long time[10];
	int zz;
};
Node a[500005];
bool u[500005];
long long sum=0;
void dfs(int x,int y,long long ans)
{
	if(x==y)
	{
		sum=min(sum,ans);
		return ;
	}
	bool r=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<a[i].zz;j++)
		{
			if(a[i].zhan[j]==y && !u[ a[i].zhan[j] ] )
			{
				r=1;
				u[ a[i].zhan[j] ]=1;
				if(j==0)
				{
					ans=ans+a[i].time[j];
					dfs(x,a[i].zhan[j+1],ans);
					u[ a[i].zhan[j] ]=0;
					dfs(x,a[i].zhan[j],ans);
				}
				else
				{
					ans=ans+a[i].time[j];
					dfs(x,a[i].zhan[j-1],ans);
					u[a[i].zhan[j] ]=0;
					dfs(x,a[i].zhan[j],ans);
				}
			}
		}
	}
	if(!r)
	{
		return ;
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=0;i<m;i++)
	{
		scanf("%lld",&w[i]);
	}
	for(int i=0;i<n;i++)
	{
		a[i].xian=i;
		scanf("%d",&a[i].zz);
		for(int j=0;j<a[i].zz;j++)
		{
			scanf("%d %lld",&a[i].zhan[j],&a[i].time[j]);
		}
	}
	for(int i=0;i<q;i++)
	{
		int x=0,y=0;
		scanf("%d %d",&x,&y);
		x=x-1;
		y=y-1;
		dfs(x,y,0);
		printf("%lld\n",sum);
		sum=0;
	}
	return 0;
}
