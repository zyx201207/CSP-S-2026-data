#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define lxl long long
#define INF 1000000000
namespace lzz
{
	int C,T,n,k;
	struct node{int u,v;}t[N];
	int bj[N],su,sv; vector<int>q[N];
	int fa[N],dfn[N],out[N],end[N];
	void init(int u)
	{
		dfn[++dfn[0]]=u,out[u]=dfn[0];
		for(int v:q[u])if(v^fa[u])fa[v]=u,init(v); end[u]=dfn[0];
	}
	pair<int,int>dfs(int u,int lim,int fa)
	{
		int ans=0,flg=0;
		for(int v:q[u])
		{
			if(v==fa)continue;
			if(min(u,v)==min(su,sv)&&max(u,v)==max(su,sv))continue;
			pair<int,int>now=dfs(v,lim,u); if(now.first)ans+=now.first; flg=max(flg,now.second+1);
		}if((!ans)&&(flg==lim&&fa))ans=1; return {ans+(ans>0),flg};
	}
	int check(int lim)
	{
		for(int i=2;i<=n;i++)
		{
//			cout<<"!!"
			su=i,sv=fa[i]; int x1=INF,x2=INF;
			for(int u=1;u<=n;u++)if(out[i]<=out[u]&&out[u]<=end[i])x1=min(x1,dfs(u,lim,0).first); else x2=min(x2,dfs(u,lim,0).first);
			if(x1+x2<=k)return 1;
		}return 0;
	}
	void clr()
	{
		dfn[0]=0;
		for(int i=1;i<=n;i++)q[i].clear(),fa[i]=0;
	}
	int main()
	{
		freopen("hub.in","r",stdin);
		freopen("hub.out","w",stdout);
		cin>>C>>T;
		while(T--)
		{
			clr(),cin>>n>>k;
			for(int i=2,x,y;i<=n;i++)cin>>x>>y,q[x].push_back(y),q[y].push_back(x); init(1);
			int l=0,r=n,ans=n;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				if(check(mid))r=mid-1,ans=mid; else l=mid+1;
			}cout<<ans<<'\n';
		}

		return 0;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	return lzz::main();
}

