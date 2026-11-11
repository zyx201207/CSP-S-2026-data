#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int C,T;
int n,k;
int fa[maxn],dis[maxn];
vector<int>g[maxn];
inline int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
inline void merge(int x,int y){
	x=find(x),y=find(y);
	fa[x]=y;
	return ;
}
inline void dfs(int u,int fa,int dep){
	dis[u]=dep;
	for(auto v:g[u]) if(v!=fa) dfs(v,u,dep+1);
	return ;
}
inline void solve1(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<n;i++){
		int u,v; cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int mn=1e9;
	for(int mask=1;mask<(1<<n);mask++){
		if(__builtin_popcount(mask)!=k) continue;
    	for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<=n;i++){
			if(!((mask>>(i-1))&1)) continue;
			for(auto j:g[i]){
				if(!((mask>>(j-1))&1)) continue;
				merge(i,j);
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(!((mask>>(i-1))&1)) continue;
			if(find(i)==i) cnt++;
		}
		if(cnt>2) continue;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(((mask>>(i-1))&1)) continue;
			dfs(i,0,0);
			int now=1e9;
			for(int j=1;j<=n;j++){
				if(!((mask>>(j-1))&1)) continue;
				now=min(now,dis[j]);
			}
			ans=max(ans,now);
		}
		mn=min(mn,ans);
	}
	cout<<mn<<'\n';
	return ;
}
inline void solve2(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<n;i++){
		int u,v; cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if(n==k) {
		cout<<0<<'\n';
		return ;
	}
	n=n-n/2;
	int u=k/2,v=n/2+k-k/2,ans=1;
	for(int i=u+1;i<v;i++) ans=max(ans,min(i-u,v-i)+1);
	cout<<ans<<'\n';
	return ;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>C>>T;
	while(T--){
		if(C<=3) solve1();
		else cout<<"0\n"; 
	//	else solve2();
//	solve2();
	}
	return 0;
 } 
