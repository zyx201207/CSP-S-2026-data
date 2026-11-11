#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int S=2e6+7,  Q=1e5+7;
int C, n, m, d, T;
int h[S], to[S], nxt[S], ct;
ll val[S], w[S], ans[Q];
//前 m 个：站点节点，后 n 个：路线节点
void add(int a, int b, ll c) {
	to[++ct]=b, val[ct]=c;
	nxt[ct]=h[a], h[a]=ct;
}
struct Node { ll w;int num; };
struct Heap {
	Node hp[S];int len;
	Heap() { len=0;
	} void Clear() { len=0;
	} Node Top() { return hp[1];
	} bool Empty() { return len==0;
	} void Push(Node x) {
		hp[++len]=x;
		int son=len;
		while(son>1 && hp[son].w<hp[son>>1].w)
			swap(hp[son], hp[son>>1]), son>>=1;
	} void Pop() {
		hp[1]=hp[len--];
		int fa=1;
		while(fa<=(len>>1)) {
			int son=fa<<1;
			if(son<len && hp[son+1].w<hp[son].w) son++;
			if(hp[son].w<hp[fa].w)
				swap(hp[son], hp[fa]), fa=son;
			else break;
		}
	}
} q;
//询问离线 
struct Node2 { int s, t, num;
} qry[Q], tmp[Q];
void Merge(Node2 *sq, int l, int r, Node2 *c) {
	int mid=(l+r)>>1, i=l, j=mid+1, k=l;
	while(i<=mid && j<=r)
		if(sq[j].s<sq[i].s) c[k++]=sq[j++];
		else c[k++]=sq[i++];
	for(; i<=mid; ) c[k++]=sq[i++];
	for(; j<=r; ) c[k++]=sq[j++];
}
void Merge_Sort(Node2 *sq, int l, int r) {
	if(r-l<1) return;
	int mid=(l+r)>>1;
	Merge_Sort(sq, l, mid);
	Merge_Sort(sq, mid+1, r);
	Merge(sq, l, r, tmp);
	for(int i=l; i<=r; i++) sq[i]=tmp[i];
}
bool vis[S];
ll dis[S];
void Dijkstra(int s, int hd) {
	for(int i=0; i<=n+m; i++)
		dis[i]=1e18, vis[i]=0;
	q.Clear(), dis[s]=0;
	q.Push(Node {0, s});
	while(!q.Empty()) {
		int x=q.Top().num;
		q.Pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=h[x]; i; i=nxt[i])
			if(dis[x]+val[i]<dis[to[i]]) {
				dis[to[i]]=dis[x]+val[i];
				q.Push(Node {dis[to[i]], to[i]});
			}
	}
	for(int i=hd; qry[i].s==qry[hd].s; i++)
		ans[qry[i].num]=dis[qry[i].t]+w[s]+w[qry[i].t];
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &C, &n, &m, &d, &T);
	for(int i=1; i<=m; i++)
		scanf("%lld", &w[i]);
	for(int i=1, k; i<=n; i++) {
		scanf("%d", &k);
		for(int j=1, a, t; j<=k; j++) {
			scanf("%d%d", &a, &t);
			add(i+m, a, t), add(a, i+m, t);
		}
	}
	for(int i=1; i<=T; i++) qry[i].num=i,
		scanf("%d%d", &qry[i].s, &qry[i].t);
	Merge_Sort(qry, 1, T);
	for(int i=1; i<=T; i++)
		if(qry[i].s!=qry[i-1].s)
			Dijkstra(qry[i].s, i);
	for(int i=1; i<=T; i++)
		printf("%lld\n", ans[i]);
	return 0;
}
