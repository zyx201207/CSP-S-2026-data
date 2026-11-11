#include<bits/stdc++.h>
using namespace std;
const int inf = 1000000;
int c,n,m,d,Q;
int w[500010],k[510];
struct node {
	int to,l;
	node (int a,int b) {
		to = a,l = b;
	}
};
vector<node> edges1[500010];
vector<node> edges2[500010];
long long dist1[500010],dist2[500010];
int q[500010];
inline void bfs(int p) {
	dist2[p] = 0;
	int r = 0,f =1;
	q[++r] = p;
	while(f <= r) {
		int x = q[f++];
		if(x < inf) {
			for(int i = 0;i < edges2[x].size();i++) {
				node y = edges2[x][i];
				if(dist1[y.to] == -1 || dist1[y.to] > dist2[x] + y.l) {
					dist1[y.to] = dist2[x] + y.l;
					q[++r] = y.to + inf;
				}
			}
		} else {
			x -= inf;
			for(int i = 0;i < edges1[x].size();i++) {
				node y = edges1[x][i];
				if(dist2[y.to] == -1 || dist2[y.to] > dist1[x] + y.l) {
					dist2[y.to] = dist1[x] + y.l;
					q[++r] = y.to;
				}
			}
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> Q;
	for(int i = 1;i <= m;i++) {
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++) {
		cin >> k[i];
		for(int j = 1;j <= k[i];j++) {
			int x,y;
			cin >> x >> y;
			edges1[i].push_back(node(x,y));
			edges2[x].push_back(node(i,y));
		}
	}
	while(Q--) {
		int x,y;
		cin >> x >> y;
		long long ans = 0;
		ans += w[x] + w[y];
		memset(q,0,sizeof(q));
		memset(dist1,-1,sizeof(dist1));
		memset(dist2,-1,sizeof(dist2));
		bfs(x);
		ans += dist2[y];
		cout << ans << endl;
	}
	return 0;
}
