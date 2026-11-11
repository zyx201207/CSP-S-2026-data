#include<bits/stdc++.h>
using namespace std;
namespace my_space{
	using ll = long long;
	using exl = __int128;
	int constexpr N = 3e3+50;
	struct graph{
		int top[N],nxt[N*2],to[N*2],tot;
		void add(int x,int y){
			nxt[++tot] = top[x];
			to[tot] = y;
			top[x] = tot;
		}
	}g;
	int f[30],minn[30];
	struct DSU{
		int fa[30];
		int find(int x){
			if(fa[x]==x) return x;
			return fa[x] = find(fa[x]);
		}
		void merge(int a,int b){
			int x = find(a),y = find(b); 
			if(x==y) return;
			fa[x] = y;
		}
	}dsu;
	void dfs1(int u,int v){
		for(int i = g.top[u];~i;i = g.nxt[i]){
			int to = g.to[i];
			if(minn[u]+1<minn[to]){
				minn[to] = minn[u] +1;
				dfs1(to,u);
			}
		}
	}
	int n,ans=1e9,temp=1e9;
	int t;
	void dfs(int pos,int k){
		if(k==0){
			for(int i = 1;i<=n;i++) dsu.fa[i] = i;
			for(int i = 1;i<=n;i++){
				if(!f[i]) continue;
				for(int j = g.top[i];~j;j = g.nxt[j]){
					int to = g.to[j];
					if(f[to]) dsu.merge(i,to);
				}
			}
			int cnt=0;
			for(int i = 1;i<=n;i++){
				if(f[i]){
					int x = dsu.find(i);
					if(i==x) cnt++;
				}
			}
			if(cnt>2) return;
			for(int i = 1;i<=n;i++) minn[i] = 1e9;
			for(int i = 1;i<=n;i++){
				if(!f[i]) continue;
				minn[i] =0;
				dfs1(i,i);
			}
			int maxn=0;
			for(int i = 1;i<=n;i++){
				maxn = max(minn[i],maxn);
			} 
//			if(t==0 && maxn==1) {
//				for(int i = 1;i<=n;i++) cout<<minn[i]<<' ';
//				cout<<cnt<<'\n';
//			}
			ans = min(ans,maxn);
			return ;
		}
		if(pos>n) return;
		dfs(pos+1,k);
		f[pos] = 1;
		dfs(pos+1,k-1);
		f[pos] = 0;
	}
	int maxx[N];
	void dfs2(int u,int v){
		maxx[u] = minn[u];
		for(int i = g.top[u];~i;i = g.nxt[i]){
			int to = g.to[i];
			if(to==v) continue;
			minn[to] = minn[u]+1; 
			dfs2(to,u);
			maxx[u] = max(maxx[u],minn[to]);
		}
	}
	void rt(int u,int v,int maxn){
		ans = min(ans,max(maxn,maxx[u]));
		int maxn1,maxn2;
		maxn1 = maxn2 = 0;
		for(int i = g.top[u];~i;i = g.nxt[i]){
			int to = g.to[i];
			if(to==v) continue;
			if(maxn1<maxx[to]) maxn2 = maxn1,maxn2 = maxx[to];
			else if(maxn2<maxx[to]) maxn2 = maxx[to];
		}
		for(int i = g.top[u];~i;i = g.nxt[i]){
			int to = g.to[i];
			if(to==v) continue;
			if(maxn==maxx[to]) rt(to,u,max(maxn,maxn2)+1);
			else rt(to,u,max(maxn,maxn1)+1);
		}
	}
	int main(){
		freopen("hub.in","r",stdin);
		freopen("hub.out","w",stdout);
		ios::sync_with_stdio(0);
		cin.tie(0),cout.tie(0);
		int c;
		cin>>c>>t; 
		while(t--){
			int k;
			cin>>n>>k;
			for(int i = 1;i<=n;i++) g.top[i] = -1;
			for(int i =1;i<n;i++){
				int x,y;
				cin>>x>>y;
				g.add(x,y);
				g.add(y,x);
			}
			if(0<=c && c<=3){
				ans = 1e9; 
				dfs(1,k);
				cout<<ans<<'\n';
			}
			else if(c==7){
				for(int i = 1;i<=n;i++){
					for(int j = 1;j<=n;j++) minn[i] = 1e9;
					minn[i] = 0;
					dfs2(i,i);
					int maxn=0,maxn1=0,w=0;
					for(int j = g.top[i];~j;j = g.nxt[j]){
						int to = g.to[j];
						if(maxn<maxx[to]){
							maxn1 = maxn;
							maxn = maxx[to]; 
							w = to;
						}
						else if(maxn1<maxx[to]){
							maxn1 = maxx[to];
						}
					}
					temp = maxn1;
					rt(w,i,0);
					ans = min(ans,temp);
				}
				cout<<ans<<'\n'; 
			}
		}
		return 0;
	}
}
int main(){
	return my_space::main();
}

