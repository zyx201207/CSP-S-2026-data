#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define endl '\n'
using namespace std;
int read();
const int N=1e6+10,inf=1e18;
int c,T,n,k,fa[N],minn[N],ans;
PII a[N];
bool vis[N];
vector<int> e[N];
inline int find(int x) {
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
inline bool check() {
	int sum=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<n;i++) {
		int u=a[i].first,v=a[i].second;
		if(!vis[u] || !vis[v]) continue;
		u=find(u),v=find(v);
		if(u!=v) sum++,fa[u]=v;
	}
	return (k-sum<=2);
}
inline void dfs1(int u,int fa,int d) {
	minn[u]=min(minn[u],d);
	for(int i=0;i<(int)e[u].size();i++) {
		int v=e[u][i];
		if(v!=fa) dfs1(v,u,d+1);
	}
} 
inline void dfs(int u,int sum) {
	if(sum>k) return;
	if(u>n) {
		if(sum!=k || !check()) return;
		for(int i=1;i<=n;i++) minn[i]=inf;
		for(int i=1;i<=n;i++) if(vis[i]) dfs1(i,i,0);
		int maxx=0;
		for(int i=1;i<=n;i++) maxx=max(maxx,minn[i]);
		ans=min(ans,maxx);
		return;
	}
	dfs(u+1,sum);
	vis[u]=true,dfs(u+1,sum+1),vis[u]=false;
}
inline void solveA() {
	n=read(),k=read(),ans=inf;
	for(int i=1;i<n;i++) read(),read();
	int m=n/2;
	if(k==2*m+1) cout<<0<<endl;
	else if(k>=m) cout<<1<<endl;
	else {
		int op=(m-k+3)/4;
		cout<<op+1<<endl;
	}
}
inline void solve() {
	n=read(),k=read(),ans=inf;
	for(int i=1;i<=n;i++) e[i].clear();
	for(int i=1;i<n;i++) {
		int u=read(),v=read();
		a[i].first=u,a[i].second=v;
		e[u].push_back(v),e[v].push_back(u);
	}
	dfs(1,0);
	cout<<ans<<endl;
}
signed main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),T=read();
	if(c==13 || c==14) while(T--) solveA();
	else while(T--) solve();
	return 0;
}
int read() {
	int Ca=0;char Cr=' ';int Cf=1;
	while(Cr<'0' || Cr>'9') {Cr=getchar();if(Cr=='-') Cf=-1;}
	while(Cr>='0' && Cr<='9') {Ca=(Ca<<3)+(Ca<<1)+Cr-48,Cr=getchar();}
	return Ca*Cf;
}

