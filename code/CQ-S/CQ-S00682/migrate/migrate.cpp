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
#define memcvr(a, b, c) memset ((a), (b), (c)*sizeof(*(a)))
#define MAXN 3000015
#define pr pair
#define fst first
#define scd second
#define mkpr make_pair
#define all(x) (x).begin(), (x).end()
// 
// namespace akakakak{
// 
// 	int c, t, n;
// 	ll d, inx[MAXN], ans;
// 	int rng[MAXN][2];
// 	// pr <int, int> val[MAXN][2];			// {id, cnt}
// 	// vector <pr<int, int>> res[MAXN][2];			// {id, cnt}
// 
// 	// inline int Calc(vector <pr<int, int>> &lst){
// 	// 	sort (all(lst), less<pr<int, int>>());
// 	// 	int res=0, las=0;
// 	// 	for (auto [id, cnt]:lst) if (id!=las){
// 	// 		res+=cnt;
// 	// 		las=id;
// 	// 	}
// 	// 	return res;
// 	// }
// 
// 	// vector <int> ref[MAXN][2];
// 
// 	// bool vis[MAXN];
// 	// inline ll Gor(int x){
// 	// 	if (vis[x]) return 0;
// 	// 	vis[x]=1;
// 
// 	// }
// 	// inline ll Calcr(int x){
// 	// 	for (int i=x+2;i<=n;++i) vis[i]=0;
// 	// 	ll res=0;
// 	// 	for (auto i:ref[x][1]) res+=Gor(i);
// 	// 	return res;
// 	// }
// 
// 	inline int main(){
// 		Read (c, t);
// 		while (t --> 0){
// 			Read (n, d);
// 			for (int i=1;i<=n;++i) Read (inx[i]);
// 			rng[1][0]=1;
// 			for (int i=2;i<=n;++i) for (rng[i][0]=rng[i-1][0];inx[i]-inx[rng[i][0]]>d;++rng[i][0]);
// 			rng[n][1]=n;
// 			for (int i=n-1;i;--i) for (rng[i][1]=rng[i+1][1];inx[rng[i][1]]-inx[i]>d;--rng[i][1]);
// 			for (int i=1;i<n-1;++i) if (rng[i][1]>i+1){
// 				ref[rng[i][1]][0].emplace_back (i);
// 			}
// 			for (int i=n;i>2;--i) if (rng[i][0]<i-1){
// 				ref[rng[i][0]][1].emplace_back (i);
// 			}
// 			ans=0;
// 			// for (int i=2;i<=n-2;++i){
// 			// 	ans+=Calcr(i)*Calcl(i+1);
// 			// }
// 			// for (int i=1;i<n;++i){
// 			// 	if (rng[i][0]<i && rng[i][0]<rng[i+1][0]){
// 			// 		val[i][0]={val[rng[i][0]][0].fst, val[rng[i][0]][0].scd+rng[i+1][0]-rng[i][0]};
// 			// 	}
// 			// 	else{
// 			// 		val[i][0]={i, 1};
// 			// 	}
// 			// 	cerr<<i<<" 0: "<<val[i][0].fst<<" "<<val[i][0].scd<<endl;
// 			// }
// 			// for (int i=n;i>1;--i){
// 			// 	if (rng[i][1]>i && rng[i][1]>rng[i-1][1]){
// 			// 		val[i][1]={val[rng[i][1]][1].fst, val[rng[i][1]][1].scd+rng[i][1]-rng[i-1][1]};
// 			// 	}
// 			// 	else{
// 			// 		val[i][1]={i, 1};
// 			// 	}
// 			// 	cerr<<i<<" 1: "<<val[i][1].fst<<" "<<val[i][1].scd<<endl;
// 			// }
// 			// for (int i=1;i<n-1;++i) if (rng[i][1]>i+1){
// 			// 	res[rng[i][1]][0].push_back (val[i][0]);
// 			// }
// 			// for (int i=n;i>2;--i) if (rng[i][0]<i-1){
// 			// 	res[rng[i][0]][1].push_back (val[i][1]);
// 			// }
// 			// ans=0;
// 			// for (int i=2;i<=n-2;++i) if (res[i][1].size() && res[i+1][0].size()){
// 			// 	// ans+=(ll)Calc(res[i][1])*Calc(res[i+1][0]);
// 			// 	ll rig=Calc(res[i][1]), lef=Calc(res[i+1][0]);
// 			// 	cerr<<i<<": "<<lef<<" "<<rig<<endl;
// 			// 	ans+=lef*rig;
// 			// }
// 			// cout<<ans<<'\n';
// 			// if (t) for (int i=1;i<=n;++i) for (auto t:{0, 1}) res[i][t].clear ();
// 			if (t) for (int i=1;i<=n;++i) for (auto t:{0, 1}) ref[i][t].clear ();
// 		}
// 		return 0;
// 	}
// 
// }

namespace akakakak{

	int c, t, n;
	ll d, inx[MAXN], ans;
	int rng[2][MAXN];
	// ll val[2][MAXN];
	ll val[MAXN][2], res[MAXN];

	inline int main(){
		Read (c, t);
		while (t --> 0){
			Read (n, d);
			for (int i=1;i<=n;++i) Read (inx[i]);
			// for (int i=1;i<=n;++i) cerr<<inx[i]-inx[1]<<" ";
			// cerr<<endl;
			// memcvr (val, 0, n+5);
			// rng[1]=1;
			rng[0][1]=1;
			for (int i=2;i<=n;++i){
				// for (rng[i]=rng[i-1];inx[i]-inx[rng[i]]>d;++rng[i]);
				for (rng[0][i]=rng[0][i-1];inx[i]-inx[rng[0][i]]>d;++rng[0][i]);
			}
			for (int i=1;i<n;++i){
				val[i][0]=1;
				if (rng[0][i]<i && rng[0][i]<rng[0][i+1]) val[i][0]+=val[rng[0][i]][0]+rng[0][i+1]-rng[0][i]-1;
			}
			rng[1][n]=n;
			for (int i=n-1;i;--i){
				for (rng[1][i]=rng[1][i+1];inx[rng[1][i]]-inx[i]>d;--rng[1][i]);
			}
			for (int i=n;i>1;--i){
				val[i][1]=1;
				if (rng[1][i]>i && rng[1][i]>rng[1][i-1]) val[i][1]+=val[rng[1][i]][1]+rng[1][i]-rng[1][i-1]-1;
			}
			ans=0;
			for (int i=2;i<=n-2;++i) if (i+1<rng[1][i] && rng[1][i-1]<rng[1][i]
						   && rng[0][i+1]<i && rng[0][i+1]<rng[0][i+2]){
				ll rig=val[i][1]-1;
				if (rng[1][i-1]<i+1 && i+1<=rng[1][i]) --rig;
				ll lef=val[i+1][0]-1;
				if (rng[0][i+2]>i && rng[0][i+1]<=i) --lef;
				ans+=lef*rig;
				// cerr<<i<<": "<<lef<<" "<<rig<<endl;
			}
			// for (int i=1;i<=n;++i) cerr<<i<<": "<<rng[0][i]<<" "<<rng[1][i]<<endl;
			// cerr<<"val:"<<endl;
			// for (int i=1;i<=n;++i) cerr<<i<<": "<<val[i][0]<<" "<<val[i][1]<<endl;
			cout<<ans<<'\n';
		}
		return 0;
	}

}

int main(){
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	cin.tie(0)->sync_with_stdio (0);
	return akakakak::main();
}

