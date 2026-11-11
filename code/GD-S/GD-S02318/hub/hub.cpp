#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define gc getchar
#define pb emplace_back
inline int re(){
	int x=0,f=1; char c=gc();
	for(;!isdigit(c);c=gc())if(c=='-')f=-1;
	for(; isdigit(c);c=gc())x=x*10+(c-48);
	return x*f;
}
constexpr int N = 1e6+3,INF = 1e9;

int n,k;
vector<int> e[N];

namespace solve{
	
	bool vis[23],mk[23];
	int dis[23];
	void dfs(int u){
		mk[u]=1;
		for(int v:e[u]){
			if(!vis[u]||mk[v])continue;
			dfs(v);
		}
	}
	
	void sol1(){
		int ans=INF;
		for(int mask=1;mask<1<<n;mask++){
			if(__builtin_popcount(mask)!=k)continue;
			int M=mask<<1,cnt=0;
			queue<int> q;
			memset(vis,0,sizeof vis);
			memset(mk,0,sizeof mk);
			memset(dis,0x3f,sizeof dis);
			
			for(int i=1;i<=n;i++)if(M>>i&1)dis[i]=0,vis[i]=1,q.push(i);
			for(int i=1;i<=n;i++)if(vis[i]&&!mk[i])cnt++,dfs(i);
			
			if(cnt>2)continue;
			
			while(!q.empty()){
				int u=q.front(); q.pop();
				for(int v:e[u]){
					if(!vis[v]){
						vis[v]=1;
						dis[v]=dis[u]+1;
						q.push(v);
					}
				}
			}
			ans=min(ans,*max_element(dis+1,dis+n+1));
		}
		cout<<ans<<'\n'; 
	}
	
}

namespace solve2{
	int dis[N];
	bool vis[N],mk[N];
	
	void sol2(){
		int ans=INF;
		for(int i=1;i<=n;i++)
			for(int j=1;j<i;j++){
				queue<int> q;
				memset(vis,0,(n+3)*sizeof(bool));
				memset(mk,0,(n+3)*sizeof(bool));
				memset(dis,0x3f,(n+3)*sizeof(int));
				q.push(i); vis[i]=1; dis[i]=0;
				q.push(j); vis[j]=1; dis[j]=0;
				while(!q.empty()){
					int u=q.front(); q.pop();
					for(int v:e[u]){
						if(!vis[v]){
							vis[v]=1;
							dis[v]=dis[u]+1;
							q.push(v);
						}
					}
				}
				ans=min(ans,*max_element(dis+1,dis+n+1));
			}
		cout<<ans<<'\n';
	}
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int ID=re(),T=re();
	while(T--){
		n=re(); k=re();
		for(int i=1;i<=n;i++)e[i].clear();
		for(int i=1;i<n;i++){
			int x=re(),y=re();
			e[x].pb(y); e[y].pb(x);
		}
		if(n<=20)solve::sol1();
		else solve2::sol2();
	}
}

