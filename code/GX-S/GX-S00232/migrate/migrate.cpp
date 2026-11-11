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
const int N=2000007;
ll c,T,n,d;
ll x[N],dis[5007][5007];
ull w[5007][5007];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read(c),read(T);
	while(T--)
	{
		read(n),read(d);
		for(int i=1;i<=n;++i)read(x[i]);
		ll ans=0;
		if(c<=6)
		{
			for(int i=1;i<=n;++i)
				for(int j=1;j<=n;++j)
					dis[i][j]=1LL<<60,w[i][j]=0;
			for(int i=1;i<n;++i)
				for(int j=i+1;j<=n;++j)
					if(x[j]-x[i]<=d)
						w[i][j]=w[j][i]=dis[i][j]=dis[j][i]=1;
					else
						break;
			for(int k=1;k<=n;++k)
				for(int i=1;i<=n;++i)
					for(int j=1;j<=n;++j)
						dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
			for(int k=1;k<=n;++k)
				for(int i=1;i<=n;++i)
					for(int j=1;j<=n;++j)
						if(dis[i][j]==dis[i][k]+dis[k][j])
							w[i][j]+=w[i][k]*w[k][j];
			for(int i=1;i<n;++i)
				for(int j=i+1;j<=n;++j)
					if(w[i][j]==2)
						++ans;
			wln(ans);
			continue;
		}
		puts("0");
	}
	return 0;
}
