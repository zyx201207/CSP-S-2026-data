#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int cc,t;
int n,k;
struct node{
	int to;
	int nxt;
}e[2000010];
int head[1000010],cnt=0;

void adde(int u,int v){
	++cnt;
	e[cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
	return;
}

void plus_add(int u,int v){
	adde(u,v);
	adde(v,u);
	return;
}

int vis[201000],dis[201000];
int b[201000],c[201000];

void dfs1(int u,int fa){
	vis[u]=1;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(v==fa || !c[v]) continue;
		dfs1(v,u);
	}
	return;
}

void dfs2(int u,int fa){
	vis[u]=1;
	dis[u]=min(dis[u],(c[u]?0:(dis[fa]+1)));
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(v==fa || vis[v]) continue;
		dfs2(v,u);
	}
	return;
}

bool check(){
	int cnt=0;
	for(int i=0;i<=n;++i){
		vis[i]=0;
	}
	for(int i=1;i<=n;++i){
		if(!vis[i] && c[i]){
			dfs1(i,0);
			++cnt;
		}
	}
	if(cnt>2) return 0;
	return 1;
}



int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cin >> cc >> t;
	while(t-->0){
		cin >> n >> k;
		cnt=0;
		for(int i=0;i<=n;++i){
			head[i]=0;
		}
		for(int i=1;i<n;++i){
			int u,v;
			cin >> u >> v;
			plus_add(u,v);
		}
		if(cc<=3){
			for(int i=1;i<=n;++i){
				b[i]=i;
			}
			int ans=1000000;
			for(int lr=1;lr<(1<<n);++lr){
				int cnt1=0;
				for(int i=1;i<=n;++i){
					c[i]=0;
				}
				for(int i=0;i<n;++i){
					if(lr&(1<<i)){
						c[i+1]=1;
						++cnt1;
					}
				}
				if(cnt1!=k) continue;
//				for(int i=1;i<=k;++i){
//					c[b[i]]=1;
//				}
				if(!check()) continue;
				for(int i=1;i<=n;++i){
					dis[i]=10000000;
				}
				for(int i=1;i<=n;++i){
					if(c[i]){
						for(int i=1;i<=n;++i){
							vis[i]=0;
						}
						dfs2(i,0);
					}
				}
				int tmp=0;
				for(int i=1;i<=n;++i){
					tmp=max(tmp,dis[i]);
				}
				ans=min(ans,tmp);
			}
			cout << ans << '\n';
		}else{
			int ans=10000;
			for(int i=1;i<=n;++i){
				for(int j=i=1;j<=n;++j){
					for(int i=1;i<=n;++i){
						dis[i]=10000000;
					}
					for(int i=1;i<=n;++i){
						vis[i]=0;
					}
					dfs2(i,0);
					for(int i=1;i<=n;++i){
						vis[i]=0;
					}
					dfs2(j,0);
					int tmp=0;
					for(int i=1;i<=n;++i){
						tmp=max(tmp,dis[i]);
					}
					ans=min(ans,tmp);
				}
			}
			cout << ans << '\n';
		}
	}
	return 0;
}
// final ver
