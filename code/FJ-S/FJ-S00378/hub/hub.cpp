#include<bits/stdc++.h>
#define int long long
using namespace std;
int C;
vector<int>ve[1000005];
int n,k;
int fa[1000005];
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int dfs(int x,int fa,int p){
	if((p>>(x-1))&1)return 0;
	int ans=1e9;
	for(int i:ve[x])
	if(i!=fa)ans=min(ans,dfs(i,x,p));
	ans++;
	return ans;
}
void print(int x){
	while(x){
		cout<<x%2;
		x>>=1;
	}
	cout<<' ';
}
void sol(){
	int ret=n;
	for(int i=1;i<(1<<n);i++){
		if(__builtin_popcount(i)!=k)continue;
		for(int j=1;j<=n;j++)fa[j]=j;
		for(int j=1;j<=n;j++)
		if((i>>(j-1))&1)
		for(int k:ve[j])
		if((i>>(k-1))&1)fa[find(j)]=find(k);
		int qwq=0;
		for(int j=1;j<=n;j++)
		if(j==find(j)&&((i>>(j-1))&1))qwq++;
		if(qwq>2)continue;
		int ans=0;
		for(int j=1;j<=n;j++)
		ans=max(ans,dfs(j,0,i));
		ret=min(ret,ans);
	}
	cout<<ret<<'\n';
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	ve[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		ve[u].push_back(v);
		ve[v].push_back(u);
	}
	if(C<=3)sol();
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t=1;
	cin>>C>>t;
	while(t--)solve();
	return 0;
}
