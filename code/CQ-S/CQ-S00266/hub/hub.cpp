#include<bits/stdc++.h>
const int QWQ=1e6+5;
using namespace std;
using LL=long long;
template<typename T=int>
inline T read(){
	T x=0; int f=1; char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar())
		if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+(ch^48);
	return x*f;
}
int Tp,T,n,k,ans;
vector<int> E[QWQ];
struct edge{ int u,v; } e[33];
int cs[33],Fa[33],d[33];
int get(int k){
	return Fa[k]==k ? k:Fa[k]=get(Fa[k]);
}
void dfs(int u,int s){
	if (s>k) return ;
	if (u>n){
		if (s<k) return ;
		iota(Fa+1,Fa+n+1,1);
		for (int i=1;i<n;i++){
			auto [u,v]=e[i];
			if (cs[u]&&cs[v]) Fa[get(v)]=get(u);
		}
		int cc=0;
		for (int i=1;i<=n;i++) if (cs[i]&&get(i)==i) cc++;
		if (cc>2) return ;
		for (int i=1;i<=n;i++) d[i]=-1;
		queue<int> q;
		for (int i=1;i<=n;i++) if (cs[i]) d[i]=0,q.push(i);
		for (;!q.empty();){
			int u=q.front(); q.pop();
			for (int v:E[u]) if (!~d[v]) d[v]=d[u]+1,q.push(v);
		}
		ans=min(ans,*max_element(d+1,d+n+1));
		return ;
	}
	cs[u]=1,dfs(u+1,s+1);
	cs[u]=0,dfs(u+1,s);
}
inline void solve(){
	n=read(),k=read();
	for (int i=1;i<=n;i++) E[i].clear();
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		E[x].push_back(y);
		E[y].push_back(x);
		if (n<=10) e[i]={x,y};
	}
	ans=n+1,dfs(1,0),printf("%d\n",ans);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	for (Tp=read(),T=read();T--;) solve();
	return 0;
}
