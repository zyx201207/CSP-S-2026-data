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
void rd(ll &x) {
	char c; while (c=getchar(),!('0'<=c&&c<='9')); x=c-'0';
	while (c=getchar(),'0'<=c&&c<='9') x=x*10+c-'0';
}
const int I=1e9;
const ll J=1e18,N=507,M=5e5+7;
int type,n,m,d,q,k[N],dd[M];
ll dis[N][N],w[M];
vector<int> a[N]; vector<ll> t[N];
vector<pair<int,ll> > to[M];
void chn(ll &x,ll y) { if (y<x) x=y; }
void mian() {
	rd(type),rd(n),rd(m),rd(d),rd(q);
	for (int i=1;i<=m;i++) rd(w[i]);
	for (int i=1;i<=n;i++) {
		rd(k[i]),a[i].resize(k[i]),t[i].resize(k[i]); 
		for (int j=0;j<k[i];j++) rd(a[i][j]),rd(t[i][j]),to[a[i][j]].pb({i,t[i][j]});
	}
	memset(dis,20,sizeof(dis));
	for (int i=1;i<=n;i++) dis[i][i]=0;
	for (int i=1;i<=m;i++) {
		dd[i]=to[i].size();
		for (int x=0;x<dd[i];x++) for (int y=x+1;y<dd[i];y++) {
			int xx=to[i][x].fi,yy=to[i][y].fi; ll w=to[i][x].se+to[i][y].se;
			chn(dis[xx][yy],w),chn(dis[yy][xx],w);
		}
	}
	for (int k=1;k<=n;k++) for (int i=1;i<=n;i++) for (int j=1;j<=n;j++)
		chn(dis[i][j],dis[i][k]+dis[k][j]);
	for (int i,j;q--;) {
		rd(i),rd(j);
		ll ans=J;
		for (int x=0;x<dd[i];x++) for (int y=0;y<dd[j];y++) {
			int xx=to[i][x].fi,yy=to[j][y].fi; ll w=to[i][x].se+to[j][y].se;
			chn(ans,w+dis[xx][yy]);
		}
		cout<<ans+w[i]+w[j]<<"\n";
	}
}
bool ORY; int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	int t; for (scanf("%d",&t);t--;)
	mian();
	cerr<<"\n"<<abs(&MEM-&ORY)/1048576<<"MB "<<clock()<<"ms";
	return 0;
}
/*
总之是给了一个地铁网
每个站最多 20 条线路 
线路数 <=500，站数 <=5e5 
查很多次最短路。查询超级多。
实际上可以简化为一个二分图。有一部的点数不超过 500。
在这 500 个点中间跑个全源最短路是不是就可以了
查询的时候枚举两条出边。O(n^3+qd^2) 
怎么看起来还怪卡常的 
*/
