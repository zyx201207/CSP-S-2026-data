#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct z{
	ll line,wi;
};
ll w[500005],n,m,c,d,q;
vector<z>vt[500005];
vector<ll>l[5005];
ll en,ans=1e18;
ll vis[500005];
ll zz[500005];
void dfs(ll u,ll line,ll sum){
	if(u==en){
		ans=min(ans,sum);
		return;
	}
	for(int i=0;i<l[line].size();i++){
		if(vis[l[line][i]]<d){
			vis[l[line][i]]++;
			dfs(l[line][i],line,sum);
			vis[l[line][i]]--;
		}
	}
	for(z x:vt[u]){
		if(zz[u]==0){
			zz[u]=1;
			dfs(u,x.line,sum+x.wi);
			zz[u]=0;
		}
	}
}
void solve(){
	ll st;cin>>st>>en;
	ans=1e18;
	for(z x:vt[st]){
		dfs(st,x.line,w[st]+w[en]); 
	}
	cout<<ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	bool A=1;
	for(int i=1;i<=n;i++){
		int x;cin>>x;int a,t;
		if(x>2)A=0;
		for(int j=1;j<=x;j++){
			cin>>a>>t;
			vt[a].push_back({i,t});
			l[i].push_back(a);
		}
	}
	while(q--){
		solve();
	}
	return 0;
}
