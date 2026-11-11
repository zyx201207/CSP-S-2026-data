#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
struct edge{
	int ed,nxt;
}b[N<<1];
struct node{
	int id,st;
};
int cid,T,n,k,a[N],nbs[N],tot,ans;
inline ll read(){
	ll x=0;
	int f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
inline void addedge(int x,int y){
	b[++tot]={y,nbs[x]}; nbs[x]=tot;
}
inline bool check(){
	int cnt=0;
	bool vis[N]={};
	for(int i=1;i<=n;i++)
		if(a[i] && !vis[i]){
			cnt++;
			queue<int> q;
			q.push(i);
			while(!q.empty()){
				int u=q.front();
				q.pop();
				for(int x=nbs[u];x;x=b[x].nxt){
					int v=b[x].ed;
					if(vis[v] || !a[v]) continue;
					vis[v]=1;
					q.push(v);
				}
			}
		}
	return cnt<=2;
}
inline void dfs(int u,int ret){
	if(ret>k) return;
	if(u>n){
		if(ret!=k) return;
		if(!check()) return;
		queue<node> q;
		bool vis[N]={};
		for(int i=1;i<=n;i++)
			if(a[i]) vis[i]=1,q.push({i,0});
		int sum=0;
		while(!q.empty()){
			int u=q.front().id;
			int st=q.front().st;
			q.pop();
			sum=max(sum,st);
			for(int x=nbs[u];x;x=b[x].nxt){
				int v=b[x].ed;
				if(vis[v]) continue;
				vis[v]=1;
				q.push({v,st+1});
			}
		}
		ans=min(ans,sum);
		return;
	}
	a[u]=0;
	dfs(u+1,ret);
	a[u]=1;
	dfs(u+1,ret+1);
	a[u]=0;
}
inline void solve(){
	tot=0;
	memset(b,0,sizeof b);
	memset(nbs,0,sizeof nbs);
	n=read(),k=read();
	for(int i=1,x,y;i<n;i++) x=read(),y=read(),addedge(x,y),addedge(y,x);
	ans=1e9;
	dfs(1,0);
	printf("%d\n",ans);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cid=read(),T=read();
	while(T--) solve();
	return 0;
}
