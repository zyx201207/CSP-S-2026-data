#include<bits/stdc++.h>
using namespace std;
const int N=4e3+5;
int c,t,n,k,x,y;
vector<int> v[N];
int fa[N],in[N],dis[N];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void dfs(int x,int fa)
{
	dis[x]=min(dis[x],dis[fa]+1);
	for(auto i:v[x])
		if(i!=fa)dfs(i,x);
}
int check(int id)
{
	for(int i=1;i<=n;i++)fa[i]=i,in[i]=0,dis[i]=0x3f3f3f3f;
	int cnt=0;
	for(int i=1;i<=n;i++)
		if((id>>(i-1))&1)cnt++,in[i]=1,dis[i]=0;
	if(cnt>k)return 0x3f3f3f3f;
	for(int i=1;i<=n;i++)
		if(in[i])
		{
			for(auto j:v[i])
				if(in[j])fa[find(i)]=find(j);
		}
	cnt=0;
	for(int i=1;i<=n;i++)
		if(in[i]&&fa[i]==i)cnt++;
	if(cnt>2)return 0x3f3f3f3f;
	for(int i=1;i<=n;i++)
		if(in[i])dfs(i,i);
	cnt=0;
	for(int i=1;i<=n;i++)
		cnt=max(cnt,dis[i]);
	return cnt;
}
void solve()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)v[i].clear();
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int ans=0x3f3f3f3f;
	for(int i=1;i<(1<<n);i++)
		ans=min(ans,check(i));
	printf("%d\n",ans);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)solve();
	return 0;
}
