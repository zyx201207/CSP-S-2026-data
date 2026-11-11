#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#define N 1000005
#define ll long long
#define INF (ll)1e9
#define PII pair<ll, ll>
#define lowbit(x) (x&(-x))

using namespace std;
inline ll rd(){
	ll res=0, f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=0; ch=getchar(); }
	while(ch>='0'&&ch<='9') res=(res<<3)+(res<<1)+(ch^48), ch=getchar();
	return (f?res:-res);
}
int c, n, k, vis[N], tag[N], t[N], dis[N], ans, dep[N];
vector<int> e[N];
queue<int> q;
void find(int x){
	tag[x]=1;
	for(int y:e[x]) if(vis[y]&&!tag[y]) find(y);
}
void bfs(){
	for(int i=1; i<=n; i++){
		t[i]=0, dis[i]=INF;
		if(vis[i]) q.push(i), dis[i]=0;
	}
	while(!q.empty()){
		int x=q.front();
		q.pop();
		if(t[x]) continue;
		t[x]=1;
		for(int y:e[x]) if(!t[y]&&dis[y]>dis[x]+1) q.push(y), dis[y]=dis[x]+1;
	}
}
void dfs(int x, int cnt){
	if(x==n+1||cnt==k){
		if(cnt<k) return;
		for(int i=1; i<=n; i++) tag[i]=0;
		int tot=0;
		for(int i=1; i<=n; i++){
			if(vis[i]&&!tag[i]) find(i), tot++;
			if(tot>2) return;
		}
		bfs();
		int res=0;
		for(int i=1; i<=n; i++) res=max(res, dis[i]);
		ans=min(ans, res);
		return;
	}
	vis[x]=1, dfs(x+1, cnt+1);
	vis[x]=0, dfs(x+1, cnt);
}
void solve2(){
	ans=INF, dfs(1, 0), printf("%d\n", ans);
}
void solve(){
	n=rd(), k=rd();
	for(int i=1; i<=n; i++) e[i].clear();
	for(int i=1; i<n; i++){
		int u=rd(), v=rd();
		e[u].push_back(v), e[v].push_back(u);
	}
//	if(c==7||c==11||c==12) solve1();
//	else solve2();
	solve2(); 
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	c=rd();
	for(int tt=rd(); tt--; solve());

	return 0;
}
/*

*/

