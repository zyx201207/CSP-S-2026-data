#include <bits/stdc++.h>
using namespace std;
#define ll long long
int read(){
	int x=0,f=1; char h=getchar();
	while(!isdigit(h)){if(h=='-') f=-f; h=getchar();}
	while(isdigit(h)){x=(x<<3)+(x<<1)+(h^48); h=getchar();}
	return x*f;
}
const int N=1e6+10;
const int INF=1e9+7;
int n,k,dis[N];
bool is[N],vis[N];
vector<int> e[N];
void dfs(int u){
	vis[u]=1;
	for(auto &v:e[u]){
		if(is[v]&&!vis[v]) dfs(v);
	}
}
void solve(){
	int n=read(),k=read();
	for(int i=1;i<=n;i++) e[i].clear();
	for(int i=1;i<n;i++){
		int u=read(),v=read();
		e[u].push_back(v),e[v].push_back(u);
	}
	int ans=INF;
	for(int base=1;base<(1<<n);base++){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if((base>>(i-1))&1) is[i]=1,cnt++;
			else is[i]=0;
			vis[i]=0,dis[i]=INF;
		}
		if(cnt!=k) continue;
		int tot=0;
		for(int i=1;i<=n;i++) if(is[i]&&!vis[i]) dfs(i),tot++;
		if(tot>2) continue;
		queue<int> q;
		for(int i=1;i<=n;i++) if(is[i]) q.push(i),dis[i]=0;
		while(q.size()){
			int u=q.front(); q.pop();
			for(auto &v:e[u]){
				if(dis[v]==INF) dis[v]=dis[u]+1,q.push(v);
			}
		}
		int res=0;
		for(int i=1;i<=n;i++) res=max(res,dis[i]);
		ans=min(ans,res);
	}
	printf("%d\n",ans);
}
signed main(){
//	freopen("D:/csps-new/down/hub/hub2.in","r",stdin);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=read(),T=read();
	while(T--) solve();	
	return 0;
}
/*

*/
