#include<bits/stdc++.h>
using namespace std;
using ll=int;
ll c,n,m,d,q,w[500005],ans[500005];
bool vis[500005];
struct node{
	ll x,y;
};
struct nodell{
	long long x,y;
};
vector<node> a[500005];
vector<node> b[505];
void solve(ll sx,ll tx){
	ll base=w[sx]+w[tx];
	queue<nodell> q;
	q.push({sx,0});
	vis[sx]=1;
	while(!q.empty()){
		ll x=q.front().x,y=q.front().y;
		q.pop();
		ans[x]=y;
		for(auto i:a[x]){
			for(auto j:b[i.x]){
				if(vis[j.x]) continue;
				vis[j.x]=1;
				q.push({j.x,y+i.y+j.y});
			}
		}
	}
	cout<<ans[tx]+base<<'\n';
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(ll j=1;j<=k;j++){
			ll x,y;
			cin>>x>>y;
			a[x].push_back({i,y});
			b[i].push_back({x,y});
		}
	}
	while(q--){
		ll x,y;
		cin>>x>>y;
		memset(vis,0,sizeof(vis));
		solve(x,y);
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
