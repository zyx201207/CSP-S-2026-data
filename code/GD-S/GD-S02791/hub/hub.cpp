#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std; bool MEM;
using ll=long long; using ld=long double;
using pii=pair<int,int>; using pll=pair<ll,ll>;
void rd(int &x) {
	char c; while (c=getchar(),!('0'<=c&&c<='9')); x=c-'0';
	while (c=getchar(),'0'<=c&&c<='9') x=x*10+c-'0';
}
mt19937 dnr(chrono::system_clock::now().time_since_epoch().count());
int rnd(int l,int r) { return dnr()%(r-l+1)+l; }
const int I=1e9,N=1e6+7,K=20;
const ll J=1e18;
int type,n,k,ml[N],cl[N],mid,ret;
vector<int> e[N];
pii get(pii x) { if (x.fi>x.se) swap(x.fi,x.se); return x; }
void dfs1(int p,int f,pii x) {
	ml[p]=cl[p]=0;
	for (int i:e[p]) if (i!=f&&get({p,i})!=x) {
		dfs1(i,p,x);
		int w=ml[i]+1;
		if (w>ml[p]) cl[p]=ml[p],ml[p]=w;
		else if (w>cl[p]) cl[p]=w;
	}
}
void dfs2(int p,int f,pii x) {
//	printf("%d %d %d %d\n",p,f,ml[p],ml[f]);
	if (f) ret+=min(ml[p],ml[f])>=mid;
	int mml=ml[p],ccl=cl[p]; ml[p]=cl[p]=0;
	for (int i:e[p]) if (get({p,i})!=x) {
		int w=ml[i]+1;
		if (w>ml[p]) cl[p]=ml[p],ml[p]=w;
		else if (w>cl[p]) cl[p]=w;
	}
	for (int i:e[p]) if (i!=f&&get({p,i})!=x) {
		if (ml[i]+1==ml[p]) swap(ml[p],cl[p]),dfs2(i,p,x),swap(ml[p],cl[p]);
		else dfs2(i,p,x);
	}
	ml[p]=mml,cl[p]=ccl;
}
int cal(int p,pii x) {
//	printf("cal %d %d {%d,%d}\n",mid,p,x.fi,x.se);
	ret=1,dfs1(p,0,x),dfs2(p,0,x);
//	printf("%d\n",ret);
	return ret;
}
bool dfs(int p,int f) {
	if (f) {
		int w=cal(f,get({p,f}))+cal(p,get({p,f}));
		if (w<=k) return 1;
	}
	for (int i:e[p]) if (i!=f&&dfs(i,p)) return 1;
	return 0;
}
bool chk(int mid) {
	if (cal(1,{0,0})<=k) return 1;
	return dfs(1,0);
}
void mian() {
	rd(n),rd(k);
//	n=4000,k=200;
	for (int i=1;i<=n;i++) e[i].clear();
	for (int i=1,x,y;i<n;i++)
		rd(x),rd(y),
//		x=rnd(1,i),y=i+1,
		e[x].pb(y),e[y].pb(x);
	int l=0,r=n-k,res=n;
	while (l<=r) {
		mid=l+r>>1;
		if (chk(mid)) res=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<res<<"\n";
}
bool ORY; int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int t; for (rd(type),rd(t);t--;)
	mian();
	cerr<<"\n"<<abs(&MEM-&ORY)/1048576<<"MB";
	return 0;
}
/*
在树上选 k 个点，使得它们形成不超过两个连通块
然后要求一个最小值 ans，使得所有点都能在 ans 步内走到关键点上
sum n<=2e6
这么难

一个连通块的情况，先拎直径中点作根
然后每次把最深子树的根砍掉。这样就能挖掉 k 个点。
当然这看起来不是很有前途。

对于两个连通块的情况。假设我们知道这两个连通块的最近点对
那么这棵树就可以沿着它们的中点劈开变成两个问题
我们考虑先劈开这条边。然后在两边随便选连通块。要求最后两边的 max 最小
那直接二分一下答案。
所以现在直接变成了一个问题：对于一棵内子树/外子树，求出要让它的通勤半径不超过 ans，最少要选多少个点。
需要在均摊 O(1) 内解决。

先假设是完整的树。假设能得到直径中点的位置。
我们还有一种理解方法：求子树深度 >=ans 的点数。
这个东西依赖根的位置不是很好搞。可以再换换：求两侧深度的min >=ans 的边数 +1

我们期望对于不同的内外子树都能维护这个东西

考虑全局直径
如果我们砍掉的边不在全局直径上
那么对于直径那一侧的边，策略是显然的，而且应该还挺容易处理的
那就只剩下一个子树内部的情况

感觉很诡异啊

考虑一条边的两侧。
如果两边深度有一边 <ans，那砍哪条边都行。 
然后考虑两边都 >=ans 的时候。
我们期望砍掉一条，能使这一侧子树深度直接 <ans 的边。
考虑最深点。这条边必须得砍在最深点到这条边的路径上，不然就没有用。
在此基础上，所有深度 >=ans 的点的深度 =ans 的祖先都得在砍掉的边下面
那也就是说能砍的边在一条链上。
算上另一侧，就是两条链。只要在两条链上随便砍一条边，这条边就不会计入代价
那么问题就只有对每个点求出这两条链了。后面的可以树上差分配合 O(1) lca 实现。 

对于子树内情况，似乎已经可以做到双 log 了？
子树外其实可能也行。但是这也太难写了！！！
 
暴力 #1~10 ok 50
#11~12 写个快速求直径 ok 10 

#A：梳子
专门给这个点是不是有什么说法。 
*/
