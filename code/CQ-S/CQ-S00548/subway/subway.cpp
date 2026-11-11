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
#define llt long long
#define rint register int
#define pint std::pair<int,int>
#define mp std::make_pair
#define fi first
#define se second
#define vint std::vector<int>
#define pb emplace_back
#define vpint std::vector<std::pair<int,int> >
const int N=505,M=5e5+5;
int c,n,m,D,q;
llt w[M],d[N][N],ans;
std::vector<std::pair<int,llt> >g[M];
signed main()
{
//	system("fc subway6.ans subway.out");
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(c);read(n);read(m);read(D);read(q);
	for(rint i=1;i<=m;++i) read(w[i]);
	int a,k,t,u,v;llt t1,t2;
	for(rint i=1;i<=n;++i)
	{
		read(k);
		for(rint j=1;j<=k;++j)
		{
			read(a);read(t);
			g[a].pb(mp(i,t));
		}
	}
	std::memset(d,0x3f,sizeof d);
	for(rint i=1;i<=n;++i)d[i][i]=0;
	for(rint a=1;a<=m;++a)for(rint i=0;i<g[a].size()-1;++i)for(rint j=i+1;j<g[a].size();++j)
	{
		u=g[a][i].fi,v=g[a][j].fi;
		t1=g[a][i].se,t2=g[a][j].se;
		d[u][v]=d[v][u]=std::min(d[u][v],t1+t2);
	}
//	for(int i=1;i<=m;++i)write(g[i].size(),10);
	for(rint k=1;k<=n;++k)for(rint i=1;i<=n;++i)if(i!=k)for(rint j=i+1;j<=n;++j)if(j!=k)
	{
		d[i][j]=d[j][i]=std::min(d[i][j],d[i][k]+d[k][j]);
	}
	for(rint _=1;_<=q;++_)
	{
		ans=0x3f3f3f3f3f3f3f3f;
		read(u);read(v);
//		write(g[u].size(),32);write(g[v].size(),10);
		for(rint i=0;i<g[u].size();++i)for(rint j=0;j<g[v].size();++j)
		{
//			putchar(10);
//			write(g[u][i].fi,32),write(g[v][j].fi,10);
			ans=std::min(ans,d[g[u][i].fi][g[v][j].fi]+g[u][i].se+g[v][j].se);
		}
		write(ans+w[u]+w[v],10);
	}
	return 0;
}
/*
正解没打出来。坠机。 
*/ 
