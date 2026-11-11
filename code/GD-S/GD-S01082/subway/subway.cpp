#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PII pair<ll,ll>
using namespace std;
const int N = 510,M = 5000010;
const ll inf = 1e18;
int c,n,m,d,q,T;
ll w[M];
vector<PII>g[N];
ll ans;
ll a[M],t[M];
bool st[M];
ll dis[M];
void bfs(int s){
	for(int i = 1;i <= m;i++){
		st[i] = false;
		dis[i] = inf;
	}
	queue<int>q;
	q.push(s);
	st[s] = true;
	dis[s] = 0;
	while(q.size()){
		int x = q.front();
		q.pop();
		for(PII nw:g[x]){
			ll y = nw.first,z = nw.second;
			if(st[y])continue;
			st[y] = true;
			dis[y] = dis[x]+z;
			q.push(y);
		}
	}
}
void Dijkstra(int s){
	for(int i = 1;i <= m;i++){
		st[i] = false;
		dis[i] = inf;
	}
	priority_queue<PII,vector<PII>,greater<PII> >heap;
	dis[s] = 0;
	heap.push({0,s});
	while(heap.size()){
		PII top = heap.top();
		heap.pop();
		int x = top.second;
		if(st[x])continue;
		st[x] = true;
		for(PII nw:g[x]){
			ll y = nw.first,z = nw.second;
			if(dis[y]>dis[x]+z){
				dis[y] = dis[x]+z;
				heap.push({dis[y],y});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	bool f = true;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)cin >> w[i];
	int p = m+1;
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		for(int j = 1;j <= k;j++){
			cin >> a[j] >> t[j];
		}
		T = t[1];
		g[p].push_back({a[1],t[1]});
		g[a[1]].push_back({p,t[1]});
		p++;
		for(int j = 2;j <= k;j++){
			g[p].push_back({p-1,0});
			g[p-1].push_back({p,0});
			g[p].push_back({a[j],t[j]});
			g[a[j]].push_back({p,t[j]});
			p++;
			if(T!=t[j])f = false;
		}
	}
	m+=p-1;
	while(q--){
		int x,y;
		cin >> x >> y;
		ans = w[x]+w[y];
		if(f)bfs(x);
		else Dijkstra(x);
		ans+=dis[y];
		cout << ans << endl;
	}
	return 0;
}
