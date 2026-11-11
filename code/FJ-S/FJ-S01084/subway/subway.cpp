#include<bits/stdc++.h>
using namespace std;
const int maxn = 505,maxm = 3 * 1e5 + 5;
int c,n,m,d,p;
int w[maxm],k[maxn];
int a[maxn][maxm],t[maxn][maxm];
int dis[maxn];
bool vis[maxn];
int prict[maxn];
vector<int>v[maxn];
const int inf = 1e5 + 5;
int ver[maxn],edge[maxn],nxt[maxn],head[maxn];
int tot = 0;
void add(int x,int y,int z) {
	ver[++tot] = y,edge[tot] = z,nxt[tot] = head[x],head[x] = tot;
}
void dijastra(int s) {
	for(int i = 1;i <= n;i++) vis[i] = false;
    for(int i = 1;i <= n;i++) dis[i] = 1005;
	cout << dis[2] << endl;
	dis[s] = 0;
	priority_queue<pair<int,int> >q;
	q.push({0,s});
	while(!q.empty()) {
		int x = q.top().second;
		q.pop();
		if(vis[x]) continue;
		vis[x] = true;
		for(int i = head[x];i;i = nxt[x]) {
			int u = ver[i],w = edge[i];
			if(dis[u] > dis[i] + w) {
				dis[u] = dis[i] + w;
				q.push({-dis[u],u});
			}
		}
	}
	
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin >> c >> n >> m >> d >> p;
	for(int i = 1;i <= m;i++) {
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++) {
		cin >> k[i];
		for(int j = 1;j <= k[i];j++) {
			cin >> a[i][j] >> t[i][j];
			v[i].push_back(a[i][j]);
			prict[a[i][j]] += t[i][j];
		}
	}
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= v[i].size();j++) {
			for(int k = j + 1;k <= v[i].size();k++) {
				add(j,k,prict[j] + prict[k]);
				add(k,j,prict[j] + prict[k]);
			}
		}
	}
	while(p--) {
		int s,e;
		cin >> s >> e;
		dijastra(s);
		cout << w[s] + dis[e] + w[e] << endl;
	}
	return 0;
}
/*
4 3
1 2 3
2 4 5
3 4 6
*/
