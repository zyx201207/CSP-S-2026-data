#include<bits/stdc++.h>
#define ll long long

using namespace std;
const int INF=1e9;
const int N=1e6+10;

int c,t;
int n,k;
int u[N],v[N];
vector<int>a[N];
int dep[N];
int fa1[N];

void dfs(int u,int fa)
{
	for(int i=0;i<a[u].size();++i)
	{
		if(a[u][i]!=fa)
		{
			dep[a[u][i]]=dep[u]+1;
			fa1[a[u][i]]=u;
			dfs(a[u][i],u);
		}
	}
}

void lca(int u,int v)
{
	
}

void solve()
{
	dep[1]=0;
	dfs(1,0);
	int mmax=0;
	for(int i=1;i<=n;++i)
	{
		mmax=max(mmax,dep[i]);
	}
	int deepest=0;
	for(int i=1;i<=n;++i)
	{
		if(mmax==dep[i])
		{
			deepest=i;
			break;
		}
	}
	dep[deepest]=0;
	dfs(deepest,0);
	mmax=0;
	for(int i=1;i<=n;++i)
	{
		mmax=max(mmax,dep[i]);
	}
	deepest=0;
	for(int i=1;i<=n;++i)
	{
		if(mmax==dep[i])
		{
			deepest=i;
			break;
		}
	}
	int now=deepest;
	for(int i=1;i<=mmax/2;++i)
	{
		now=fa1[now];
	}
	dep[now]=0;
	dfs(now,0);
	mmax=0;
	for(int i=1;i<=n;++i)
	{
		mmax=max(mmax,dep[i]);
	}
	printf("%d\n",mmax);
}

void solvea()
{
	printf("%d\n",(n-2*k)/8+2);
}
void input()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)a[i].clear();
	for(int i=1;i<=n-1;++i)
	{
		scanf("%d%d",&u[i],&v[i]);
		a[u[i]].push_back(v[i]);
		a[v[i]].push_back(u[i]);
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	if(13<=c&&c<=14)
	{
		while(t--)
		{
			input();
			solvea();
		}
	}
	else
	{
		while(t--)
		{
			input();
			solve();
		}
	}
}

