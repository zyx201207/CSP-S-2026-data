// Thanks for judging my code!
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define down(i,x,y) for(int i=(x);i>=(y);--i)
#define pii pair<int,int>
#define fi first
#define se second
#define mkp make_pair
#define eb emplace_back
#define pb push_back
#define maxn 1000006
using namespace std;
int TC,T,n,K;
vector<int> g[maxn];
int fa[maxn][25],dep[maxn];
ll cost[maxn][25];
bool vis[maxn],flag[maxn];
void dfs(int x,int Fa){
	fa[x][0]=Fa;
	cost[x][0]=1;
	dep[x]=dep[Fa]+1;
	rep(i,1,20){
		fa[x][i]=fa[fa[x][i-1]][i-1];
		cost[x][i]=cost[x][i-1]+cost[fa[x][i-1]][i-1];
	}
	for(int v:g[x]){
		if(v==Fa)continue;
		dfs(v,x);
	}
}
void dfs2(int x){
	vis[x]=1;
	for(int v:g[x]){
		if(flag[v])continue;
		if(vis[v])continue;
		dfs2(v);
	}
}
ll dist(int x,int y){
	if(dep[x]>dep[y])swap(x,y);
	ll res=0;
	down(i,20,0){
		if(dep[fa[y][i]]>=dep[x]){
			res+=cost[y][i];
			y=fa[y][i];
		}
	}
	if(x==y)return res;
	down(i,20,0){
		if(fa[x][i]!=fa[y][i]){
			res+=cost[x][i]+cost[y][i];
			x=fa[x][i],y=fa[y][i];
		}
	}
	return res+2;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&TC,&T);
	while(T--){
		scanf("%d%d",&n,&K);
		rep(i,1,n){
			rep(j,0,20){
				fa[i][j]=cost[i][j]=0;
			}
			g[i].clear();
		}
		rep(i,1,n-1){
			int u,v;scanf("%d%d",&u,&v);
			g[u].eb(v),g[v].eb(u);
		}
		dfs(1,0);
		ll ans=1e18;
		rep(i,1,(1<<n)-1){
			vector<int> now;
			int cnt=0;
			rep(j,1,n){
				vis[j]=0;
				if((i>>(j-1))&1){
					now.eb(j);
					++cnt;
					flag[j]=0;
				}else{
					flag[j]=1;
				}
			}
			if(cnt!=K)continue;
			cnt=0;
			for(int j:now){
				if(!vis[j]){
					dfs2(j);
					++cnt;
				}
			}
			if(cnt>2)continue;
			ll mx=-1e18;
			rep(j,1,n){
				ll mi=1e18;
				for(int k:now){
					mi=min(mi,dist(j,k));
				}
				mx=max(mx,mi);
			}
			ans=min(ans,mx);
		}
		printf("%lld\n",ans);
	} 
	return 0;
}
// Oct31>Dec25!
// 15pts?
// I do not know what I will do and what I do.
// Who am I?
// Where am I?
// What am I doing?
// I love CCF.
