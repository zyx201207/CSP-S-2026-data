#include <bits/stdc++.h>
using namespace std;

char buf[1<<21], *p1, *p2;
#define getchar() (p1==p2 && (p2=(p1=buf)+fread(buf, 1, 1<<21, stdin), p1==p2)?EOF:*p1++)

template <typename T>
inline void Read(T &in){
	in=0;
	bool tag=0;
	char ch=0;
	while (ch=getchar(), !isdigit(ch) && ch!=EOF) if (ch=='-') tag=1;
	if (ch==EOF) return;
	while (isdigit(ch)) in=(in<<1)+(in<<3)+ch-48, ch=getchar();
	if (tag) in=-in;
	return;
}

template <typename T, typename ...Args>
inline void Read(T &in, Args &...rest){
	return Read(in), Read(rest...);
}

using ll=long long;

#define MAXN 515
#define MAXM 500015
constexpr ll INF=0x3f3f3f3f3f3f3f3fll;
#define pr pair
#define fst first
#define scd second
#define mkpr make_pair
#define memcvr(a, b, c) memset ((a), (b), (c)*sizeof(*(a)))

namespace akakakak{

	int c, n, m, d, q;
	ll inw[MAXM];
	ll f[MAXN][MAXN];
	vector <pr<int, ll>> g[MAXM];

	inline int main(){
		Read (c, n, m, d, q);
		for (int i=1;i<=m;++i) Read (inw[i]);
		for (int i=1;i<=n;++i){
			memcvr (f[i], 0x3f, n+5);
			f[i][i]=0;
		}
		for (int i=1, k=0;i<=n;++i){
			Read (k);
			while (k --> 0){
				int a=0; ll w=0;
				Read (a, w);
				for (auto [v, e]:g[a]){
					f[v][i]=f[i][v]=min(f[i][v], e+w);
				}
				g[a].emplace_back (i, w);
			}
		}
		for (int k=1;k<=n;++k) for (int i=1;i<=n;++i) for (int j=1;j<=n;++j){
			f[i][j]=min(f[i][j], f[i][k]+f[k][j]);
		}
		while (q --> 0){
			int x=0, y=0;
			Read (x, y);
			ll ans=INF;
			for (auto [v1, e1]:g[x]) for (auto [v2, e2]:g[y]){
				ans=min(ans, f[v1][v2]+e1+e2);
			}
			cout<<ans+inw[x]+inw[y]<<'\n';
		}
		return 0;
	}

}

int main(){
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	cin.tie(0)->sync_with_stdio (0);
	return akakakak::main();
}

