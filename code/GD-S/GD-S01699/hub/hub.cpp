#include<bits/stdc++.h>
using namespace std;

constexpr int N=1e6+5,inf=0x3f3f3f; 
int c,t,n,k,u,v,ans;
vector<int>e[N];

int cnt,dis[N],vis[N];
void combin(int u){
//	cerr<<u<<endl;
	if(vis[u]) dis[u]=0,cnt++;
	for(int v:e[u]){
		if(dis[v]!=-1) continue;
		dis[v]=dis[u]+1;
		combin(v);
	}
}
int check(){
	cnt=0;
	int tmp=0;
	for(int i=1;i<=n;i++) dis[i]=-1;
	for(int i=1;i<=n;i++){
		if(tmp==2) break;
		if(vis[i]&&dis[i]==-1){
			tmp++;
			combin(i);
		}
	}
	if(cnt<k) return inf;
	int maxn=0;
	for(int i=1;i<=n;i++) maxn=max(maxn,dis[i]);
	return maxn;
}
void dfs(int pos,int lst){
	if(pos==k+1){
		ans=min(check(),ans);
		return;
	}
	for(int i=lst+1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		dfs(pos+1,i);
		vis[i]=0;
	}
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(;t--;){
		cin>>n>>k;
		ans=inf;
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<n;i++){
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u); 
		}
		dfs(1,0);
		cout<<ans<<'\n';
	}
}
