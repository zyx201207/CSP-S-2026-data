#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int N=5e5+10;
int w[N];
bool vis[N];
vector<pair<int,int> > tree[N];
int ans=INT_MAX;
void dfs(int u,int end,int dist){
	if(vis[u]=1) return;
	if(u==end){
		if(dist<ans){
			ans=dist;
		}
		return;
	}
	vis[u]=1;
	dist+=w[u];
	for(auto v:tree[u]){
		dfs(v.first,end,dist+v.second);
	}
	vis[u]=0;
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			tree[5000010+j].push_back({a,t});
			tree[a].push_back({5000010+j,t});
		}
	}
	while(q--){
		int s,e;
		cin>>s>>e;
	    dfs(s,e,0);
	    cout<<ans<<'\n';
	    ans=0;
	}
	return 0;
}
