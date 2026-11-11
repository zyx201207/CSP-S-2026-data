#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=1e6+5;
int c,t,n,k,ans,dis[N];
vector<int>g[N];
bool chos[N];
void bfs(int x,int fa,int len){
//	if(dis[x]<len)return ;
	dis[x]=min(dis[x],len);
	for(int i:g[x]){
		if(i==fa)continue;
		bfs(i,x,len+1);
	}
}
bool vis[N];
void fff(int x){
	queue<int>q;
	q.push(x); vis[x]=1;
	while(!q.empty()){
		int p=q.front();q.pop();
		for(int i:g[p]){
			if(!vis[i]&&chos[i]){
				vis[i]=1;
				q.push(i);
			}
		}
	}
}
void dfs(int x,int cnt){
	if(x>n){
		if(cnt>k)return ;
		if(cnt<k)return ;
		for(int i=1;i<=n;++i)dis[i]=n-1;
		for(int i=1;i<=n;++i)
			if(chos[i])bfs(i,0,0);
		int sum=0;
		for(int i=1;i<=n;++i)
			sum=max(sum,dis[i]);
		if(sum>ans)return ;
		for(int i=1;i<=n;++i)vis[i]=0;
		int cnt=0;
		for(int i=1;i<=n;++i){
			if(chos[i]&&!vis[i]){
				vis[i]=1;
				fff(i);
				++cnt;
			}
		}
		if(cnt>2)return ;
		ans=min(ans,sum);
		return ;
	} 
	if(cnt>k)return ;
	chos[x]=1;
	dfs(x+1,cnt+1);
	chos[x]=0;
	dfs(x+1,cnt);
}
int dep[N];
void dfsw(int x,int fa){
	for(int i:g[x]){
		if(i==fa)continue;
		dep[i]=dep[x]+1;
		dfsw(i,x);
	}
} 
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		ans=n-1;
		for(int i=1;i<=n;++i)g[i].clear();
		for(int i=1,u,v;i<n;++i){
			cin>>u>>v;
			g[u].pb(v); g[v].pb(u);
		}
		if(n<=10){
			dfs(1,0);
			cout<<ans<<'\n';
			continue;
		}
		if(k<=2){
			dfsw(1,0);
			int id=0,maxn=0;
			for(int i=1;i<=n;++i){
				if(dep[i]>maxn){
					id=i;
					maxn=dep[i];
				}
			}
			dfsw(id,0);
			id=0; maxn=0;
//			cout<<id<<'\n';
			for(int i=1;i<=n;++i){
				if(dep[i]>maxn){
					id=i;
					maxn=dep[i];
				}
//				cout<<i<<' '<<dep[i]<<'\n';
			}
			maxn=(maxn+1)/2;
//			cout<<id<<' '<<maxn<<'\n';
			cout<<maxn<<'\n';
		}
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
