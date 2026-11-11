#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int ID,T,n,K;
vector<int>e[N];
namespace baoli{
	int mx[N],mx2[N],f[N],X,As,pr[N];
	void dfs(int u,int fa){
		mx[u]=mx2[u]=0;
		f[u]=1;
		for(int v:e[u])
			if(v^fa){
				dfs(v,u);
				if(mx[v]>=X)f[u]+=f[v];
				if(mx[v]+1>mx[u]){
					mx2[u]=mx[u];
					mx[u]=mx[v]+1;
				}
				else mx2[u]=max(mx2[u],mx[v]+1);
			}
	}
	void dfs2(int u,int fa,int x){
		if(x>X)return;
		As=min(As,f[u]);
		for(int v:e[u])
			if(v^fa)dfs2(v,u,max(x,mx[u]==mx[v]+1?mx2[u]:mx[u])+1);
	}
	bool chk(int lim){
		X=lim;
		dfs(1,0);
		As=n;
		dfs2(1,0,0);
		if(As<=K)return 1;
		for(int i=2;i<=n;i++){
			int j=pr[i];
			dfs(j,i);
			As=n;
			dfs2(j,i,0);
			int jj=As;
			As=n;
			dfs(i,j);
			dfs2(i,j,0);
			if(jj+As<=K)return 1;
		}
		return 0;
	}
	void dfs0(int u){
		for(int v:e[u])
			if(v^pr[u]){
				pr[v]=u;
				dfs0(v);
			}
	}
	void main(){
		dfs0(1);
		int l=0,r=n-K;
		while(l<=r){
			int mid=l+r>>1;
			if(chk(mid))r=mid-1;
			else l=mid+1;
		}
		cout<<l<<"\n";
		for(int i=1;i<=n;i++)e[i].clear();
	}
}
namespace spa{
	int mx[N],mx2[N],f[N],g[N],X,d[N][20],w[N][20],pr[N][20],h[N][20],dep[N],As;
	void dfs(int u,int fa){
		mx[u]=mx2[u]=0;
		f[u]=1;
		for(int v:e[u])
			if(v^fa){
				dep[v]=dep[u]+1;
				dfs(v,u);
				if(mx[v]>=X)f[u]+=f[v];
				if(mx[v]+1>mx[u]){
					mx2[u]=mx[u];
					mx[u]=mx[v]+1;
				}
				else mx2[u]=max(mx2[u],mx[v]+1);
			}
	}
	void dfs2(int u,int fa,int x){
		if(x<=X)As=min(As,f[u]);
		for(int v:e[u])
			if(v^fa){
				g[v]=f[u]-(mx[v]>=X?f[v]:0)+(x>X?g[u]:0);
				int y=mx[u]==mx[v]+1?mx2[u]:mx[u];
				pr[v][0]=u;
				d[v][0]=y-dep[u];
				w[v][0]=y+dep[u];
				h[v][0]=g[v];
				for(int j=1;j<20;j++){
					if(pr[v][j-1]){
						pr[v][j]=pr[pr[v][j-1]][j-1];
						d[v][j]=max(d[v][j-1],d[pr[v][j-1]][j-1]);
						w[v][j]=max(w[v][j-1],w[pr[v][j-1]][j-1]);
						h[v][j]=min(h[v][j-1],h[pr[v][j-1]][j-1]);
					}
					else pr[v][j]=0;
				}
				dfs2(v,u,max(x,y)+1);
			}
	}
	bool chk(int lim){
		X=lim;
		As=n;
		dfs(1,0);
		dfs2(1,0,0);
		if(As<=K)return 1;
		for(int i=2;i<=n;i++){
			int x=i,z=n;
			for(int j=19;~j;j--)
				if(pr[x][j]&&d[x][j]+dep[i]<=X){
					z=min(z,h[x][j]);
					x=pr[x][j];
				}
			int y=0;
			for(int j=19;~j;j--)
				if(pr[x][j]&&max(y,w[x][j])-dep[pr[x][j]]+1<=X){
					z=min(z,h[x][j]);
					y=max(y,w[x][j]);
					x=pr[x][j];
				}
			if(pr[x][0])z=min(z,h[x][0]);
			if(f[i]+z<=K)return 1;
		}
		return 0;
	}
	void main(){
		int l=0,r=n-K;
		while(l<=r){
			int mid=l+r>>1;
			if(chk(mid))r=mid-1;
			else l=mid+1;
		}
		cout<<l<<"\n";
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>ID>>T;
	while(T--){
		cin>>n>>K;
		bool fg=n&1;
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			e[x].push_back(y);
			e[y].push_back(x);
			if(fg){
				if(i<=n/2){
					if(x!=i||y!=i+1)fg=0;
				}
				else{
					if(x!=i-n/2||y!=i+1)fg=0;
				}
			}
		}
		if(n==K)cout<<"0\n";
		else if(n<=4000)baoli::main();
		else spa::main();
		for(int i=1;i<=n;i++)e[i].clear();
	}
	return 0;
}
