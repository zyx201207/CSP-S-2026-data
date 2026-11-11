#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int dep[N];
bool vis[N];
int ans[N];
vector<int> g[N];
int lim;
int mx[N];
int sum[N];
int dfn[N],out[N];
int rnk[N];
int dcnt;
bool stk[N];
int w[N];
int n,k;
int p,q;
void solve(int u,int fa)
{
	dep[u]=dep[fa]+1;
	mx[u]=dep[u]; 
	for(auto v:g[u])
	{
		if(v==fa||stk[v]||dfn[v]<p||dfn[v]>q) continue;
		solve(v,u);
		mx[u]=max(mx[u],mx[v]);
		sum[u]=sum[u]+sum[v];
		vis[u]|=vis[v];
	}
	if(mx[u]-dep[u]>=lim)
	{
		vis[u]=1;
	}
	if(vis[u]) sum[u]++;
}
void dfs_init(int u,int fa)
{
//	printf("%d\n",u);
	dfn[u]=++dcnt;
	rnk[dcnt]=u;
	stk[u]=1;
	for(auto v:g[u])
	{
		if(v==fa) continue;
		dfs_init(v,u);
	}
	out[u]=dcnt;
	stk[u]=0;
	w[u]=1e9;
	for(int i=dfn[u];i<=out[u];i++)
	{
		for(int j=dfn[u];j<=out[u];j++) 
		{
			dep[rnk[j]]=0;
			sum[rnk[j]]=vis[rnk[j]]=0;
			mx[rnk[j]]=0;
		 } 
		p=dfn[u],q=out[u];
		int rt=rnk[i];
		
		solve(rt,0);
//		if(lim==1&&u==3) cout<<dfn[u]<<" "<<out[u]<<"!>!\n";
//		if(lim==1&&u==3&&rt==4) cout<<sum[rt]<<"out\n";
		w[u]=min(w[u],sum[rt]);
	}
	
}
void dfs(int u,int fa)
{
//	cout<<u<<"\n";
	dep[u]=dep[fa]+1;
	mx[u]=dep[u]; 
	for(auto v:g[u])
	{
		if(v==fa) continue;
		dfs(v,u);
		mx[u]=max(mx[u],mx[v]);
		sum[u]=sum[u]+sum[v];
		vis[u]|=vis[v];
	}
	if(mx[u]-dep[u]>=lim)
	{
		vis[u]=1;
	}
	if(vis[u]) sum[u]++;
	ans[u]=sum[u];
	int cnt=1;
	int mi=1e9;
	for(auto v:g[u])
	{
		if(v==fa) continue;
		cnt=cnt+sum[v];
		mi=min(mi,min(ans[v],w[v])-sum[v]);
	}
	ans[u]=min(ans[u],cnt+mi);
}
bool check(int mid)
{
	lim=mid;
	for(int rt=1;rt<=n;rt++)
	{
		dcnt=0;
		for(int i=1;i<=n;i++)
		{
			vis[i]=0;
			ans[i]=0;
			dep[i]=0;
			sum[i]=0;
			stk[i]=0;
		}
		dfs_init(rt,0);
		for(int i=1;i<=n;i++)
		{
			vis[i]=0;
			ans[i]=0;
			dep[i]=0;
			sum[i]=0;
		}
		dfs(rt,0);
//		if(mid==1&&rt==2) cout<<rt<<" "<<w[3]<<"!!!\n";
		if(ans[rt]<=k) return 1;
	}
	return 0;
	
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int cc,cas;
	scanf("%d%d",&cc,&cas);
	while(cas--)
	{
//		cout<<"?\n";
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u); 
		}
		int l=1,r=n,best=-1;
		while(l<=r)
		{
			int mid=(l+r)>>1;
//			cout<<mid<<"\n";
			if(check(mid))
			{
				best=mid;
				r=mid-1;
			}	
			else l=mid+1;
		} 
//		cout<<check(1)<<"\n";
		printf("%d\n",best);
	}
}
