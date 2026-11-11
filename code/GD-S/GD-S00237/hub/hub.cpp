#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5,INF=1e9;
int c,t,n,k,dep[N],st[23][N],dfn[N],tot;
vector <int> v[N];
void dfs(int u,int fa)
{
	dep[u]=dep[fa]+1;
	dfn[u]=++tot;
	st[0][dfn[u]]=fa;
	for(int i=0;i<v[u].size();i++)
	{
		int v2=v[u][i];
		if(v2==fa) continue;
		dfs(v2,u);
	}
}
int chkmin(int x,int y)
{
	return dfn[x]<dfn[y]?x:y;
}
int LCA(int x,int y)
{
	if(x==y) return x;
	if((x=dfn[x])>(y=dfn[y])) swap(x,y);
	int lglen=__lg(y-x++);
	return chkmin(st[lglen][x],st[lglen][y-(1<<lglen)+1]);
}
int dist(int x,int y)
{
	return dep[x]+dep[y]-2*dep[LCA(x,y)];
}
namespace sub12
{
	bool chs[15],vis[15];
	void dfs2(int u)
	{
		vis[u]=1;
		for(int i=0;i<v[u].size();i++)
		{
			int v2=v[u][i];
			if(!vis[v2] && chs[v2]) dfs2(v2);
		}
	}
	bool check()
	{
		memset(vis,0,sizeof(vis));
		int cntt=0;
		for(int i=1;i<=n;i++)
		{
			if(chs[i] && !vis[i]) dfs2(i),cntt++;
//			cout<<cntt<<"\n";
			if(cntt>2) return 0; 
		}
		return 1;
	}
	void main()
	{
		int U=(1<<n)-1,ans=INF;
		for(int zt=0;zt<=U;zt++)
		{
			if(__builtin_popcount(zt)!=k) continue;
//			cout<<zt<<"\n";
			for(int i=1;i<=n;i++)
			{
				if((zt>>(i-1))&1) chs[i]=1;
				else chs[i]=0;
			}
			if(!check()) continue;
//			cout<<"aaa\n";
			int maxx=0;
			for(int i=1;i<=n;i++)
			{
				int minn=INF;
				for(int j=1;j<=n;j++)
				{
					if(!chs[j]) continue;
					minn=min(minn,dist(i,j));
				}
				maxx=max(maxx,minn);
			}
//			if(maxx==0) cout<<zt<<"@";
			ans=min(ans,maxx);
		}
		cout<<ans<<"\n";
	}
}
namespace sub3
{
	bool chs[1005],vis[1005];
	void main()
	{
		int ans=INF;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				chs[i]=1,chs[j]=1;
				int maxx=0;
				for(int i=1;i<=n;i++)
				{
					int minn=INF;
					for(int j=1;j<=n;j++)
					{
						if(!chs[j]) continue;
						minn=min(minn,dist(i,j));
					}
					maxx=max(maxx,minn);
				}
	//			if(maxx==0) cout<<zt<<"@";
				ans=min(ans,maxx);
				chs[i]=0,chs[j]=0;
			}
		}
		cout<<ans<<"\n"; 
		return ;
	}
}
namespace other
{
	int cnt=0,f[N],g[N],mbb;
	void dfs2(int u,int fa)
	{
		int mdis=-INF,mdep=INF;
		f[u]=-INF,g[u]=INF;
		int son=0;
		for(int i=0;i<v[u].size();i++)
		{
			int v2=v[u][i];
			if(v2==fa) continue;
			dfs2(v2,u);
			mdis=max(mdis,f[v2]);
			mdep=min(mdep,g[v2]);
			son++;
		}
		if(son==0)
		{
			return ;
		}
		if(mdis+mdep+2<=mbb)
		{
			f[u]=0;
			g[u]=mdep+1;
		}else if(mdis+2<=mbb)
		{
			f[u]=mdis+1;
			g[u]=mdep+1;
		}else
		{
			cnt++;
			f[u]=-INF;
			g[u]=0;
		}
//		cout<<mdis<<" "<<mdep<<"\n";
//		cout<<u<<" "<<f[u]<<" "<<g[u]<<"\n";
	}
	bool check(int mid)
	{
		mbb=mid;
		cnt=0;
		dfs2(1,0);
//		for(int i=1;i<=10;i++) cout<<f[i]<<" "<<g[i]<<"\n";
		if(cnt<=k) return 1;
		else return 0;
	}
	void main()
	{
		int l=1,r=1e9;
		while(l<r)
		{
			int mid=l+r>>1;
			if(check(mid)) r=mid;
			else l=mid+1;
		}
//		check(1);
		cout<<l<<"\n";
	}
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) v[i].clear();
	tot=0;
	for(int i=1;i<=n-1;i++)
	{
		int u,v2;
		cin>>u>>v2;
		v[u].push_back(v2);
		v[v2].push_back(u);
	}
	dfs(1,0);
	for(int i=1;i<=21;i++)
	{
		for(int j=1;j+(1<<i)-1<=n;j++) st[i][j]=chkmin(st[i-1][j],st[i-1][j+(1<<(i-1))]);
	}
	if(c<=3)
	{
		sub12::main();
		return ;
	}
	if(c==7)
	{
		sub3::main();
		return ;
	}
	other::main();
	return ; 
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
/*
7 1
10 2
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10



0 2
5 2
1 2
2 3
3 4
4 5

10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10


提交前检查：
ll.
ce. re. /0 越界
多测清空
算空间！

*/

