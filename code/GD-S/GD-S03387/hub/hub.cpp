#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+10;
ll n,k,vis[N],dis[N];
vector<ll> v[N];
void bfs(ll s){
	queue<ll> q;
	for(int i=1;i<=n;i++){
		vis[i]=0;
		dis[i]=INT_MAX;
	}
	for(int i=1;i<=n;i++){
		if(((s>>(i-1))&1)==1){
			q.push(i);
			dis[i]=0,vis[i]=1;
		}
	}
	while(!q.empty()){
		ll u=q.front();
		q.pop();
		for(auto nx:v[u]){
			if(vis[nx]) continue ; 
//			cout << nx << " " << u << " " << dis[nx] << "\n";
			dis[nx]=dis[u]+1;
			vis[nx]=1;
			q.push(nx); 
		}
	} 
	return ;
}
void solve(){
	cin >> n >> k;
	for(int i=1;i<n;i++){
		ll x,y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	ll ans=INT_MAX;
	for(int i=1;i<(1ll<<n);i++){
		ll cnt=__builtin_popcount(i);
		if(cnt!=k) continue ;
		bfs(i);
		ll maxx=0;
		vector<ll> v;
		for(int j=1;j<=n;j++){
			if(((i>>(j-1))&1)==1){
				v.push_back(j);
				continue ;
			}
			maxx=max(maxx,dis[j]);
		}
//		cout << i << " " << maxx << "\n";
//		if(maxx==1){
//			for(auto x:v){
//				cout << x << " ";
//			}
//			cout << "\n";
//			for(int i=1;i<=n;i++){
//				cout << dis[i] << " ";
//			}
//			cout << "\n";
//		}
		ans=min(ans,maxx);
	}
	for(int i=1;i<=n;i++) v[i].clear(); 
	cout << ans << "\n";
}
ll c,T=1;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> c >> T;
	while(T--) solve();
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
