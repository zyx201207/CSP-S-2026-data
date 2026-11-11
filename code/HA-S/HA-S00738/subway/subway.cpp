#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
using namespace std;
vector<pair<ll,ll> > v[500005];
ll a[500005];
ll ans=1e17;
ll s,e;
bool vis[500005];
void dfs(ll x,ll sum){
	sum+=a[x];
	if(sum>=ans){
		return ;
	}
	if(x==e){
		ans=min(sum,ans);
		return ;
	}
	vis[x]=1;
	for(int i=0;i<v[x].size();i++){
		if(vis[v[x][i].f]!=1){
			dfs(v[x][i].f,sum+v[x][i].s);
		}
	}
	vis[x]=0;
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll c, n,m, d, q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) {
		ll x;
		cin>>x;
		for(int j=1; j<=x; j++) {
			int f,e;
			cin>>f>>e;
			v[i].push_back({f,e});
		}
	}
	for(int i=1; i<=q; i++) {
		cin>>s>>e;
		dfs(s,0);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

