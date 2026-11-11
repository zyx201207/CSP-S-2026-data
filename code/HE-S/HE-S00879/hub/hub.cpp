#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10;
int c,_,k,n,ans=INT_MAX;
int fa[N],a[N];
vector<int>g[N];
bool f[N],f1[N];
inline int find1(int u){
	if(fa[u]==u)return u;
	return fa[u]=find1(fa[u]);
}
inline int dfs2(int u,int v,int sum,int ans){
	if(sum>ans)return ans;
	if(u==v)return sum;
	for(auto it:g[u]){
		if(f1[it])continue;
		f1[it]=1;
		ans=min(ans,dfs2(it,v,sum+1,ans));
	}
	return ans;
}
inline void chuli(){
	int cnt=0,tot=0;
	for(int i=1;i<=k;i++)f[a[i]]=1;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=k;j++){
			if(find1(a[i])==find1(a[j]))continue;
			cnt++;
		}
	}
	if(cnt>2)return ;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			int sum=0;
			if(f[i]){
				sum=0;
				continue;
			}
			for(int i=1;i<=n;i++)f1[i]=0;
			sum=dfs2(i,a[j],0,INT_MAX);
			tot=max(tot,sum);
		}
	}
	ans=min(ans,tot);
	for(int i=1;i<=n;i++)f[i]=0;
}
inline void dfs(int x,int xia){
	if(x==k){
		chuli();
		return ;
	}
	for(int i=xia+1;i<=n;i++){
		a[x+1]=i;
		dfs(x+1,i);
		a[x+1]=0;
	}
	return ;
}
inline void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=n-1;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
		fa[u]=v;
	}
	dfs(0,0);
	cout<<ans<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>_;
	while(_--){
		solve();
	}
	return 0;
}

