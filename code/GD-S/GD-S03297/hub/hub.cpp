#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,k;
vector<vector<int>> mp;
map<int,bool> vis;
int ans=LLONG_MAX;
map<int,bool> vis2;
int jl(int x,int y){
	if(x==y)
		return 0;
	int s=LLONG_MAX;
	for(auto it:mp[x]){
		if(vis2[it])
			continue;
		vis2[it]=1;
		s=min(s,jl(it,y)+1);
		vis2[it]=0;
	}
	return s;
}
void dfs(vector<int>& lis,int ltk){
	if(ltk>2)
		return;
	if(lis.size()==k){
		int s=-1;
		for(auto i:lis)
			for(auto j:lis)
				if(i!=j){
					vis2[i]=1;
					s=max(s,jl(i,j));
					vis2[i]=0;
				}
		ans=min(ans,s);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])
			continue;
		vis[i]=1;
		lis.push_back(i);
		dfs(lis,ltk+!(vis[i-1]+vis[i+1]));
		lis.erase(lis.end());
		vis[i]=0;
	}
}
void solve(){
	cin>>n>>k;
	mp.resize(n+1);
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	ans=LLONG_MAX;
	vector<int> lis;
	dfs(lis,0);
	cout<<ans<<'\n';
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
		solve();
	return 0;
}
