#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define gc getchar_unlocked
#define pc putchar_unlocked
inline ll read(){
	ll x=0,f=1;
	char ch=gc();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=gc();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=gc();
	}
	return x*f;
}
const int N=5e5+10;
ll c,n,m,d,q,w[N],dist[5010][5010];
vector<pair<ll,ll>>g[N];
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
bool vis[N];
inline void dijkstra(ll s){
	dist[s][s]=0;
	memset(vis,0,sizeof(vis));
	pq.push({0,s});
	while(!pq.empty()){
		ll u=pq.top().second;
		pq.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto it:g[u]){
			ll v=it.first,w=it.second;
			dist[s][v]=min(dist[s][v],dist[s][u]+w);
			pq.push({dist[s][v],v});
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(ll i=1;i<=m;i++){
		w[i]=read();
	}
	for(ll i=1;i<=n;i++){
		ll k=read();
		vector<ll>a(k+1),c(k+1);
		for(ll i=1;i<=k;i++){
			a[i]=read();
			c[i]=read();
		}
		for(ll i=1;i<=k;i++){
			for(ll j=1;j<=k;j++){
				if(i==j) continue;
				ll cost=c[i]+c[j];
				g[a[j]].push_back({a[i],cost});
			}
		}
	}
	memset(dist,0x3f,sizeof(dist));
	for(ll i=1;i<=m;i++){
		dijkstra(i);
	}
	while(q--){
		ll x=read(),y=read();
		cout<<min(dist[x][y],dist[y][x])+w[x]+w[y]<<'\n';
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
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
