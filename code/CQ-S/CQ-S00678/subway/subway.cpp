//待我为你吹散阴云，阳光终会照耀大地
//也许是不知梦的缘故，流离之人追逐幻影
//致我的最后一次CSP，彻底告别我的竞赛生涯 
//我大抵是累了，做完T1睡了两个小时
//一个多月完全没碰竞赛，能打完就心满意足了吧
//到底怎样的结局，才配得上这一路的颠沛流离
//终究是镜花水月一场空，空悲切 
//不想再打了，拿不了牌进不了国集都没用
//我为了什么学信息的呢，当初是爱好吧
//后来变得越来越功利，早就失去了初心吧
//总觉得心缺了一部分，已经回不到过去了
//早知道吃午饭了，胃要痛死了 
//累了，不想再思考了，就这样结束吧
//如此草率，可又好像释怀了吧 
//后面的题打打我喜欢的数据结构吧
//这样的告别，似乎也很不错呢 
//也许未来还有这样的告别，但我想，那时候，我已经放下一切了吧
//最后，向我的挚友表达我最真挚的怀念，晚安 
#include <stdio.h>
#define ll long long
#define maxn 5000010
int n, m, head[maxn], tot, dfn[maxn], dcnt, rnk[maxn], siz[maxn], fa[maxn], dep[maxn], top[maxn];
struct node { int next, to, val; } edge[maxn];
void addedge(int from, int to, int val) { edge[++tot].next = head[from], edge[tot].to = to, edge[tot].val = val, head[from] = tot; }
void dfs1(int u, int p) {
	fa[u] = p, dep[u] = dep[p] + 1, siz[u] = 1;
	for (int i = head[u]; i; i = edge[i].next) {
		int v = edge[i].to;
		if (v == p) continue;
		dfs1(v, u), siz[u] += siz[v];
	}
}
void dfs2(int u, int tp) {
	dfn[u] = ++dcnt, rnk[dcnt] = u, top[u] = tp;
	if (u != tp) dfs2(u, u);
	for (int i = head[u]; i; i = edge[i].next) {
		int v = edge[i].to;
		if (v == fa[u]) continue;
		dfs2(v, v);
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1, a, b, c; i <= m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		addedge(a, b, c), addedge(b, a, c);
	}
	dfs1(1, 0), dfs2(1, 1);
	return 0;
}
