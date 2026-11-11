#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int M=5e5+50;
int c,n,m,d,q;
int w[M],k[505];
int Head[M],Nxt[M],val[M],To[M],dist[505][505];
//dist[cxy][zmjjkk]
int cnt;
int x[M/5],y[M/5];
struct Node {
	int U,V,Val;
	bool operator < (const Node& a) const
	{
		return a.Val<Val;
	}
};
priority_queue <Node> pq;

void add (int u,int v,int w) {
	To[++cnt]=v;
	Nxt[cnt]=u;
	val[cnt]=w;
	Head[u]=cnt;
}

void dijkstra (int x,int y) {
	dist[y][x]=0;
	pq.push({x,0});
	int u=pq.top().U;
	pq.pop();
	for (int k=Head[u];k;k=Nxt[k]) {
		int v=To[k];
		if (dist[u][v]>dist[u][k]+v) {
			dist[u][v]=dist[u][k]+v;
			pq.push({v,dist[u][v]});
		}
	}
	printf("%d\n",pq.top().Val+w[x]+w[y]);
}

int main () {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for (int i=1;i<=m;i++)
		scanf("%d",&w[i]);
	vector <int> a[505];
	vector <int> t[505];
	for (int i=1;i<=n;i++) {
		scanf("%d",&k[i]);
		for (int j=1,A,T;j<=k[i];j++) {
			scanf("%d %d",&A,&T);
			a[i].push_back(A);
			t[i].push_back(T);
		}
	}
	for (int r=1;r<=q;r++) 
		scanf("%d %d",&x[r],&y[r]);
	for (int i=1;i<=n;i++) {
		for (int j=2;j<=k[i];j++) {
			add(a[i][j-1],a[i][j],t[i][j-1]+t[i][j]);
		}
	}
	for (int r=1;r<=q;r++) {
		dijkstra(x[r],y[r]);
		while (!pq.empty()) pq.pop();
		memset(dist,0,sizeof(dist));
	}
	return 0;
}
