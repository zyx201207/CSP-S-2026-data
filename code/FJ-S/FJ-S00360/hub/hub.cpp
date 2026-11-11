#include<bits/stdc++.h>
using namespace std;
constexpr int N=1e6+5;
int c,t,n,k,u,v;
int head[N],tot,to[N<<1],nxt[N<<1];
void add(int u,int v){
	to[++tot]=v,nxt[tot]=head[u],head[u]=tot;
}
bool vis[N],tag[N];
void dfs1(int u){
	vis[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(vis[v]||tag[v]==0)continue;
		dfs1(v);
	}
}
struct node{
	int u,dis;
};
int bfs(int x){
	queue<node>q;
	q.push({x,0});
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}
	vis[x]=1;
	while(!q.empty()){
		int u=q.front().u,dis=q.front().dis;
		q.pop();
		if(tag[u])return dis;
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(vis[v])continue;
			vis[v]=1;
			q.push({v,dis+1});
		}
	}
}
int ans;
void dfs2(int x,int cnt){
	if(x==n+1){
		if(cnt!=k)return; 
		int cnt=0;
		for(int i=1;i<=n;i++){
			vis[i]=0;
		}
		for(int i=1;i<=n;i++){
			if(tag[i]&&vis[i]==0){
				dfs1(i);
				cnt++;
			}
		}
		if(cnt>2)return;
		int maxx=0;
		for(int i=1;i<=n;i++){
			maxx=max(maxx,bfs(i));
		}
		ans=min(ans,maxx);
		return;
	}
	tag[x]=1;
	dfs2(x+1,cnt+1);
	tag[x]=0;
	dfs2(x+1,cnt);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		tot=0;
		memset(head+1,0,sizeof(int)*n);
		for(int i=1;i<n;i++){
			cin>>u>>v;
			add(u,v),add(v,u);
		}
		ans=INT_MAX;
		dfs2(1,0);
		cout<<ans<<"\n";
	}
	return 0;
}

