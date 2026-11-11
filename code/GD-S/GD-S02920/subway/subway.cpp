// 3:00
// 3:37

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define siz(x) ((int)(x).size())
#define L(i,l,r) for(int i=(l);i<=(r);i++)
#define R(i,r,l) for(int i=(r);i>=(l);i--)
#define ve(x) vector<x>
#define x first
#define y second
#define me(x,v) memset(x,v,sizeof(x))
#define wr(...) printf(__VA_ARGS__)

#define ast(x) assert(x)

using sint =signed;
using ll =long long;

char gc() {
	return getchar();
}
void pc(char c) {
	putchar(c);
}
int rd() {
	int sgn=0,ret=0,c=0;
	while(c<'0'||c>'9') {
		sgn|=(c=='-');
		c=gc();
	}
	while(c>='0'&&c<='9') {
		ret=ret*10+c-'0';
		c=gc();
	}
	return sgn?-ret:ret;
}

void chkmin(int& x,int y) {
	if(x>y) {
		x=y;
	}
}

constexpr int N=507,M=5e5+7,QN=1e5+7,inf=0x3f3f3f3f3f3f3f3f;

struct T {
	int v,d;
};
struct Ln {
	ve(T) v;
} lin[N];
struct A {
	ve(T) v;
	int w;
} a[M];
int dis[N][N];
int n,m,qn,mxn;

sint main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	me(dis,0x3f);
	ast(dis[0][0]==inf);

	rd();
	n=rd(),m=rd(),mxn=rd(),qn=rd();
	L(i,1,m) {
		a[i].w=rd();
	}
	L(i,1,n) {
		int k=rd();
		lin[i].v.reserve(k);
		L(j,1,k) {
			int v=rd(),d=rd();
			lin[i].v.push_back({v,d});
			a[v].v.push_back({i,d});
		}
	}
	L(u,1,m) {
		ast(siz(a[u].v)<=mxn);
	}
	L(u,1,n) {
		for(T tmp:lin[u].v) {
			int mid=tmp.v,d1=tmp.d;
			for(T t2:a[mid].v) {
				int v=t2.v,d2=t2.d;
				int d=d1+d2;
				chkmin(dis[u][v],d);
			}
		}
	}
	L(i,1,n){
		dis[i][i]=0;
	}
	L(k,1,n) {
		L(i,1,n) {
			L(j,1,n) {
				chkmin(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	L(i,1,qn) {
		int x=rd(),y=rd();
		int ans=inf;
		for(T t1:a[x].v) {
			int u=t1.v,du=t1.d;
			for(T t2:a[y].v) {
				int v=t2.v,dv=t2.d;
				chkmin(ans,du+dis[u][v]+dv);
			}
		}
		ans+=a[x].w+a[y].w;
		wr("%lld\n",ans);
	}
	return 0;
}
