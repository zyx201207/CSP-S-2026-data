#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define st stack
#define qu queue
#define qp priority_queue
#define qwq ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define N 100005
ll c,n,m,d,q;
ll w[N];
struct P{
	ll aa,tt;
};
vector<P> a[N];
ll b[N]={0}; 
ll dis[N]={0};
//从x站到第y站的最短路程 
ll dfs(ll x,ll y,ll ans){
	if(x==y){
		return ans;
	}
	if(dis[x]!=0){
		return 1e18;
	}else{
		dis[x]=1;
	}
	ll minn=1e18;
	for(ll i=1;i<=b[x];i++){
		minn=min(minn,a[x][i].tt+dfs(a[x][i].aa,y,ans+a[x][i].tt));
	}
	return minn;
}
void solve(ll x,ll y){
	for(ll i=1;i<=m;i++){
		dis[i]=0;
	}
	cout<<w[x]+w[y]+dfs(x,y,0)<<endl;
}
int main(){
	qwq;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++){
		ll k1=0;
		cin>>k1;
		ll a1[N]={0},t[N]={0};
		for(ll j=1;j<=k1;j++){
			cin>>a1[j]>>t[j];
		}
		for(ll j=1;j<=k1;j++){
			for(ll k=1;k<=k1;k++){
				if(j!=k){
					a[a1[j]].push_back({a1[k],t[k]});
					b[a1[j]]++;
				}
			}
		}
	}
	for(ll i=1;i<=q;i++){
		ll x,y;
		cin>>x>>y;
		solve(x,y);
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/

