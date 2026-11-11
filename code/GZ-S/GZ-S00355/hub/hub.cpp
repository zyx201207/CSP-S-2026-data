//观山湖中学 梁洪锐 GZ-S00355 
#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define endl '\n'
using namespace std;
const int N=1e5+5,inf=0x3f3f3f3f,mod=1e9+7;
const ll INF=0x3f3f3f3f3f3f3f3f;
int depth;
void dfs(int u,int p,int deep,vector< vector<int> >g){
	depth=max(depth,deep);
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==p){
			continue;
		}
		dfs(v,u,deep+1,g);
	}
}
void solve(){
	int n,k;
	cin>>n>>k;
	vector< vector<int> >g(n+1);
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int ans=inf;
	for(int i=1;i<=n;i++){
		int d=0;
		for(int j=1;j<=n;j++){
			dfs(i,0,0,g);
			d=depth;
			depth=0;
			dfs(j,0,0,g);
			d=max(depth,d);
		}
		ans=min(ans,d);
	}
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int t=1,c;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
