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

#define MAXN 1000005
#define pr pair
#define fst first
#define scd second
#define mkpr make_pair
#define all(x) (x).begin(), (x).end()

namespace akakakak{

	int c, t, n, k;
	pr <int, int> ines[MAXN];
	vector <int> g[MAXN];

	int dep[MAXN];
	pr <int, int> Getroot(int u, int fa, int ban){
		pr <int, int> res(u, 0);
		for (auto v:g[u]) if (v!=fa && v!=ban){
			dep[v]=dep[u]+1;
			// auto [a, b]=Getroot(v, u, ban);
			// if (dep[a]>dep[res.fst]){
			// 	// res={
			// }
			auto got=Getroot(v, u, ban);
			if (dep[got.fst]>dep[res.fst]) res=got;
		}
		if (dep[u]==(dep[res.fst]>>1)) res.scd=u;
		return res;
	}
	inline int Dfs(int u, int fa, int p, int ban){
		int res=0;
		dep[u]=0;
		for (auto v:g[u]) if (v!=fa && v!=ban){
			res+=Dfs(v, u, p, ban);
			dep[u]=max(dep[u], dep[v]+1);
		}
		if (dep[u]>=p) ++res;
		return res;
	}
	inline int Cost(int u, int fa, int p){
		dep[u]=0;
		u=Getroot(u, 0, fa).fst;
		dep[u]=0;
		u=Getroot(u, 0, fa).scd;
		return max(1, Dfs(u, 0, p, fa));
	}

	inline bool Check(int x){
		if (Cost(1, 0, x)<=k) return 1;
		for (int i=1;i<n;++i){
			auto [u, v]=ines[i];
			if (Cost(u, v, x)+Cost(v, u, x)<=k) return 1;
		}
		return 0;
	}

	inline int main(){
		Read (c, t);
		while (t --> 0){
			Read (n, k);
			for (int i=1;i<n;++i){
				auto &[u, v]=ines[i];
				Read (u, v);
				g[u].emplace_back (v);
				g[v].emplace_back (u);
			}
			int lef=0, rig=n-1, ans=n-1;
			while (lef<=rig){
				int mid=(lef+rig)>>1;
				if (Check(mid)){
					ans=min(ans, mid);
					rig=mid-1;
				}
				else lef=mid+1;
			}
			cout<<ans<<'\n';
			// cerr<<Check(1)<<endl;
			if (t){
				for (int i=1;i<=n;++i) g[i].clear ();
			}
		}
		return 0;
	}

}

int main(){
	freopen ("hub.in", "r", stdin);
	freopen ("hub.out", "w", stdout);
	cin.tie(0)->sync_with_stdio (0);
	return akakakak::main();
}

