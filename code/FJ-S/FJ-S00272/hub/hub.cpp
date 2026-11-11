#include <bits/stdc++.h>
#define fr(x)\
	freopen(#x".in","r",stdin);\
	freopen(#x".out","w",stdout);

using std::cin;
typedef long long ll;
constexpr int N=2e6;
int C,n,k;
std::vector<int> e[N];
int deg[N],dis[N];
int del,ans;

int mid;

int dfs(int u,int f)
{
	// fprintf(stderr,"%d\n",u);
	std::vector<int> res;
	for(int v:e[u])if(v!=f)
	{
		int r=dfs(v,u);
		if(r!=-1)res.push_back(r);
		del=std::max(del,r);
	}
	if(dis[u]>=mid)return 0;
	if(res.size()>1)return 0;
	if(res.size()==1)return res[0]+1;
	ans--;
	return -1;
}

bool check(int x) // to check whether delete height<x is ok
{
	int s=-1;
	for(int i=1;i<=n;i++)if(dis[i]>=x)s=i;
	if(s==-1)return true;
	del=0,ans=n;
	dfs(s,0);
	// if(x==1)fprintf(stderr,"!!!%d\n",del);
	return ans-del<=k;
}

void Main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)e[i].clear();
	std::fill(deg,deg+n+1,0);
	for(int i=1,u,v;i<n;i++)
	{
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
		deg[u]++,deg[v]++;
		// fprintf(stderr,"%d-%d\n",u,v);
	}
	std::queue<int> Q;
	std::fill(dis,dis+n+1,1e9);
	for(int i=1;i<=n;i++)if(deg[i]==1)deg[i]=0,Q.push(i),dis[i]=0;
	while(!Q.empty())
	{
		int u=Q.front();Q.pop();
		for(int v:e[u])if(deg[v]&&--deg[v]==1)
		{
			deg[v]=0;
			Q.push(v);
			dis[v]=dis[u]+1;
		}
	}
	// for(int i=1;i<=n;i++)fprintf(stderr,"%d:%d\n",i,dis[i]);
	int L=-1,R=n-1;
	while(L+1<R)
	{
		mid=(L+R)>>1;
		// fprintf(stderr,"check %d\n",mid);
		if(check(mid))R=mid;
		else L=mid;
	}
	printf("%d\n",R);
}

int main()
{
	fr(hub)
	cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	cin>>C>>T;
	while(T--)Main();
	return 0;
}
