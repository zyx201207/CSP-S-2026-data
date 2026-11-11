//32pts~60pts
//坏菜了我所有巧克力被我吃完了
//呜呜呜 
#include<bits/stdc++.h>
using namespace std;
const int N=6e5+5;
const int M=5e5+5;
const int K=505;
const long long INF=1e18;
long long dis[N];
int c,n,m,d,q,x,w[M],k[K];
struct node{
	int v;
	long long w;
	bool operator<(const node &other)const{
		return w<other.w;
	}
};
vector<node> a[N];
int Dijkstra(int st,int en) {
	for (int i=1;i<=n+m;i++) {
		dis[i]=INF;
	}
	priority_queue<node> pq;
	pq.push({st,0});
	while (!pq.empty()) {
		int u=pq.top().v;
		int w=pq.top().w;
		pq.pop();
		for (auto i:a[u]) {
			if (i.w+w<dis[i.v]) {
				dis[i.v]=i.w+w;
				pq.push({i.v,dis[i.v]});
			}
		}
	}
	return dis[en];
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for (int i=1;i<=m;i++) {
		cin >> w[i];
	} 
	for (int i=1;i<=n;i++) {
		cin >> k[i];
		for (int j=1;j<=k[i];j++) {
			int x,y;
			cin >> x >> y;
			a[x].push_back({m+i,y});
			a[m+i].push_back({x,y});
		}
	}
	while (q--) {
		int s,e;
		cin >> s >> e;
		cout << Dijkstra(s,e)+w[s]+w[e] << endl;
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
