#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000005;
int csdbh,t,n,k,zx=LLONG_MAX,dis[N];
bool sel[N],vis[N];
vector<vector<int> >g;
queue<int>q;
void chk_dfs(int now,int fa){
	if(!sel[now])return;
	vis[now]=1;
	for(int v:g[now]){
		if(v==fa)continue;
		chk_dfs(v,now);
	}
}
inline bool check(void){
	int cnt=0;
	for(int i=1;i<=n;i++)vis[i]=0;
	for(int i=1;i<=n;i++){
		if(sel[i]&&!vis[i]){
			cnt++;
			if(cnt>2)return false;
			chk_dfs(i,0);
		}
	}
	return true;
}
inline int calc(void){
	while(!q.empty())q.pop();
	for(int i=1;i<=n;i++){
		if(sel[i]){
			dis[i]=0;
			q.push(i);
		}
		else dis[i]=-1;
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int v:g[u]){
			if(dis[v]==-1){
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
	int zd=0;
	for(int i=1;i<=n;i++)zd=max(zd,dis[i]);
	return zd;
}
void dfs(int now,int cnt){
	if(cnt==k){
		if(check())zx=min(zx,calc());
		return;
	}
	if(now>n)return;
	sel[now]=1;
	dfs(now+1,cnt+1);
	sel[now]=0;
	dfs(now+1,cnt);
}
inline void sol(void){
	g.clear();
	zx=LLONG_MAX;
	cin>>n>>k;
	g.resize(n+1);
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	cout<<zx<<"\n";
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>csdbh>>t;
	while(t--)sol();
	return 0;
}
