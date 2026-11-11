#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+5;
int n,k,ans,C;
vector<int> a[N];
int dis[N][N],fa[N];
bool vis[N];
void solve();
void bfs(int st);
void bfs2(int st,int k);
int find(int x);
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int T=1;
	cin>>C>>T;
	while(T--){
		solve();
	}
	return 0;
}
void solve(){
	ans=1e18;
	cin>>n>>k;
	for(int i=1;i<=n;i++) a[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		a[u].push_back(v);
		a[v].push_back(u); 
	}
	for(int i=1;i<=n;i++) bfs(i);
	for(int i=0;i<(1<<n);i++){
		int res=0;
		for(int j=1;j<=n;j++){
			if((i>>(j-1))&1) res++;
		}
		if(res!=k) continue;
		memset(vis,0,sizeof(vis));
		res=0;
		for(int j=1;j<=n;j++){
			if(((i>>(j-1))&1)==0) continue;
			if(vis[j]) continue;
			res++;
			bfs2(j,i); 
		}
		if(res>2) continue;
		int cnt1=0;	
		for(int j=1;j<=n;j++){
			int cnt2=1e18;
			for(int l=1;l<=n;l++){
				if((i>>(l-1))&1){
					cnt2=min(cnt2,dis[l][j]);
				}
			}
			cnt1=max(cnt1,cnt2);
		}
		ans=min(ans,cnt1);
	}
	cout<<ans<<'\n';
	return ;
}
void bfs(int st){
	memset(vis,0,sizeof(vis));
	queue<int> q;
	q.push(st);
	dis[st][st]=0;
	vis[st]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=0;i<a[x].size();i++){
			if(!vis[a[x][i]]){
				vis[a[x][i]]=1;
				dis[st][a[x][i]]=dis[st][x]+1;
				q.push(a[x][i]);
			}
		}
	}
	return ;
}
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void bfs2(int st,int k){
	queue<int> q;
	q.push(st);
	vis[st]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=0;i<a[x].size();i++){
			if(!vis[a[x][i]]&&((k>>(a[x][i]-1))&1)){
				vis[a[x][i]]=1;
				q.push(a[x][i]);
			}
		}
	}
	return ;
}
