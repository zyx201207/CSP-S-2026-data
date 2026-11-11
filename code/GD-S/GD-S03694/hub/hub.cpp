#include<bits/stdc++.h>
# define Maxn 1000005
using namespace std;
int cid,T,n,K,u,v;

vector<int> e[Maxn];
void add(int u,int v) {e[u].push_back(v);}

struct Baoli{
	int fa[Maxn];
	int find(int x) {
		if(x!=fa[x]) fa[x]=find(fa[x]);
		return fa[x];
	}
	
	int ans;
	int dis[15][15];
	void dfs(int rt,int fa,int g) {
		for(int i:e[rt]) {
			if(i==fa) continue;
			dis[g][i]=dis[g][rt]+1;
			dfs(i,rt,g);
		}
	}
	
	void Solve() {
		while(T--) {
			scanf("%d%d",&n,&K),ans=n;
			for(int i=1;i<n;i++) {
				scanf("%d%d",&u,&v);
				add(u,v),add(v,u);
			}
			for(int i=1;i<=n;i++) dfs(i,0,i);
			
			for(int s=0;s<(1<<n);s++) {
				if(__builtin_popcount(s)!=K) continue;
				
				int cnt=K;
				for(int i=1;i<=n;i++) fa[i]=i;
				
				for(int i=1;i<=n;i++) {
					if((s>>(i-1))&1) {
						for(int j=i+1;j<=n;j++) {
							if((s>>(j-1))&1) {
								if(dis[i][j]==1) {
									int f1=find(i),f2=find(j);
									if(f1!=f2) {
										cnt--;
										f1=f2;
									}
								}
							} 
						}	
					}
				}
				if(cnt>2) continue;
				
				int now=0;
				for(int i=1;i<=n;i++) {
					if(!((s>>(i-1))&1)) {
						int DIS=n;
						for(int j=1;j<=n;j++) {
							if((s>>(j-1))&1)
							DIS=min(DIS,dis[i][j]);
						}
						now=max(now,DIS);
					}
				}
				ans=min(ans,now);
			}
			
			printf("%d\n",ans);
			
			for(int i=1;i<=n;i++) e[i].clear();
		}
	}
}Baoli;

int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&cid,&T);
	Baoli.Solve();
	return 0;
}
