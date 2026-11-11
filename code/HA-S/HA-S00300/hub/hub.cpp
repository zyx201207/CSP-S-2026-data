#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2000005,M=N*2;
const ll INF=0x3f3f3f3f;
int n,k;
int hd[N],to[M],nxt[M],tot;
void add(int x,int y){
	tot++;
	to[tot]=y;
	nxt[tot]=hd[x];
	hd[x]=tot;
}
int ans=INF;
int b[N];
int vis[N];
void dfs2(int u,int fa){
	vis[u]=1;
	for(int i=hd[u];i;i=nxt[i]){
		int v=to[i];
		if(v==fa) continue;
		if(!b[v]) continue;
		if(vis[v]) continue;
		dfs2(v,u);
	}
}
struct node{
	int u,s;
};
void bfs(){
	queue<node> q;
	int mx=0;
	for(int i=1;i<=n;i++){
		vis[i]=0;
		if(b[i]){
			q.push({i,0});
			vis[i]=1;
		}
	}
//	cout<<"!";
	while(q.size()){
		node t=q.front();
		q.pop();
		mx=max(mx,t.s);
//		if(b[2]&&b[7]&&b[9]){
//			cout<<t.u<<" "<<t.s<<"\n";
//		}
		for(int i=hd[t.u];i;i=nxt[i]){
			int v=to[i];
			if(vis[v]) continue;
			vis[v]=1;
			q.push({v,t.s+1});
		}
	}
//	cout<<"---\n";
//	cout<<mx<<"\n";
//	for(int i=1;i<=n;i++){
//		if(b[i]){
//			cout<<i<<" ";
//		}
//	}
//	cout<<"\n";
	ans=min(ans,mx);
}
void work(){
	int cnt=0;
	for(int i=1;i<=n;i++) vis[i]=0;
	for(int i=1;i<=n;i++){
		if(b[i]&&!vis[i]){
			dfs2(i,0);
			cnt++;
		}
	}
	if(cnt>2) return;
	bfs();
}
void dfs(int idx,int x){
	if(idx>k){
		work();
		return;
	}
	for(int i=x;i<=n;i++){
		b[i]=1;
		dfs(idx+1,i+1);
		b[i]=0;
	}
}
void del(){
	for(int i=1;i<=n;i++) hd[i]=0;
	for(int i=1;i<=tot;i++) to[i]=nxt[i]=0;
	tot=0;
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	ans=INF;
	dfs(1,1);
	cout<<ans<<"\n";
	del();
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
