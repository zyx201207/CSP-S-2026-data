#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define qwq Ff472130
#define ll long long
#define f(i,l,r) for (int i=l;i<=r;i++)
#define F(i,r,l) for (int i=r;i>=l;i--)
constexpr int N=500+10;
constexpr int M=5e5+10;
constexpr ll inf=1e18+10;

inline void read(int &x) {
	x=0;
	char ch=getchar();
	while (ch<48) ch=getchar();
	while (ch>=48) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
}

int C,n,m,d,q;
int st[M],siz[M];

struct Node{int v,w;};
vector<Node> vec[M];

ll dis[N][N];
inline void init() {
	f(i,1,n) f(j,1,n) dis[i][j]=(i!=j)?inf:0;
	f(c,1,m) {
		int L=siz[c]-1;
		f(i,0,L) f(j,0,L) {
			int u=vec[c][i].v,v=vec[c][j].v,w=vec[c][i].w+vec[c][j].w;
			dis[u][v]=min(dis[u][v],(ll)w);
		}
	}
	f(k,1,n) f(i,1,n) {
		if (i==k||dis[i][k]==inf) continue;
		f(j,1,n) if (i!=j&&k!=j) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	}
}

inline ll query(int x,int y) {
	ll ret=inf;
	for (Node i:vec[x]) for (Node j:vec[y])
		ret=min(ret,i.w+j.w+dis[i.v][j.v]);
	return ret+st[x]+st[y];
}

int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	read(C);read(n);read(m);read(d);read(q);
	f(i,1,m) read(st[i]);
	f(i,1,n) {
		int T;read(T);
		while (T--) {
			int v,w;read(v);read(w);
			vec[v].push_back({i,w});siz[v]++;
		}
	}
	init();
	while (q--) {
		int x,y;read(x);read(y);
		printf("%lld\n",query(x,y));
	}
	return 0;
}

/*
too easy
15:10 AC
Graph T2 is wrong
*/
