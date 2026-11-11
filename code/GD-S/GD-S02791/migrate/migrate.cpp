#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std; bool MEM;
using ll=long long; using ld=long double;
using pii=pair<int,int>; using pll=pair<ll,ll>;
void rd(int &x) {
	char c; int f=1;
	while (c=getchar(),!('0'<=c&&c<='9'||c=='-'));
	if (c=='-') f=-1,x=0; else x=c-'0';
	while (c=getchar(),'0'<=c&&c<='9') x=x*10+c-'0'; x*=f;
}
void rd(ll &x) {
	char c; int f=1;
	while (c=getchar(),!('0'<=c&&c<='9'||c=='-'));
	if (c=='-') f=-1,x=0; else x=c-'0';
	while (c=getchar(),'0'<=c&&c<='9') x=x*10+c-'0'; x*=f;
}
const int I=1e9,N=2e6+7,K=21;
const ll J=1e18;
int type,n,cr[N],cl[N],sr[N],sl[N]; ll d,a[N],ans;
int dr[N],dl[N],er[N],el[N];
mt19937 dnr(chrono::system_clock::now().time_since_epoch().count());
int rnd(int l,int r) { return dnr()%(r-l+1)+l; }
bool is(int x,int y) {
	if (x>y) swap(x,y);
	while (1) {
		if (x==y) return 1;
		if (cr[x]==x||cr[cl[x]]!=x) return 0;
		x=cr[x];
	}
}
void mian() {
	rd(n),rd(d);
//	n=5,d=rnd(1,10);
	ans=0;
	for (int i=1;i<=n;i++)
		rd(a[i]);
//		a[i]=rnd(1,10);
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) dr[i]=dl[i]=0,er[i]=n+1,el[i]=0;
//	printf("%d %d\n",n,d);
//	for (int i=1;i<=n;i++) printf(" %d",a[i]); printf("\n");
	for (int i=n,j=n;i>=1;i--) {
		while (a[j]-a[i]>d) j--;
		cr[i]=j,dr[j]++,er[j]=i;
	}
	for (int i=1,j=1;i<=n;i++) {
		while (a[i]-a[j]>d) j++;
		cl[i]=j,dl[j]++,el[j]=i;
	}
	for (int i=n;i;i--) {
		if (cr[i]==i||cl[cr[i]]!=i) sr[i]=0;
		else {
			int l=i+1,r=cr[i],mid,res=cr[i];
			while (l<=r) {
				mid=l+r>>1;
				if (cl[mid]==i) res=mid,r=mid-1;
				else l=mid+1;
			}
			sr[i]=sr[cr[i]]+cr[i]-res+1;
		}
	}
	for (int i=1;i<=n;i++) {
		if (cl[i]==i||cr[cl[i]]!=i) sl[i]=0;
		else {
			int l=cl[i],r=i-1,mid,res=cl[i];
			while (l<=r) {
				mid=l+r>>1;
				if (cr[mid]==i) res=mid,l=mid+1;
				else r=mid-1;
			}
			sl[i]=sl[cl[i]]+res-cl[i]+1;
		}
	}
