#include<iostream>
#include<queue>
#include<vector>
#include<numeric>
#include<cstring>
#include<algorithm>
template<typename T>
inline void read(T& x)
{
	x=0;int f=1;
	char c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-') f=-f;
		c=getchar();
	}
	while('0'<=c&&c<='9')
	{
		x=x*10+(c-'0');
		c=getchar();
	}
	x*=f;
}
char asdf[1005];
template<typename T>
inline void write(T x,char dlc='\0')
{
	if(x<0) putchar('-'),x=-x;
	int t=0;
	while(x||(!t)) asdf[t++]=x%10+'0',x/=10;
	while(t--) putchar(asdf[t]);
	if(dlc!='\0') putchar(dlc);
}
#define int long long
#define pint std::pair<int,int>
#define mp std::make_pair
#define fi first
#define se second
#define vint std::vector<int>
#define pb emplace_back
#define vpint std::vector<std::pair<int,int> >
const int N=5e5+5;
#define rt (1+(n-1)|(1!=n-1))
int n,m,a[N],b[N],ans=1;
namespace seg
{
	int sum[N*3],tag[N*3];
	#define mid ((l+r)>>1)
	#define p (l+r|l!=r)
	#define ls (l+mid|l!=mid)
	#define rs (mid+1+r|(mid+1)!=r)
	#define lside l,mid
	#define rside mid+1,r
	inline void add(int l,int r,int w)
	{
		tag[p]+=w; 
		sum[p]+=w*(r-l+1);
	}
	inline void pushdown(int l,int r)
	{
		if(!tag[p]) return;
		add(lside,tag[p]);
		add(rside,tag[p]);
		tag[p]=0;
	}
	inline void pushup(int l,int r)
	{
		sum[p]=sum[ls]+sum[rs];
	}
	void build(int l,int r)
	{
		tag[p]=0;
		if(l==r)
		{
			sum[p]=b[l];
			return;
		}
		build(lside);build(rside);
		pushup(l,r); 
	}
	void check(int l,int r)
	{
		if(l==r)
		{
			write(p,32);putchar(32);write(l,32);write(r,32);write(sum[p],10);
			return;
		}
		write(p,32);putchar(32);write(l,32);write(r,32);write(sum[p],32);putchar(32);write(ls,32);write(rs,10);
		check(lside);check(rside); 
	}
	void update(int l,int r,int x,int y,int w)
	{
		if(x<=l&&r<=y)
		{
			add(l,r,w);
			return;	
		}
		pushdown(l,r);
		if(x<=mid) update(lside,x,y,w);
		if(y>mid) update(rside,x,y,w);
		pushup(l,r);
	}
	int search(int l,int r,int w)
	{
		if(l==r) return l;
		pushdown(l,r);
		if(w>sum[rs]) return search(lside,w-sum[rs]);
		else return search(rside,w);
	}
	#undef mid 
	#undef p
	#undef ls
	#undef rs
	#undef lside
	#undef rside
}
signed main()
{
//	system("fc crystal4.ans crystal.out");
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=n;++i) read(a[i]);
	if(n==1)
	{
		putchar('1');
		return 0;
	}
	std::sort(a+1,a+n+1);
	a[n+1]=a[n];
	for(int i=1;i<=n;++i) b[i]=a[i+1]-a[i];
	for(int i=n;i>=1;--i) b[i]+=b[i+1];
//	for(int i=1;i<=n;++i) write(b[i],32);putchar(10);
	seg::build(1,n);
	for(int i=n;i>1;--i)
	{
//		write(ans,10);
		seg::update(1,n,1,i,b[i+1]-b[i]);
//	seg::check(1,n);
		if(m>=seg::sum[rt])
		{
			ans=std::max(ans,i);
			break;
		}
		int tp=seg::search(1,n,m)+1;
//		write(i,32);write(tp,10);
		ans=std::max(ans,i-tp+1);
	}
	write(ans);
	return 0;
}
/*
感觉自己写复杂了 

hhddxyhhddd,
hhdddzhhddz.
hhddzswhwhg?
hhddzrmrcy.
yggzpyzybbh,
qcrmbbmzjhh.
mcmmjyswqbz,
后面忘了 
*/
