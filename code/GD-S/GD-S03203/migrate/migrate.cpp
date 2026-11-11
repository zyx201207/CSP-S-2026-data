#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define int long long
#define abs(x) ((x)<0?-(x):(x))
using namespace std;
int c,t,n,d,x[2000001],cnt[2000001],mind,vis[2000001],id=1,ans=0;
void dfs(int p,int t,int dis)
{
	if(dis>mind)return;
	if(p==t){
		cnt[dis]++,mind=min(mind,dis);
		return;
	}
	int r=min(upper_bound(x+1,x+n+1,x[p]+d)-x-1,t);
	for(int i=r;i>p&&abs(x[p]-x[i])<=d;i--)dfs(i,t,dis+1);
	return;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--)
	{
		ans=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",x+i);
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++,id++)
			{
				memset(cnt,0,(n+1)*sizeof(int)),mind=2000000;
				dfs(i,j,0);
				if(cnt[mind]==2)ans++;
			}
		printf("%lld\n",ans);
	}
	return 0;
}
