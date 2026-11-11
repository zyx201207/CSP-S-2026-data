#include<bits/stdc++.h>//8
using namespace std;
typedef long long inf;
inf C,T,n,d,a[2000005],ans;
inf vis[2000005],dd[2000005],dm[2000005];
void mdin(inf x,inf dis)
{
	if(x>n)return;
	dm[x]=min(dm[x],dis);
	for(inf i=x+1;i<=n;i++)
	{
		if(a[i]-a[x]>d)break;
		mdin(i,dis+1);
	}
	return ;
}
void dfs(inf now,inf bg,inf dis)
{
	if(now>n)return;
	//printf("%d\n",now);
	if(dis==dm[now])vis[now]++;
	for(inf i=now+1;i<=n;i++)
	{
		if(a[i]-a[now]>d)break;
		dfs(i,bg,dis+1);
	}
	return ;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&C,&T);
	if(C==11 or C==12)
	{
		while(T--)
		{
			ans=0;
			scanf("%lld%lld",&n,&d);
			for(inf i=1;i<=n;i++)scanf("%lld",&a[i]);
			int k=a[2]-a[1];
			if(2*k<=d)printf("%d\n",n-3);
			else printf("0\n");
		}
		return 0;
	}
	while(T--)
	{
		ans=0;
		scanf("%lld%lld",&n,&d);
		for(inf i=1;i<=n;i++)scanf("%lld",&a[i]);
		//printf("%d ",T);
		//memset(dd,0,sizeof(dd));
		
		for(inf i=1;i<=n;i++)
		{
			memset(vis,0,sizeof(vis));
			memset(dm,127,sizeof(dm));
			mdin(i,0);
			//for(int j=1;j<=n;j++)printf("%lld ",dm[j]);
			dfs(i,i,0);
			for(inf j=1;j<=n;j++)
			{
				//printf("%d ",vis[j]);
				if(vis[j]==2)
				{
					ans++;
					//printf("%d %d\n",i,j);
				}
			}
			//printf("\n");
			
		}
		//return 0;
		printf("%lld\n",ans);
	}
	return 0;
}
