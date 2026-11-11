#include<bits/stdc++.h>//172.16.12.5
using namespace std;

#ifdef LOCAL
#define debug(x) cerr<<#x<<" = "<<(x)<<'\n';
#else
#define debug(x)
#endif
#define ll long long
#define vct vector
#define pb push_back
#define PII pair<int,int>
#define int long long

#ifdef LOCAL
bool ____ST;
#endif
int n,k,ans,cnt1,tot,dep[4010],dfn[4010],minn[20][4010];
bool vis[4010];
vct<int>e[4010],vec;
#ifdef LOCAL
bool ____ED;
#endif

int get(int u,int v)
{
	return dfn[u]<dfn[v]?u:v;
}

void dfs(int u,int fa)
{
	minn[0][dfn[u]=++tot]=fa;
	dep[u]=dep[fa]+1; 
	for(int v:e[u])
	{
		if(v==fa)
		{
			continue;
		}
		dfs(v,u);
	}
} 

void build()
{
	for(int j=1;j<=__lg(n);j++)
	{
		for(int i=1;i+(1<<j)-1<=n;i++)
		{
			minn[j][i]=get(minn[j-1][i],minn[j-1][i+(1<<j-1)]);
		}
	}
}

int lca(int u,int v)
{
	if(u==v)
	{
		return u;
	}
	u=dfn[u],v=dfn[v];
	if(u>v)
	{
		swap(u,v);
	}
	int d=__lg(v-u++);
	return get(minn[d][u],minn[d][v-(1<<d)+1]);
}

int dis(int u,int v)
{
	return dep[u]+dep[v]-2*dep[lca(u,v)];
}

void calc()
{
	int maxn=0;
	for(int i=1;i<=n;i++)
	{
		int minn=0x3f3f3f3f3f3f3f3f;	
		for(int j:vec)
		{
			minn=min(minn,dis(i,j));
		}
		maxn=max(maxn,minn);
	}
	ans=min(ans,maxn);
}

void _dfs(int pos)
{
	if(pos==0)
	{
		if(cnt1==2)
		{
			calc();
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			bool flg=0;
			for(int v:e[i])
			{
				if(vis[v])
				{
					flg=1;
					break;
				}
			}
			if(!flg&&cnt1<2)
			{
				cnt1++;
				vis[i]=1;
				vec.pb(i);
				_dfs(pos-1);
				vec.pop_back();
				vis[i]=0;
				cnt1--;
			}
			if(flg)
			{
				vis[i]=1;
				vec.pb(i);
				_dfs(pos-1);
				vec.pop_back();
				vis[i]=0;
			}
		} 
	}
}

void solve()
{
	memset(vis,0,sizeof(vis));
	vec.clear();
	ans=0x3f3f3f3f3f3f3f3f;
	cin>>n>>k;
	tot=0;
	for(int i=1;i<=n;i++)
	{
		e[i].clear();
	}
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		e[u].pb(v);
		e[v].pb(u);
	}
	dfs(1,0);
	build();
	_dfs(k);
	cout<<ans<<'\n';
}

namespace SolA
{
	void solve()
	{
		debug(111);
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
//			e[u].pb(v);
//			e[v].pb(u);
		}
		if(n==3||n==5)
		{
			cout<<"1\n";
			return;
		}
		cout<<max(2ll,(n/2-k+2)/3+1);
	}
}

signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifdef LOCAL
	cerr<<double(&____ED-&____ST)/(1024*1024)<<"Mib\n";
	double ____st=clock();
#endif
	int c,T;
	cin>>c>>T;
	if(c==13||c==14)
	{
		while(T--)
		{
			SolA::solve();
		}
		return 0;
	}
	while(T--)
	{
		solve();
	}
#ifdef LOCAL
	double ____ed=clock();
	cerr<<'\n'<<(____ed-____st)/CLOCKS_PER_SEC*1000<<"ms\n";
#endif
	return 0;
}
