#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5002;
int n;
ll d,a[maxn];
namespace Graph{
	int hd[maxn],cnt=0;
	inline void ini(){for(int i=1;i<=n;i++) hd[i]=0;cnt=0;}
	struct edge{int to,nxt;}e[maxn*maxn];
	inline void ade(int from,int to){e[++cnt]={to,hd[from]},hd[from]=cnt;}
}using namespace Graph;
int dep[maxn],p[maxn];
bool vis[maxn];
queue<int> pq;
void bfs(int st){
	for(int i=1;i<=n;i++) vis[i]=0,dep[i]=p[i]=0;
	pq.push(st);
	vis[st]=1;
	while(!pq.empty()){
		int u=pq.front();pq.pop();
		for(int i=hd[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(vis[v]) continue;
			vis[v]=1,pq.push(v),dep[v]=dep[u]+1;
		}
	}
}
void dfs(int u){
	p[u]++;
	for(int i=hd[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(dep[v]==dep[u]+1) dfs(v);
	}
}
void Doru(){
	cin>>n>>d;
	ini();
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]>a[i]+d) break;
			ade(i,j);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		bfs(i),dfs(i);
		for(int j=i+1;j<=n;j++) ans+=(p[j]==2);
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--) Doru();
	return 0;
}

