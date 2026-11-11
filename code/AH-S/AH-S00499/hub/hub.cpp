#include <bits/stdc++.h>
#define ll long long
#define up(i,a,b) for (int i=(a);i<=(b);i++)
#define down(i,a,b) for (int i=(a);i>=(b);i--)
using namespace std;
int n,k;
namespace solve1{
	const int N=105;
	vector<int> g[N];
	int sel[N],d[N][N],ans;
	int fa[N];
	int find(int x){
		if (fa[x]==x) return x;
		else return fa[x]=find(fa[x]);
	}
	void check(){
		int res=0;
		vector<int> s;
		up(i,1,n) if (sel[i]) s.emplace_back(i);
		up(i,1,n) fa[i]=i;
		for (int u:s){
			for (int v:g[u]) if (sel[v]){
				int x=find(u),y=find(v);
				if (x!=y) fa[x]=y;
			}
		}
		int cntt=0;
		up(i,1,n) if (sel[i]&&find(i)==i) cntt++;
		if (cntt>2) return;
		up(i,1,n) if (!sel[i]){
			int tmp=1e9;
			for (int j:s) tmp=min(tmp,d[i][j]);
			res=max(res,tmp);
		}
		ans=min(ans,res);
	}
	void dfs(int now,int cnt){
		if (cnt==k) return check(),void();
		if (now==n+1) return;
		dfs(now+1,cnt);
		sel[now]=1,dfs(now+1,cnt+1),sel[now]=0;
	}
	void solve(){
		ans=1e9;
		cin>>n>>k;
		up(i,1,n) g[i].clear();
		up(i,1,n) up(j,1,n) d[i][j]=(i==j?0:1e9);
		up(i,1,n-1){
			int u,v;cin>>u>>v;
			d[u][v]=d[v][u]=1;
			g[u].emplace_back(v),g[v].emplace_back(u);
		}
		up(mid,1,n) up(i,1,n) up(j,1,n) d[i][j]=min(d[i][j],d[i][mid]+d[mid][j]);
		dfs(1,0);
		cout<<ans<<'\n';
	}
}
namespace solve2{
	const int N=1005;
	vector<int> g[N];
	int l[N],r[N],tim,dad[N],id[N];
	void dfs0(int u,int fa){
		dad[u]=fa;
		l[u]=++tim,id[tim]=u;
		for (int v:g[u]) if (v!=fa) dfs0(v,u);
		r[u]=tim;
	}
	int liml,limr,flag;
	int dep[N];
	void dfs1(int u,int fa){
		dep[u]=dep[fa]+1;
		for (int v:g[u]){
			if (v==fa) continue;
			int op=(l[v]>=liml&&l[v]<=limr);
			if (op!=flag) continue;
			dfs1(v,u);
		}
	}
	int X,Y;
	int calc(int x){
		int rt=0;
		liml=l[x],limr=r[x];
		flag=1;dfs1(x,0);
		X=0;
		up(i,liml,limr){
			int u=id[i];
			if (dep[u]>dep[X]) X=u;
		}
		dfs1(X,0);
		Y=0;
		up(i,liml,limr){
			int u=id[i];
			if (dep[u]>dep[Y]) Y=u;
		}
		rt=(dep[Y]>>1);
		flag=0;dfs1(dad[x],0);
		X=0;
		up(i,1,liml-1){
			int u=id[i];
			if (dep[u]>dep[X]) X=u;
		}
		up(i,limr+1,n){
			int u=id[i];
			if (dep[u]>dep[X]) X=u;
		}
		dfs1(X,0);
		Y=0;
		up(i,1,liml-1){
			int u=id[i];
			if (dep[u]>dep[Y]) Y=u;
		}
		up(i,limr+1,n){
			int u=id[i];
			if (dep[u]>dep[Y]) Y=u;
		}
		rt=max(rt,dep[Y]>>1);
		return rt;
	}
	void solve(){
		cin>>n>>k;
		up(i,1,n) g[i].clear();
		up(i,1,n-1){
			int u,v;cin>>u>>v;
			g[u].emplace_back(v),g[v].emplace_back(u);
		}
		tim=0,dfs0(1,0);
		int ans=1e9;
		up(i,2,n) ans=min(ans,calc(i));
		cout<<ans<<'\n';
	}
}

namespace solve3{
	const int N=1e5+5;
	vector<int> g[N];
	int l[N],r[N],tim,dad[N],id[N];
	void dfs0(int u,int fa){
		dad[u]=fa;
		l[u]=++tim,id[tim]=u;
		for (int v:g[u]) if (v!=fa) dfs0(v,u);
		r[u]=tim;
	}
	int liml,limr,flag;
	int dep[N];
	void dfs1(int u,int fa){
		dep[u]=dep[fa]+1;
		for (int v:g[u]){
			if (v==fa) continue;
			int op=(l[v]>=liml&&l[v]<=limr);
			if (op!=flag) continue;
			dfs1(v,u);
		}
	}
	int X,Y;
	int calc(int x){
		int rt=0;
		liml=l[x],limr=r[x];
		flag=1;dfs1(x,0);
		X=0;
		up(i,liml,limr){
			int u=id[i];
			if (dep[u]>dep[X]) X=u;
		}
		dfs1(X,0);
		Y=0;
		up(i,liml,limr){
			int u=id[i];
			if (dep[u]>dep[Y]) Y=u;
		}
		rt=(dep[Y]>>1);
		flag=0;dfs1(dad[x],0);
		X=0;
		up(i,1,liml-1){
			int u=id[i];
			if (dep[u]>dep[X]) X=u;
		}
		up(i,limr+1,n){
			int u=id[i];
			if (dep[u]>dep[X]) X=u;
		}
		dfs1(X,0);
		Y=0;
		up(i,1,liml-1){
			int u=id[i];
			if (dep[u]>dep[Y]) Y=u;
		}
		up(i,limr+1,n){
			int u=id[i];
			if (dep[u]>dep[Y]) Y=u;
		}
		rt=max(rt,dep[Y]>>1);
		return rt;
	}
	int Dep[N];
	void dfs3(int u,int fa){
		Dep[u]=Dep[fa]+1;
		for (int v:g[u]) if (v!=fa) dfs3(v,u);
	}
	void solve(){
		cin>>n>>k;
		up(i,1,n) g[i].clear();
		up(i,1,n-1){
			int u,v;cin>>u>>v;
			g[u].emplace_back(v),g[v].emplace_back(u);
		}
		tim=0,dfs0(1,0);
		int X=0,Y=0;
		dfs3(1,0);
		up(i,1,n) if (Dep[i]>Dep[X]) X=i;
		dfs3(X,0);
		up(i,1,n) if (Dep[i]>Dep[Y]) Y=i;
		int maxd=Dep[Y];
		int ans=1e9;
		up(i,2,n) if (abs(Dep[i]-maxd)<=20) ans=min(ans,calc(i));
		cout<<ans<<'\n';
	}
}

int main(){
	freopen("hub2.in","r",stdin);
	freopen("hub.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;cin>>c>>t;
	while (t--){
		if (c==7) solve2::solve();
		if (c==11||c==12) solve3::solve();
		else solve1::solve();
	}
	return 0;
}
