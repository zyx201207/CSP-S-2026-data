#include<bits/stdc++.h>
#define PII pair<int,long long>
using namespace std;
const int N = 505, M = 1e3+10;
int c, n, m, d, q;
long long w[M];

vector<PII>g[N*M];

//g[i][j]->i*n+j;
//i*n+j=x -> (x-1)%n+1=j, (x-1)/n=i;
int p(int x){
	return (x-1)/m;
}
int vi(int x){
	return (x-1)%m+1;
}
int vis[N*M];
long long dis[N*M];
priority_queue<PII, vector<PII>, greater<PII> > qu;
long long dij(int start, int end){
	qu.push({0, start});
	dis[start] = w[start];
	while(!qu.empty()){
		int u = qu.top().second;
		long long dis_in = qu.top().first;
		qu.pop();
		vis[u] = 1;
		if(dis_in>dis[u]) continue;
		for(auto x:g[u]){
			int v = x.first;
			long long w_h = x.second;
			if(vis[v]) continue;
			if(dis[v]>=dis[u]+w_h){
				dis[v] = dis[u]+w_h;
				qu.push({dis[v], v});
			}
		}
	}
	return dis[end]+w[end];
}

void add(int p1, int v1, int p2, int v2, long long w_h){
	g[(p1)*m+v1].push_back({(p2)*m+v2, w_h});
	g[(p2)*m+v2].push_back({(p1)*m+v1, w_h});
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++) cin >> w[i];
	int k, last_a, now_a;
	long long t;
	for(int i=1;i<=n;++i){
		cin >> k;
		last_a = 0;
		for(int j=1;j<=k;++j){
			cin >> now_a;
			cin >> t;
			if(last_a!=0) add(i, last_a, i, now_a, 0);
			add(0, now_a, i, now_a, t);
			last_a = now_a;
		}
	}
	int x, y;
	for(int i=1;i<=q;i++){
		memset(dis, 0x3f, sizeof dis);
		memset(vis, 0, sizeof vis);
		cin >> x >> y;
		cout << dij(x, y) << endl;
	}
	return 0;
}
