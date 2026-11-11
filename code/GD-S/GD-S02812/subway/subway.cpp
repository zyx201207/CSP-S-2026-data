#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long c,n,m,d,q;
long long w[N];
long long fa[N][30],fb[N],fc[N][30];
long long ans=0x3f3f3f3f;
void dfs(long long now,long long node,long long cost)
{
	if(now==node)
	{
		ans=min(ans,cost);
		return ;
	}
	long long co=cost;
	for(long long i=1;i<=fb[now];i++)
	{
		cost=co+fc[now][i];
		dfs(fa[now][i],node,cost);
	}
	return ;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++)
	{
		long long k;
		cin>>k;
		long long x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		fb[x1]++;
		fb[x2]++;
		fa[x1][fb[x1]]=x2;
		fa[x2][fb[x2]]=x1;
		fc[x1][fb[x1]]=y1+y2;
	}
	while(q--)
	{
		long long p1,p2;
		cin>>p1>>p2;
		dfs(p1,p2,w[p1]+w[p2]);
		cout<<ans<<endl;
		ans=0x3f3f3f3f;
	}
	return 0;
}
