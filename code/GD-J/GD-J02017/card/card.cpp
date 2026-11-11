#include<algorithm>
#include<cstdio>
using namespace std;
constexpr int N = 5e5 + 5, M = 1e6 + 5;
int a[N], n, m;
int head[N], nxt[M], to[M], dnt;
int pre[N];
void add_edge(int u, int v)noexcept{
	nxt[++dnt] = head[u];
	head[u] = dnt;
	to[dnt] = v, pre[v]++;
//	printf("%d -> %d\n", u, v);
}
int box[N], nxta[N];
int q[N], st, ed;
int dis[N];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout); 
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++){
		scanf("%d", a + i);
	}
	for(int i = n;i >= 1;i--){
		if(box[a[i]])nxta[i] = nxta[box[a[i]]];
		else nxta[i] = i;
		box[a[i]] = i;
//		printf("%d: %d\n", i, nxta[i]);
	}
	for(int i = 1;i <= n;i++){
		dis[i] = 1;
		if(nxta[i] != i)add_edge(i, nxta[i]);
		else if(i < n)add_edge(i, i + 1); 
	}
	st = 1;
	for(int i = 1;i <= n;i++){
		if(!pre[i])q[++ed] = i;
	}
	while(st <= ed){
		int u = q[st++];
		for(int d = head[u];d;d = nxt[d]){
			int v = to[d];
			dis[v] += dis[u], pre[v]--;
			if(!pre[v])q[++ed] = v;
		}
	}
//	for(int i = 1;i <= n;i++)printf("%d: %d\n", i, dis[i]); 
	for(int i = 1;i <= m;i++){
		printf("%d ", dis[nxta[box[i]]]);
	}
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1

AK了，希望不要挂分qwq，加油！ 
*/
