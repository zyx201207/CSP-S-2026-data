#include<bits/stdc++.h>
using namespace std;
#define maxn 11000
int const inf =1e9;
vector<int> g[maxn];
int c,t,n,k,fa[maxn],d[maxn],f[maxn][30],vis[maxn],cnt[maxn],ans=0;
int find(int x){
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y)return;
	fa[x]=y;
}
void dfs(int u,int fr){
	f[u][0]=fr;
	d[u]=d[fr]+1;
	for(int j=1;j<20;j++){
		f[u][j]=f[f[u][j-1]][j-1];
	}
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==fr)continue;
		dfs(v,u);
	}
}
int lca(int x,int y){
	if(d[x]>d[y])swap(x,y);
	for(int j=20;j>=0;j--){
		if(d[f[y][j]]>=d[x]){
			y=f[y][j];
		}
	}
	if(x==y)return x;
	for(int j=20;j>=0;j--){
		if(f[y][j]!=f[x][j]){
			x=f[x][j];
			y=f[y][j];
		}
	}
	return f[x][0];
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=inf;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1,0);
		queue<int> q;
	
		for(int j=0;j<(1<<n);j++){
			int temans=0;
			for(int i=1;i<=n;i++){
				vis[i]=0;fa[i]=i;cnt[i]=0;
			}
			while(q.size())q.pop();
			for(int i=1;i<=n;i++){
				if((j>>(i-1))&1){
					q.push(i);
					vis[i]=1;
				}
			}
			
			if(q.size()!=k)continue;
			
			while(q.size()){
				int u=q.front();
				q.pop();
				for(int i=0;i<g[u].size();i++){
					int v=g[u][i];
					if(vis[v]){
						merge(u,v);
					}
				}
			}
			
			for(int i=1;i<=n;i++){
				if(vis[i]){
					cnt[find(i)]=1;
				}
			}
			int res=0;
			for(int i=1;i<=n;i++){
				res+=cnt[i];
			}
			
			if(res<=2){
//				cout<<res<<' ';
//				for(int i=1;i<=n;i++){
//					if(vis[i])printf("#%d ",i);
//				}
//				cout<<'\n';
				for(int i=1;i<=n;i++){
					if(vis[i])continue;
					int ansn=inf;
					for(int j=1;j<=n;j++){
						if(i==j)continue;
						if(vis[j]){
							//printf("%d %d %d\n",i,j,d[i]+d[j]-2*d[lca(i,j)]);
							ansn=min(ansn,d[i]+d[j]-2*d[lca(i,j)]);
						}
					}
					temans=max(temans,ansn);
				}
				ans=min(ans,temans);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
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
*/
