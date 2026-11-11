#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 505,M = 5e5 + 5,D = 22;
const ll INF = 1e18;

bool b1;

namespace FastIO
{
	const int S = 1 << 21;
	char ibuf[S],*p1 = ibuf,*p2 = ibuf,obuf[S],*op = obuf;
	inline char gc()
	{
		if(p1 == p2)
		{
			p2 = (p1 = ibuf) + fread(ibuf,1,S,stdin);
			if(p1 == p2) return EOF;
		}
		return *p1++;
	}
	inline int read() // without f !!!
	{
		int x = 0; char c = gc();
		while(c < '0' || c > '9') c = gc();
		while(c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ 48),c = gc();
		return x;
	}
//	inline int read() // without f !!!
//	{
//		int x = 0; char c = getchar();
//		while(c < '0' || c > '9') c = getchar();
//		while(c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ 48),c = getchar();
//		return x;
//	}
}
using FastIO::read;

int kase,n,m,kase_d,q;
ll W[M]; vector<pair<int,ll> > nlis[M]; 
ll f[N][N];

bool b2;

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	freopen("hack.in","r",stdin);
//	freopen("hack.out","w",stdout);
	kase = read(),n = read(),m = read(),kase_d = read(),q = read();
	for(int i = 1; i <= m; i++) W[i] = read();
	for(int i = 1; i <= n; i++)
	{
		int cnt = read(),a,t;
		while(cnt--)
		{
			a = read(),t = read();
			nlis[a].emplace_back(i,t);
		}
	}
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			f[i][j] = INF;
	for(int i = 1; i <= n; i++) f[i][i] = 0;
	for(int x = 1; x <= m; x++)
		for(int i = 0; i < nlis[x].size(); i++)	
			for(int j = i + 1; j < nlis[x].size(); j++)
			{
				ll vx = nlis[x][i].second,idx = nlis[x][i].first;
				ll vy = nlis[x][j].second,idy = nlis[x][j].first;
				f[idx][idy] = min(f[idx][idy],vx + vy);
				f[idy][idx] = min(f[idy][idx],vx + vy);
			}
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
	
	int x,y;
	while(q--)
	{
		x = read(),y = read(); ll ans = 0;
		ans += W[x] + W[y]; ll minn = INF;
		for(int i = 0; i < nlis[x].size(); i++)
			for(int j = 0; j < nlis[y].size(); j++)
			{
				ll vx = nlis[x][i].second,idx = nlis[x][i].first;
				ll vy = nlis[y][j].second,idy = nlis[y][j].first;
				minn = min(minn,vx + vy + f[idx][idy]);
			}
		ans += minn;
		printf("%lld\n",ans);
	}
	
//	cerr << (&b2 - &b1) / 1024.0 / 1024.0 << "mb\n";
	return 0;
}

