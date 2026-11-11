#include<bits/stdc++.h>
using namespace std;
int n,k;
const int N=1010;
const int inf=1e9;
vector<int> e[N];
int vis[N],flag[N],dis[N];
inline int read() {int x;cin>>x;return x;}
void bfs(int x) {
	queue<int> q;
	q.push(x);
	while(q.size()) {
		int x=q.front();q.pop();
		for(auto y:e[x]) {
			if(!vis[y]) continue;
			if(flag[y]) continue;
			flag[y]=1;
			q.push(y);
		}
	}
}
int get_ans() {
	queue<int> q;
	for(int i=1;i<=n;i++) {
		dis[i]=inf;
		if(vis[i]) {
			q.push(i);
			dis[i]=0;
		}
	}
	while(q.size()) {
		int x=q.front();q.pop();
		for(auto y:e[x]) {
			if(dis[y]!=inf) continue;
			dis[y]=dis[x]+1;
			q.push(y);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++) {
		ans=max(ans,dis[i]);
	}
	return ans;
} 
void work() {
	n=read();k=read();
	for(int i=1;i<=n;i++) {
		e[i].clear();
	}
	for(int i=1;i<n;i++) {
		int u,v;
		u=read();v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}  
	int ans=inf;
	for(int i=1;i<(1<<n);i++) {
		if(__builtin_popcount(i)!=k) continue;
		for(int j=1;j<=n;j++) {
			flag[j]=0;vis[j]=(i>>(j-1))&1;
		} 
		int cnt=0;
		for(int j=1;j<=n;j++) {
			if(vis[j]&&(!flag[j])) {
				bfs(j);
				cnt++;
			}
		}
		if(cnt>2) continue; 
		int x=get_ans();
		ans=min(ans,x);
	}
	cout<<ans<<endl;
}
signed main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,t; 
	c=read();t=read();
	while(t--) work();
	return 0;
}
/*

*/
