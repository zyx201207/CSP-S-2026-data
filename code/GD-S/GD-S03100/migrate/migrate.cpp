#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll maxn=2e6+10;
vector<ll> a[maxn];
ll n,m,dist[maxn],fan[maxn],x[maxn],c,t;
void bfs(ll u){
	memset(dist,0x3f,sizeof(dist));
	dist[u]=0;
	queue<ll> q;
	q.push(u);
	while(!q.empty()){
		ll u1=q.front();
		q.pop(); 
		for(ll v:a[u1]){
			q.push(v);
			dist[v]=min(dist[v],dist[u1]+1);
		}
	}
}
void dfs(ll u,ll move){
	if(move==dist[u]) fan[u]++;
	for(ll v:a[u]){
		dfs(v,move+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(fan,0,sizeof(fan));
		memset(a,0,sizeof(a));
		ll ans=0;
		cin>>n>>m;
		for(ll i=1;i<=n;i++) cin>>x[i];
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=i+m;j++){
				if(j>n) break;
				a[x[i]].push_back(x[j]);
			}
		}
		for(ll i=1;i<=n;i++){
			bfs(i);
			memset(fan,0,sizeof(fan));
			dfs(i,0);
			for(ll j=1;j<=n;j++) if(fan[j]==2) ans++;	
		}
		cout<<ans<<endl; 
	}
	return 0;
}
