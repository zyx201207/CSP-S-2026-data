#include<bits/stdc++.h>
#define N 500000
#define M 2000000
using namespace std;
using ll = long long;
ll c,n,m,d,q;
ll dd[1005][1005];
ll W[500005];
ll w[M],to[M],nxt[M],tot=0,head[600000];
void add(int u,int v,int val){
	to[++tot] = v;
	nxt[tot] = head[u];
	head[u] = tot;
	w[tot] = val;
	
	to[++tot] = u;
	nxt[tot] = head[v];
	head[v] = tot;
	w[tot] = val;
	return;
}
ll dis[N+600];
void Dijkstra(ll s){
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
	fill(dis+1,dis+N+n+1,INT_MAX);
	dis[s] = 0;
	q.push({0*1LL,s});
	while(!q.empty()){
		ll d = q.top().first,u = q.top().second;
		q.pop();
//		cout<<d<<" "<<u<<endl;
//		for(int i = 1;i <= m;i ++){
//			cout<<i<<":"<<((dis[i]==2147483647) ? 0 : dis[i])<<" ";
//		}for(int j = 1;j <= n;j ++){
//			cout<<j+N<<":"<<((dis[j+N]==2147483647) ? 0 : dis[j+N])<<" ";
//		}cout<<endl;
		if(d != dis[u])continue;
		
		for(ll i = head[u];i != -1;i = nxt[i]){
			ll v = to[i],val = w[i];
//			cout<<u<<" "<<v<<" "<<val<<" "<<dis[v]<<" "<<d+val<<" \n";
			if(dis[v] > d + val){
				dis[v]=d+val;
				q.push({dis[v],v});
			}
		}
	}return;
}
void bfs(ll s,ll e){
	queue<int> q;
	q.push(s);
	fill(dis+1,dis+N+n+1,INT_MAX);
	dis[s] = 0;
	while(!q.empty()){
		ll u = q.front();
		q.pop();
		if(u == e){
			cout<<dis[e]*w[1]+W[e]+W[s]<<"\n";
			break;
		}
		for(ll i = head[u];i != -1;i = nxt[i]){
			ll v = to[i];
			if(dis[v] == INT_MAX){
				dis[v] = dis[u]+1;
				q.push(v);
			}
		} 
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i = 1;i <= m;i ++){
		cin>>W[i];
	}memset(head,-1,sizeof(head));
	for(ll i = 1;i <= n;i ++){
		ll k,a,t;
		cin>>k;
		for(ll j = 1;j <= k;j ++){
			cin>>a>>t;
			add(i+N,a,t);
		}
	}
	if(c <= 8){
		ll x,y;
		for(ll i = 1;i <= q;i ++){
			cin>>x>>y;
			Dijkstra(x);
			cout<<dis[y]+W[x]+W[y]<<"\n";
		}
	}else 
	if(c <= 11){
		for(int i = 1;i <= m;i ++){
			Dijkstra(i);
			for(int j = 1;j <= m;j ++){
				dd[i][j] = dis[j];
			}
		} for(int i = 1;i <= q;i ++){
			ll x,y;
			cin>>x>>y;
			cout<<dd[x][y]+W[x]+W[y]<<"\n";
		}
	}else if(c <= 19){
		for(int i = 1;i <= q;i ++){
			ll x,y;
			cin>>x>>y;
			bfs(x,y);
		}
	}
	return 0;
}

