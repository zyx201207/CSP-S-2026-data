#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=(a);i<=(n);++i)
#define per(i,a,n) for(int i=(n);i>=(a);--i)
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=1e5+10;

int n,k;
vector<int> e[maxn];

inline void clear(){
	rep(i,1,n) e[i].clear();	
}

int f[maxn],vis[maxn],dis[maxn];

inline int find(int x){
	puts("??");
	if(f[x]==x) return x;
	return f[x]=find(f[x]);	
}

inline dfs(int u,int fa){
	printf("%d %d\n",u,fa);
	for(auto v:e[u]){
		if(v==fa) continue;
//		printf("%d %d\n",u,v);
//		puts(">>");
		dfs(v,u);		
		if(vis[v]&&vis[u]) f[find(u)]=find(v);
	}
}

inline void sol1(){
	int ans=n+1;
//	printf("n=?? %d\n",n);
	rep(S,0,2){
		ll cnt=0;
//		printf("%d\n",S);
		rep(j,1,n) vis[j]=S&(1<<(j-1)),cnt+=vis[j];
		rep(i,1,n) f[i]=i;
		if(cnt!=k) continue; 
//		puts("??");
		dfs(1,-1);
		cnt=0;
		rep(j,1,n) cnt+=vis[j]&&f[j]==find(j);
		if(cnt>2) continue;
		rep(i,1,n) dis[i]=1e9; 
		rep(i,1,n){
			if(vis[i] && f[i]==find(i)){
				queue<int> q;
				rep(j,1,n) 
					if(find(f[j])==f[i]) 
						q.push(j),dis[j]=0;
				while(q.size()){
					int u=q.front();
					q.pop();
					for(auto v:e[u]){
						if(dis[u]+1<dis[v]){
							dis[v]=dis[u]+1;
							q.push(v);
						}
					}
				}
			}
		}
		int res=0;
		rep(i,1,n) res=max(res,dis[i]);
		ans=min(ans,res);
 	}
 	printf("%d\n",ans);
} 

inline void solve(){
	scanf("%d%d",&n,&k);
	clear();
	rep(i,1,n-1){
		int u,v;
		scanf("%d%d",&u,&v);
//		printf("u v=%d %d\n",u,v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
//	printf("### %d %d\n",n,k);
	if(n<=10){
		sol1();	
		return;
	}
}

signed main(){
	freopen("hub1.in","r",stdin);
	int c,_=1;
	scanf("%d%d",&c,&_);
	while(_--) solve();
}

