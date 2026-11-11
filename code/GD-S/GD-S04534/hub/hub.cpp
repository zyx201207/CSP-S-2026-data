#include <bits/stdc++.h>
#define int long long
#define Blackdream1853 return
#define code 0
using namespace std;
const int N=1e6+1;
int _, T, n, k, ex[N], ey[N], ans;
vector <int> g[N];
int deg[N], h[N], fh[N], sh[N], rt;
bool vis[N];
void topo() {
	queue <int> q;
	for (int i=1;i<=n;i++)
		if (deg[i]==1) --deg[i], q.push(i);
	for (int i=1;i<=n-k;i++) {
		int x=q.front(); q.pop();
		--deg[x], vis[x]=1;
		for (int y:g[x])
			if (--deg[y]==1) q.push(y);
	}
}
struct node {
	int type, ht;
	bool operator < (const node &w) const {
		return (type!=w.type?type<w.type:ht>w.ht);
	}
} q[N];
void dfs0(int fa,int x) {
	h[x]=vis[x]*(h[fa]+1);
	for (int y:g[x]) if (y!=fa) dfs0(x,y);
}
void dfs1(int fa,int x) {
	fh[x]=0, sh[x]=-n-1;
	for (int y:g[x]) {
		if (y==fa) continue;
		dfs1(x,y);
		if (fh[y]+1>fh[x]) sh[x]=fh[x], fh[x]=fh[y]+1;
		else if (fh[y]+1>sh[x]) sh[x]=fh[y]+1;
	}
}
void dfs2(int fa,int x) {
	if (rt==-1||fh[x]<fh[rt]) rt=x;
	for (int y:g[x]) {
		if (y==fa) continue;
		if (fh[x]==fh[y]+1) fh[y]=max(fh[y],sh[x]+1);
		else fh[y]=max(fh[y],fh[x]+1);
		dfs2(x,y);
	}
}
void dfs3(int fa,int x,int id,int err) {
	q[x]={id,0};
	for (int y:g[x]) {
		if (y==fa||y==err) continue;
		dfs3(x,y,id,err);
		q[x].ht=max(q[x].ht,q[y].ht+1);
	}
}
void solve() {
	cin >> n >> k;
	for (int i=1;i<=n;i++) {
		deg[i]=vis[i]=0;
		g[i].clear();
		g[i].shrink_to_fit();
	}
	for (int i=1;i<n;i++) {
		cin >> ex[i] >> ey[i];
		g[ex[i]].push_back(ey[i]);
		g[ey[i]].push_back(ex[i]);
		deg[ex[i]]++, deg[ey[i]]++;
	}
	topo();
	for (int i=1;i<=n;i++)
		if (vis[i]) {dfs0(0,i); break;}
	ans=*max_element(h+1,h+n+1);
	
	for (int i=1;i<n;i++) {
		dfs1(ey[i],ex[i]);
		rt=-1, dfs2(ey[i],ex[i]);
		dfs3(0,rt,1,ey[i]);
		dfs1(ex[i],ey[i]);
		rt=-1, dfs2(ex[i],ey[i]);
		dfs3(0,rt,2,ex[i]);
		sort(q+1,q+n+1);
		int pos=1;
		while (pos<=n&&q[pos].type==1) pos++;
		for (int j=1;j<=min(pos-1,k);j++) {
			if (k-j>n-pos+1) continue;
			int ans1=0, ans2=0;
			if (j<pos-1) ans1=q[j+1].ht+1;
			if (pos+k-j-1<n) ans2=q[pos+k-j].ht+1;
			ans=min(ans,max(ans1,ans2));
		}
	}
	cout << ans << '\n';
}
signed main(void) {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> _ >> T; while (T--) solve();
	Blackdream1853 code;
}
/*
给出一棵树,需要在上面选择k个关键点
要求这些关键点形成不超过两个连通块
定义一个城市的通勤距离为其到任意关键点的最小距离
定义整个方案的通勤半径为所有点通勤距离的最大值
求通勤半径最小值
多测, sum(n)<=2e6,2<=k<=n

考虑二分答案
每次二分一个mid,求出哪些点必须被选
显然,必须被选的点会是比较上的
但是这是两个连通块,可能有多个点必须被选
其中一些点可能导致另一些点不需要必须被选
所以这不行
注意到形成不超过两个连通块
那很显然,如果一个连通块,要么直接剥叶贪心
要么考虑求出中心并按h排序
如果两个连通块,那就是选择一条边断掉
然后在两个连通块内求出中心,并按h排序
然后进行相应的计算答案处理
此时有个问题,如果某条边一侧有一个中心
另一侧是一条极长的链
此时会选择链的中点作为中心
那么链的连接该边的那一半显然有些点是可以用边上那个中心的
此时答案会错吗?貌似不会,因为还有另一边的贡献
这样是n^2的,有40分
考虑边移动会带来什么
显然,中心是在直径上的,最多只会移动1格
问题转化为,移动之后,中心的变化,以及带来的h数组的变化
显然这是两次换根,还有一个单点加
可以通过最长链和次长链的更新快速求出h数组的变化
在h数组上,假设选了前x大的
那么此时的结果应该是选了的里面最小的那个
也就是说结果是第n-x+1小的,在第n-x+1个位置
倒过来就是在第x个位置
此时,造成的更新最多有三个,x的,y的,新加入or新删的点的
那么中心怎么移动呢,然而并不会
*/
