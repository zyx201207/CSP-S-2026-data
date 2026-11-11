/*
记录思考
1.如果第i个数没能参加第j场对局，那么第i个数必然不能参加第j-1场对局
2.任意对局中存在两个相同的数a[l]和a[r](l<=r)，则l~r之间的数无法参加这场对局
3.从右往左更新，如果出现a[l]和a[r]这两个相等的数，
	则在其前面的对局a[l]~a[r]之间的数无法参加
想法1:容斥原理，从左往右更新，更新到a[l]时，l~lst[a[l]之间的数不能参加第1~l场对局
初始化所有数能参加所有对局...
思考:能否统计不能参加1~l对局的交集。答案：不行
想法2:从后往前更新，统计停摆数字。但是最多有3e5个l~r停摆，所以不行
想法3:结合性质发现该问题没有后效性（由第一点可得），f[l]统计l~n之间能参加对局的数字个数
想法3补充：由于还是存在交集，容斥问题，无法实行
想法4:我发现从后往前统计可以使用特殊方法标记无法参加该场对局的数字数量
但是统计没有标记过的数字非常困难
想法4补充：使用并查集建立l指向lst[a[l]]的边，然后统计的时候跳过
时间复杂度计算：3e5个数据均摊到5e5的数组中，至少有2e5个数据与之前重复
最坏情况：重复数据互相相邻或间隔极少，那么统计一次时间复杂度为3e5
想法5:能否将可以参加对局的连续区间中的数据一键统计
想法6:可以使用并查集压缩路径解决相邻问题，但是如果相隔极少还是难以解决
问题:我突然发现如果重复数据在前半数据扎堆，那么后半数据统计会是灾难

发现：读题错误，所有相邻的l~lst[a[l]]之间的数据不一定就不能参加这次比赛
因为如果l这一轮无法参加对局，那么也就无法对后面数据产生影响 

整理一下
1.第l个数据无法影响到第l+1场比赛
2.思考的第2点和第3点错误
思维转化：能否记录第j个数字出现的下标，答案：不行 
核心思维；l~lst[a[l]]的所有数字影响局数全部减去l的影响局数
巧妙：可以同时消去重复统计，两个1只算一个
使用线段数维护AC 
*/
#include <bits/stdc++.h>
#define lc p<<1
#define rc p<<1|1
using namespace std;
const int N=5e5+10;
int n,m;
int a[N],s[N];
int lst[N];

struct node
{
	int l,r,s,d;
} tr[N<<2];

int len(int p)
{
	return tr[p].r-tr[p].l+1;
}

void pushup(int p)
{
	tr[p].s=tr[lc].s+tr[rc].s;
}

void add(int p, int x)
{
	tr[p].s+=x*len(p);
	tr[p].d+=x;
}

void pushdown(int p)
{
	if(tr[p].d)
	{
		add(lc, tr[p].d);
		add(rc, tr[p].d);
		tr[p].d=0;
	}
}

void build(int p, int l, int r)
{
	tr[p]={l,r,l};
	if(l==r) return;
	int mid=l+r>>1;
	build(lc, l, mid);
	build(rc, mid+1, r);
	pushup(p);
}

void update(int p, int l, int r, int x)
{
	if(l<=tr[p].l&&tr[p].r<=r)
	{
		add(p,x);
		return;
	}
	int mid=tr[p].l+tr[p].r>>1;
	pushdown(p); 
	if(l<=mid) update(lc, l, r, x);
	if(mid<r)  update(rc, l, r, x);
	pushup(p);
}

int query(int p, int loc)
{
	if(tr[p].l==tr[p].r) return tr[p].s;
	int mid=tr[p].l+tr[p].r>>1;
	pushdown(p); 
	if(loc<=mid) return query(lc, loc);
	else return query(rc, loc);
}

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d", &n, &m);
	build(1,1,n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d", &a[i]);
		lst[a[i]]=i;
	}
	for(int i=1; i<=n; i++)
	{
		int x=query(1,i);
		s[a[i]]+=query(1,i);
		if(i<lst[a[i]]) update(1,i+1,lst[a[i]],-x);
	}
	for(int i=1; i<=m; i++)
	printf("%d ", s[i]);
	return 0;
}