//	for (int i=1;i<=n;i++) printf("%d ",cl[i]); printf("\n");
//	for (int i=1;i<=n;i++) printf("%d ",cr[i]); printf("\n");
//	for (int i=1;i<=n;i++) printf(" %d",dl[i]); printf("\n");
//	for (int i=1;i<=n;i++) printf(" %d",dr[i]); printf("\n");
//	for (int i=1;i<=n;i++) printf("%d ",el[i]); printf("\n");
//	for (int i=1;i<=n;i++) printf("%d ",er[i]); printf("\n");
//	for (int i=1;i<=n;i++) printf(" %d",sl[i]); printf("\n");
//	for (int i=1;i<=n;i++) printf(" %d",sr[i]); printf("\n");
//	vector<int> ssl(n+1),ssr(n+1);
//	for (int i=1;i<=n;i++) for (int j=i+1;j<=n;j++) if (is(i,j)) ssr[i]++;
//	for (int i=1;i<=n;i++) for (int j=i-1;j;j--) if (is(j,i)) ssl[i]++;
//	for (int i=1;i<=n;i++) printf(" %d",ssl[i]); printf("\n");
//	for (int i=1;i<=n;i++) printf(" %d",ssr[i]); printf("\n");
//	for (int i=1;i<=n;i++) if (sl[i]!=ssl[i]||sr[i]!=ssr[i]) assert(0);
	for (int i=1;i<n;i++) if (er[i+1]<i&&el[i]>i+1) {
		ans+=1ll*dr[i+1]*dl[i];
		if (cl[i]==er[i+1]) ans+=1ll*sl[er[i+1]]*dl[i];
		if (cr[i+1]==el[i]) ans+=1ll*dr[i+1]*sr[el[i]];
		if (cl[i]==er[i+1]&&cr[i+1]==el[i]) ans+=1ll*sl[er[i+1]]*sr[el[i]];
	}
	cout<<ans<<"\n";
}
bool ORY; int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t; for (rd(type),rd(t);t--;)
	mian();
	cerr<<"\n"<<abs(&MEM-&ORY)/1048576<<"MB";
	return 0;
}
/*
一个数轴上很多个点，对于距离不超过 d 的点，中间会有连边
求有多少对点满足它们中间的最短路径恰好有两条
sum n<=1e6

首先对于两个点 x y，走出最短路径的方法是显然的
也就是一路用最大的距离跳过去

然后我们考虑从 x 到 y 和 y 到 x 分别这么跳
尝试证明：如果这两条路径是一样的，那它是 x y 中间唯一的最短路径
看起来是显然的。因为只要有另一条路径就违反了我们跳的时候的最优性

如果两条路径头尾一样，中间有两段不一样，又夹了一段一样的，那显然超过了两条路径

所以现在我们只研究一种情况：从 x 到 y 和从 y 到 x，中间有一段连续的点是错开的
首先它们一定形如 xbababay
我们考虑一下这些 ab 中间夹的点有没有什么说法
看起来没什么说法。挺难分析的。
夹在中间的点有可能可以塞到路径里，也有可能不行

感受到一个事情：双径岛屿对好像存在某种嵌套定义

考虑从一个 x 开始往右跳。跳到 y
(x,y) 似乎一定是在前一段时间保持单径岛屿对，然后变成双径岛屿对，再变成更多
这个单径岛屿对的前缀不知道能不能求？


#n<=300
可以对每对点暴力做
如果存在一个点，它可能存在于最短路径中，但是又不在那两条路径里，就寄了
#1~6 ok 24
#n<=5000
如果有上面这样的点，那它就一定可以单独改进两条路径中的一条。调整可证？
n^2 怎么做？
感觉很关键，应该是差了一步刻画之类的，不然这隔着数量级的优化也太远了。
 
#A 讨论一下
ok 8 
#B 有个超级源 
ok 8
#C 步数不超过 10

诶，不对
极小的双径岛屿对好像一定形如 abcd。其中 bc 中间没有点，然后有 a->c,d->b。
如果是非极小双径岛屿对，假设两侧都扩展出去了一小段。那一定还有 b->a,c->d。（如果只有一侧扩展出去，那就只有那边有限制）
那么这样的 (a,b,c,d) 只有很少对。
所以我们只需要考虑一个这样的问题：固定一个左端点 d，有多少 (d,i) 满足它是单径岛屿对？
我们从 d 往右跳一下。
对于那些最优方案能跳到的 i，如果从某个 i 开始它不再是单径岛屿对，那后面就不是了
然后对于 d->i>j，如果 d<=>i，j->i，那这个 i 也可以
考虑第一个不再是单径岛屿对的 i。这个时候就是，i 往回跳跳不到跳过来的点上。那就倒闭了。
这个数量不多。
总之我们可以倍增处理这个东西。那似乎就可以做了。 
这也太难了！！！！！ 
*/
