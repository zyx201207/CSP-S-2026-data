#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<cstring>
#include<stack>
#include<queue>
#include<map>
#include<iomanip>
#include<vector>
#include<set>
#include<deque>
#include<bitset>
using namespace std;
#define ll long long
#define ull unsigned ll
#define db double
#define ld long db
#define ui unsigned
#define eb push_back
#define pb pop_back
#define mk make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ls i<<1
#define rs i<<1|1
#define fir first
#define sec second
#define wls(x) output(x),putchar(32)
#define wln(x) output(x),putchar(10)

template<class T>void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;!isdigit(c);c=getchar())f|=c==45;
	for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
	x=f?-x:x;
}
template<class T>void output(T x)
{
	if(!x)return putchar(48),void();
	if(x<0)putchar(45),x=-x;
	int sta[50]={},tot=0;
	while(x)sta[++tot]=x%10,x/=10;
	for(int i=tot;i;--i)putchar(sta[i]|48);
}
const int M=500007,N=507;
int n,m,c,q,d;
int w[M],head[N+M],tot;
ll dis[M+N];
bool v[M+N];
struct sch{int to,next,val;}a[(M+N)*5];
void add(int u,int v,int w){a[++tot]=(sch){v,head[u],w};head[u]=tot;}
void work(int s,int t)
{
	for(int i=1;i<=n+m;++i)dis[i]=1e18,v[i]=0;
	dis[s]=0;
	priority_queue<pll,vector<pll>,greater<pll> >q;
	q.push(mk(0,s));
	while(q.size())
	{
		ll k=q.top().sec;q.pop();
		if(v[k])continue;
		for(int to,i=head[k];i;i=a[i].next)
			if(dis[to=a[i].to]>dis[k]+a[i].val)
				dis[to]=dis[k]+a[i].val,q.push(mk(dis[to],to));
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(c),read(n),read(m),read(d),read(q);
	for(int i=1;i<=m;++i)read(w[i]);
	if(c<=15)
	{
		for(int i=1,k;i<=n;++i)
		{
			read(k);
			for(int x,t,j=1;j<=k;++j)
			{
				read(x),read(t);
				add(i+m,x,t);
				add(x,i+m,t);
			}
		}
		while(q--)
		{
			int x,y;
			read(x),read(y);
			work(x,y);
			wln(dis[y]+w[x]+w[y]);
		}
	}
	return 0;
}
